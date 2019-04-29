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
      delay(TIEMPO_CONFIRMACION);
      Serial.println("Todos activados");
      // cinta atravesada confirmada
      bit = 1;
      sigo = false;
      while(SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA) {
        //Mientras haya cinta atravesada, sigue alante
        robot.alante();
      }
    } else if (!izda && !centro && !dcha) {
      //TODO funciona raro, saltos entre sensores entran en esta categoria
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
      //Si se activa otro sensor, descartalo; ha sido un error
    }
    //Avanza normalmente a partir de ahora.
    if (centro) {
      robot.alante();
    } else if (izda) {
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
    Serial.println("Otro bucle");
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
    //Si no encuentra un cruce, como ya se introduce un 0, dejalo como esta
  }
  return x;
}

/*
 * Recorre el perimetro del nodo, y devuelve el numero de cruces que se encuentre
 * (tambien reconoce y devuelve por referencia el identificador del nodo actual).
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
 * Despues de lee_nodo_A sabemos que el robot esta detras del identificador de nodo.
 *
 * Calcula el grado del nodo (numero aristas), y lo devuelve por referencia.
 * El identificador leido en lee_nodo_A debe ser el mismo que el leido en lee_nodo_B.
 * Calcula la arista desde la que ha empezado contando desde despues de la etiqueta, con la ayuda de crucesEncontrados.
 *  (Si ha empezado lee_nodo() 2 aristas despues del identificador, entrada = 2).
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
 * y cuantos cruces debe saltarse el robot para llegar desde el final del identificador
 * al cruce por el que el robot ha empezado a investigar el nodo.
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

void Cnosos::sal(byte aristaATomar, byte grado, byte posicionInicial) {
  //Arista saltado representa los cruces que el robot se ha saltado hasta el momento.
  //Si las aristas estan identificadas en el intervalo {1..n},
  //el robot puede haberse saltado {0..n} aristas al recorrer el perimetro del nodo,
  //siendo "0" el tramo entre el identificador y la primera arista,
  //y "n" el tramo entre la ultima arista y el identificador.
  byte aristaSaltada = posicionInicial;
  
  //Mientras la arista que el robot se ha saltado no sea la arista anterior a la que se quiere tomar:
  while (aristaSaltada != aristaATomar - 1) {
    //Si la arista actual supera o iguala el grado:
    //Esta en la zona de identificadores
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

  //Si se ha salido del bucle, es que se quiere tomar el siguiente cruce.
  //El robot toma el siguiente cruce.
  if (this->siguiente() == 1){
    this->sal_aqui();
  }else{
    this->error();
  }
}

void Cnosos::sal_izq() {
  //TODO probar en vivo
  robot.rotaIzda();
  robot.alante();
  robot.rotaIzda();
  robot.para();
}

// Necesita modulo Morse inicializado para que suene/luzca
// Necesita modulo Bluetooth inicializado para mandar mensajes
void Cnosos::luce_numero(byte n) {
  for (byte i = 0; i < n; i++) {
    robot.MORSE.raya();
  }
  robot.BLUETOOTH.envia("Numero: ");
  robot.BLUETOOTH.enviaLinea(String(n));
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
