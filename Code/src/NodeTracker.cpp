/**
 * ----------------------------------------------------------------
 * NodeTracker.cpp
 * Libreria que lee, reconoce y navega grafos con robots Arduino.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef nodetracker_cpp
#define nodetracker_cpp

#include "NodeTracker.h"

#define READING_TIME_VALUE_0 5000

//Constructores
NodeTracker::NodeTracker(Robot r, byte numBits) {
  robot = r;
  BITS_OF_ID = numBits;
}
//Constructor por defecto
NodeTracker::NodeTracker(){
  NodeTracker(Robot(), 255);
}
//Destructor


//Funciones
//Doble atravesado es el nuevo hueco
byte NodeTracker::nextBit() {
  byte bit;
  bool keepGoing = true;
  bool left, right;
  int i;
  //Avanza hasta encontrar una cinta atravesada
  while (keepGoing) {
    robot.alante();
    //centro = CENTRE_SENSOR;
    if(LEFT_SENSOR || RIGHT_SENSOR){
      delay(50);
      left = LEFT_SENSOR;
      right = RIGHT_SENSOR;
      if(left && right){
        bit = 1;
        keepGoing = false;

        i = 0;
        while(LEFT_SENSOR && CENTRE_SENSOR && RIGHT_SENSOR){
          i++;
        }
        //Si se ha pasado el limite,
        //entonces esta cinta atravesada vale 0
        if(i>READING_TIME_VALUE_0){
          bit = 0;
        }
      }else if(left && !right){
        robot.leftRotation();
      }else if(!left && right){
        robot.rightRotation();
      }
    }
    while(!CENTRE_SENSOR);
  }
  robot.stop();
  Serial.println("Bit read");
  delay(THINKING_TIME);
  return bit;
}


byte NodeTracker::readNumber() {
  byte x = 0;
  for (byte i = 0; i < BITS_OF_ID; i++) {
    //Desplaza el numero a la izquierda.
    //Si x = 0, despues de la operacion x = 0
    //Si x = 0b1, despues de la operacion x = 0b10
    x = x << 1;
    //Si encuentra un cruce, suma 1 a x
    if(nextBit() == 1){
      x++;
    }
    //Si no encuentra un cruce, como ya se introduce un 0
    //al desplazar el numero, dejalo como esta
  }
  return x;
}

/*
 * lee_nodo_A()
 * Recorre el perimetro del nodo,
 * y devuelve el numero de cruces que se encuentre
 * (tambien reconoce y devuelve por referencia
 * el identificador del nodo actual).
 * Este metodo no sabe desde que parte del nodo empieza, por lo que
 * crossroadsFound es menor o igual que el degree.
 */
byte recon_trip(NodeTracker* nt, byte &id) {
  byte crossroadsFound = 0;  // caminos contados desde la entrance
  //Mientras nextBit() encuentre cintas cruzadas
  while (nt->nextBit() == 1){
    crossroadsFound++;
  }

  //Cuando nextBit() encuentre un hueco en la cinta
  //Empieza a leer el identificador
  id = nt->readNumber();

  //Devuelve los cruces que haya encontrado
  return crossroadsFound;
}

/*
 * lee_nodo_b()
 * Despues de recon_trip sabemos que el robot
 * esta detras del identificador de nodo.
 *
 * Calcula el degree del nodo (numero aristas),
 * y lo devuelve por referencia.
 * El identificador leido en recon_trip debe ser el mismo
 * que el leido en degreeOfNode.
 * Calcula la arista desde la que ha empezado contando
 * desde despues de la labelueta, con la ayuda de crossroadsFound.
 *   (Si ha empezado readNode() 2 aristas despues del identificador,
 *    entrance = 2).
 */
void degreeOfNode(NodeTracker* nt, byte crossroadsFound, byte id,
                byte &degree, byte &entrance) {
  //Calcula el degree del nodo
  degree = 0;
  while (nt->nextBit() == 1){
    degree++;
  }

  // Calcula el cruce por el que ha entrado el robot
  entrance = degree - crossroadsFound + 1;

  //Si el id leido es distinto del recibido por argumentos
  if (id != nt->readNumber()){
    //Salta error
    nt->error();
  }
}

/*
 * Despues de dos vueltas al nodo, devuelve por referencia
 * el identificador del nodo, el degree del nodo,
 * y cuantos cruces debe saltarse el robot
 * para llegar desde el final del identificador al cruce
 * por el que el robot ha empezado a investigar el nodo.
 */
void NodeTracker::readNode(byte &label, byte &degree, byte &entrance) {
  byte crossroadsFound = recon_trip(this, label);
  degreeOfNode(this, crossroadsFound, label, degree, entrance);
}

/*
 * Dos giros a la izquierda.
 */
void NodeTracker::takeThisTurn() {
  this->takeLeft();
  if (this->nextBit() == 1){
    this->takeLeft();
  }else{
    this->error();
  }
}

void NodeTracker::takeExit( byte edgesToTurn,
                  byte degree,
                  byte initialPos) {
  /*
   * Arista saltado representa los cruces que el robot
   * se ha saltado hasta el momento.
   * Si las aristas estan identificadas en el intervalo {1..n},
   * el robot puede haberse saltado {0..n} aristas
   * al recorrer el perimetro del nodo,
   * siendo "0" el tramo entre el identificador y la primera arista,
   * y "n" el tramo entre la ultima arista y el identificador.
   */
  byte disregardedEdge = initialPos;

  /*
   * Mientras la arista que el robot se ha saltado
   * no sea la arista anterior a la que se quiere tomar:
   */
  while (disregardedEdge != edgesToTurn - 1) {
    /*
     * Si la arista actual supera o iguala el degree:
     * Esta en la zona de identificadores
     */
    if (disregardedEdge >= degree) {
      //Si no encuentra el identificador, error
      if (this->nextBit() == 1) {
        error();
      }
      //Descarta el identificador, no lo necesitamos ahora
      readNumber();
      //La arista actual es 0 (no nos hemos saltado ninguna)
      disregardedEdge = 0;
    }else{
      //El robot no esta en zona de identificadores
      //Si encuentra un identificador, error
      if (this->nextBit() == 0){
       this->error();
      }
      //El robot acaba de saltarse un cruce
      //La arista saltada aumenta en 1
      disregardedEdge++;
    }
  }

  /*
   * Si se ha salido del bucle,
   * es que se quiere tomar el siguiente cruce.
   * El robot toma el siguiente cruce.
   */
  if (this->nextBit() == 1){
    this->takeThisTurn();
  }else{
    this->error();
  }
}

//Es necesario que esta funcion este en la interfaz?
void NodeTracker::takeLeft() {
  robot.leftRotation();
  while(!LEFT_SENSOR){};
  while(!CENTRE_SENSOR){};
}

// Necesita modulo Morse inicializado para que suene/luzca
// Necesita modulo Bluetooth inicializado para mandar mensajes
void NodeTracker::showNumber(byte n) {
  robot.BLUETOOTH.send("Number: ");
  robot.BLUETOOTH.sendNewLine(String(n));

  for (byte i = 0; i < n; i++) {
    robot.MORSE.dash();
  }
}

// Necesita modulo Morse inicializado para que suene/luzca
// Necesita modulo Bluetooth inicializado para mandar mensajes
void NodeTracker::error() {
  robot.stop();
  while (true){
    robot.BLUETOOTH.sendNewLine("¡ERROR!");
    robot.MORSE.sos();
  }
}

#endif

/* DEPRECATED
//Traducido directamente
byte NodeTracker::nextBit(){
  robot.alante();
  bool bit;
  bool keepGoing = true;
  byte left, centro, right;
  while (keepGoing) {
    left = LEFT_SENSOR;
    centro = CENTRE_SENSOR;
    right = RIGHT_SENSOR;
    if (left && centro && right) {
      // cinta atravesada
      bit = true;
      keepGoing = false;
      while (LEFT_SENSOR && CENTRE_SENSOR && RIGHT_SENSOR);
    }else if (!(left || centro || right)) {
      //Salta el hueco
      while(!(LEFT_SENSOR || CENTRE_SENSOR || RIGHT_SENSOR)) {};
      if (!LEFT_SENSOR && CENTRE_SENSOR && !RIGHT_SENSOR){
        // hueco
        bit = false;
        keepGoing = false;
      }
    }else if (left ^ right) {
      if (LEFT_SENSOR) {
        robot.leftRotation();
        while (LEFT_SENSOR && !RIGHT_SENSOR) {};
      } else if (RIGHT_SENSOR) {
        robot.rightRotation();
        while (RIGHT_SENSOR && !LEFT_SENSOR) {};
      }
      robot.alante();
    }
  }

  // Bit sobrepasado. Enderezamos si es preciso.
  while (LEFT_SENSOR || RIGHT_SENSOR) {
    if (LEFT_SENSOR) {
      robot.leftRotation();
      while (LEFT_SENSOR);
    } else if (RIGHT_SENSOR) {
      robot.rightRotation();
      while (RIGHT_SENSOR);
    }
  }

  robot.stop();
  delay(THINKING_TIME);

  return bit;
}
*/
/*
//Interpretacion Tapia
byte NodeTracker::nextBit() {
  robot.alante();
  byte bit;
  bool keepGoing = true;
  bool left, centro, right;
  //Avanza hasta encontrar un hueco o una cinta atravesada
  while (keepGoing) {
    left = LEFT_SENSOR;
    centro = CENTRE_SENSOR;
    right = RIGHT_SENSOR;
    if (left && centro && right) {
      //Se confirma que es una cinta atravesada
      Serial.println("Todos activados");
      // cinta atravesada confirmada
      bit = 1;
      keepGoing = false;
      //Mientras haya cinta atravesada, sigue alante para evitarla
      while(LEFT_SENSOR && CENTRE_SENSOR && RIGHT_SENSOR) {
        robot.alante();
      }
      //Si al final del cruce se encuentra con un hueco,
      //rota a la right para evitarlo
      while(!LEFT_SENSOR && !CENTRE_SENSOR && !RIGHT_SENSOR) {
        robot.rightRotation();
      }
      //Una vez el robot centrado, se continua normalmente
    } else if (!left && !centro && !right) {
      //TODO funciona raro,
      //huecos entre sensores entran en esta categoria
      Serial.println("Ninguno activado");
      while(!LEFT_SENSOR && !CENTRE_SENSOR && !RIGHT_SENSOR) {
        //Mientras haya hueco, sigue alante
        robot.alante();
      }
      //Si solo se activa el sensor del centro
      if (!LEFT_SENSOR && CENTRE_SENSOR && !RIGHT_SENSOR) {
        // hueco confirmado
        bit = 0;
        keepGoing = false;
      }
      //Si se activa otra combinacion de sensores, descartalo;
      //ha sido un error
    }
    //Avanza normalmente a partir de ahora.
    if (left) {
      robot.leftRotation();
      Serial.println("Girando left");
      //Espera a que se limpie el sensor izquierdo
      while(LEFT_SENSOR){ }
      //Mientras haya un hueco, ignoralo
      while(!LEFT_SENSOR && !CENTRE_SENSOR && !RIGHT_SENSOR){ };
    } else if (right) {
      robot.rightRotation();
      Serial.println("Girando right");
      //Espera a que se limpie el sensor derecho
      while(RIGHT_SENSOR){ }
      //Mientras haya un hueco, ignoralo
      while(!LEFT_SENSOR && !CENTRE_SENSOR && !RIGHT_SENSOR){ };
    }
    robot.alante();
    Serial.println("Otro bucle");
  }
  robot.stop();
  Serial.println("Bit read");
  delay(THINKING_TIME);
  return bit;
}
*/
