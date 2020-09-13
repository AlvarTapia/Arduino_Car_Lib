/**
 * ----------------------------------------------------------------
 * Cnosos.cpp
 * Libreria que lee, reconoce y navega grafos con robots Arduino.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef cnosos_cpp
#define cnosos_cpp

#include "Cnosos.h"

#define TIEMPO_PARA_LEER_0 5000

//Constructores
Cnosos::Cnosos(Robot r, byte bits) {
  robot = r;
  BITS = bits;
}
//Constructor por defecto
Cnosos::Cnosos(){
  Cnosos(Robot(), 255);
}
//Destructor


//Funciones
/*
//Traducido directamente
byte Cnosos::siguiente(){
  robot.alante();
  bool bit;
  bool sigo = true;
  byte izda, centro, dcha;
  while (sigo) {
    izda = SENSOR_IZDA;
    centro = SENSOR_CENTRO;
    dcha = SENSOR_DCHA;
    if (izda && centro && dcha) {
      // cinta atravesada
      bit = true;
      sigo = false;
      while (SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA);
    }else if (!(izda || centro || dcha)) {
      //Salta el hueco
      while(!(SENSOR_IZDA || SENSOR_CENTRO || SENSOR_DCHA)) {};
      if (!SENSOR_IZDA && SENSOR_CENTRO && !SENSOR_DCHA){
        // hueco
        bit = false;
        sigo = false;
      }
    }else if (izda ^ dcha) {
      if (SENSOR_IZDA) {
        robot.rotaIzda();
        while (SENSOR_IZDA && !SENSOR_DCHA) {};
      } else if (SENSOR_DCHA) {
        robot.rotaDcha();
        while (SENSOR_DCHA && !SENSOR_IZDA) {};
      }
      robot.alante();
    }
  }

  // Bit sobrepasado. Enderezamos si es preciso.
  while (SENSOR_IZDA || SENSOR_DCHA) {
    if (SENSOR_IZDA) {
      robot.rotaIzda();
      while (SENSOR_IZDA);
    } else if (SENSOR_DCHA) {
      robot.rotaDcha();
      while (SENSOR_DCHA);
    }
  }

  robot.para();
  delay(TIEMPO_PENSAR);

  return bit;
}
*/
/*
//Interpretacion Tapia
byte Cnosos::siguiente() {
  robot.alante();
  byte bit;
  bool sigo = true;
  bool izda, centro, dcha;
  //Avanza hasta encontrar un hueco o una cinta atravesada
  while (sigo) {
    izda = SENSOR_IZDA;
    centro = SENSOR_CENTRO;
    dcha = SENSOR_DCHA;
    if (izda && centro && dcha) {
      //Se confirma que es una cinta atravesada
      Serial.println("Todos activados");
      // cinta atravesada confirmada
      bit = 1;
      sigo = false;
      //Mientras haya cinta atravesada, sigue alante para evitarla
      while(SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA) {
        robot.alante();
      }
      //Si al final del cruce se encuentra con un hueco,
      //rota a la dcha para evitarlo
      while(!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA) {
        robot.rotaDcha();
      }
      //Una vez el robot centrado, se continua normalmente
    } else if (!izda && !centro && !dcha) {
      //TODO funciona raro,
      //huecos entre sensores entran en esta categoria
      Serial.println("Ninguno activado");
      while(!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA) {
        //Mientras haya hueco, sigue alante
        robot.alante();
      }
      //Si solo se activa el sensor del centro
      if (!SENSOR_IZDA && SENSOR_CENTRO && !SENSOR_DCHA) {
        // hueco confirmado
        bit = 0;
        sigo = false;
      }
      //Si se activa otra combinacion de sensores, descartalo;
      //ha sido un error
    }
    //Avanza normalmente a partir de ahora.
    if (izda) {
      robot.rotaIzda();
      Serial.println("Girando izda");
      //Espera a que se limpie el sensor izquierdo
      while(SENSOR_IZDA){ }
      //Mientras haya un hueco, ignoralo
      while(!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA){ };
    } else if (dcha) {
      robot.rotaDcha();
      Serial.println("Girando dcha");
      //Espera a que se limpie el sensor derecho
      while(SENSOR_DCHA){ }
      //Mientras haya un hueco, ignoralo
      while(!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA){ };
    }
    robot.alante();
    Serial.println("Otro bucle");
  }
  robot.para();
  Serial.println("Bit leido");
  delay(TIEMPO_PENSAR);
  return bit;
}
*/

//Doble atravesado es el nuevo hueco
byte Cnosos::siguiente() {
  byte bit;
  bool sigo = true;
  bool izda, dcha;
  int i;
  //Avanza hasta encontrar una cinta atravesada
  while (sigo) {
    robot.alante();
    //centro = SENSOR_CENTRO;
    if(SENSOR_IZDA || SENSOR_DCHA){
      delay(50);
      izda = SENSOR_IZDA;
      dcha = SENSOR_DCHA;
      if(izda && dcha){
        bit = 1;
        sigo = false;

        i = 0;
        while(SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA){
          i++;
        }
        //Si se ha pasado el limite,
        //entonces esta cinta atravesada vale 0
        if(i>TIEMPO_PARA_LEER_0){
          bit = 0;
        }
      }else if(izda && !dcha){
        robot.rotaIzda();
      }else if(!izda && dcha){
        robot.rotaDcha();
      }
    }
    while(!SENSOR_CENTRO);
  }
  robot.para();
  Serial.println("Bit leido");
  delay(TIEMPO_PENSAR);
  return bit;
}


byte Cnosos::lee_numero() {
  byte x = 0;
  for (byte i = 0; i < BITS; i++) {
    //Desplaza el numero a la izquierda.
    //Si x = 0, despues de la operacion x = 0
    //Si x = 0b1, despues de la operacion x = 0b10
    x = x << 1;
    //Si encuentra un cruce, suma 1 a x
    if(siguiente() == 1){
      x++;
    }
    //Si no encuentra un cruce, como ya se introduce un 0
    //al desplazar el numero, dejalo como esta
  }
  return x;
}

/*
 * Recorre el perimetro del nodo,
 * y devuelve el numero de cruces que se encuentre
 * (tambien reconoce y devuelve por referencia
 * el identificador del nodo actual).
 * Este metodo no sabe desde que parte del nodo empieza, por lo que
 * crucesEncontrados es menor o igual que el grado.
 */
byte lee_nodo_A(Cnosos* cn, byte &id) {
  byte crucesEncontrados = 0;  // caminos contados desde la entrada
  //Mientras siguiente() encuentre cintas cruzadas
  while (cn->siguiente() == 1){
    crucesEncontrados++;
  }

  //Cuando siguiente() encuentre un hueco en la cinta
  //Empieza a leer el identificador
  id = cn->lee_numero();

  //Devuelve los cruces que haya encontrado
  return crucesEncontrados;
}

/*
 * Despues de lee_nodo_A sabemos que el robot
 * esta detras del identificador de nodo.
 *
 * Calcula el grado del nodo (numero aristas),
 * y lo devuelve por referencia.
 * El identificador leido en lee_nodo_A debe ser el mismo
 * que el leido en lee_nodo_B.
 * Calcula la arista desde la que ha empezado contando
 * desde despues de la etiqueta, con la ayuda de crucesEncontrados.
 *   (Si ha empezado lee_nodo() 2 aristas despues del identificador,
 *    entrada = 2).
 */
void lee_nodo_B(Cnosos* cn, byte crucesEncontrados, byte id,
                byte &grado, byte &entrada) {
  //Calcula el grado del nodo
  grado = 0;
  while (cn->siguiente() == 1){
    grado++;
  }

  // Calcula el cruce por el que ha entrado el robot
  entrada = grado - crucesEncontrados + 1;

  //Si el id leido es distinto del recibido por argumentos
  if (id != cn->lee_numero()){
    //Salta error
    cn->error();
  }
}

/*
 * Despues de dos vueltas al nodo, devuelve por referencia
 * el identificador del nodo, el grado del nodo,
 * y cuantos cruces debe saltarse el robot
 * para llegar desde el final del identificador al cruce
 * por el que el robot ha empezado a investigar el nodo.
 */
void Cnosos::lee_nodo(byte &etiq, byte &grado, byte &entrada) {
  byte crucesEncontrados = lee_nodo_A(this, etiq);
  lee_nodo_B(this, crucesEncontrados, etiq, grado, entrada);
}

/*
 * Dos giros a la izquierda.
 */
void Cnosos::sal_aqui() {
  this->sal_izq();
  if (this->siguiente() == 1){
    this->sal_izq();
  }else{
    this->error();
  }
}

void Cnosos::sal( byte aristaATomar,
                  byte grado,
                  byte posicionInicial) {
  /*
   * Arista saltado representa los cruces que el robot
   * se ha saltado hasta el momento.
   * Si las aristas estan identificadas en el intervalo {1..n},
   * el robot puede haberse saltado {0..n} aristas
   * al recorrer el perimetro del nodo,
   * siendo "0" el tramo entre el identificador y la primera arista,
   * y "n" el tramo entre la ultima arista y el identificador.
   */
  byte aristaSaltada = posicionInicial;

  /*
   * Mientras la arista que el robot se ha saltado
   * no sea la arista anterior a la que se quiere tomar:
   */
  while (aristaSaltada != aristaATomar - 1) {
    /*
     * Si la arista actual supera o iguala el grado:
     * Esta en la zona de identificadores
     */
    if (aristaSaltada >= grado) {
      //Si no encuentra el identificador, error
      if (this->siguiente() == 1) {
        error();
      }
      //Descarta el identificador, no lo necesitamos ahora
      lee_numero();
      //La arista actual es 0 (no nos hemos saltado ninguna)
      aristaSaltada = 0;
    }else{
      //El robot no esta en zona de identificadores
      //Si encuentra un identificador, error
      if (this->siguiente() == 0){
       this->error();
      }
      //El robot acaba de saltarse un cruce
      //La arista saltada aumenta en 1
      aristaSaltada++;
    }
  }

  /*
   * Si se ha salido del bucle,
   * es que se quiere tomar el siguiente cruce.
   * El robot toma el siguiente cruce.
   */
  if (this->siguiente() == 1){
    this->sal_aqui();
  }else{
    this->error();
  }
}

//Es necesario que esta funcion este en la interfaz?
void Cnosos::sal_izq() {
  robot.rotaIzda();
  while(!SENSOR_IZDA){};
  while(!SENSOR_CENTRO){};
}

// Necesita modulo Morse inicializado para que suene/luzca
// Necesita modulo Bluetooth inicializado para mandar mensajes
void Cnosos::luce_numero(byte n) {
  robot.BLUETOOTH.envia("Numero: ");
  robot.BLUETOOTH.enviaLinea(String(n));

  for (byte i = 0; i < n; i++) {
    robot.MORSE.raya();
  }
}

// Necesita modulo Morse inicializado para que suene/luzca
// Necesita modulo Bluetooth inicializado para mandar mensajes
void Cnosos::error() {
  robot.para();
  while (true){
    robot.BLUETOOTH.enviaLinea("¡ERROR!");
    robot.MORSE.sos();
  }
}

#endif
