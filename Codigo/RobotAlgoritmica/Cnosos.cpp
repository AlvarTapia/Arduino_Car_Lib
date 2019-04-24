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

//Constructor
Cnosos::Cnosos(Robot r, byte bits) {
  robot = r;
  BITS = bits;
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
      Serial.println("Todos activados");
      if (SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA) {
        // cinta atravesada confirmada
        bit = 1;
        sigo = false;
      }
    } else if (!izda && !centro && !dcha) {
      Serial.println("Ninguno activado");
      if (!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA) {
        // hueco confirmado
        bit = 0;
        sigo = false;
      }
    }
    //No hay ni hueco ni cinta atravesada todavia. Avanza normalmente.
    else if (centro) {
      robot.alante();
    } else if (izda) {
      robot.rotaIzda();
    } else if (dcha) {
      robot.rotaDcha();
    }
  }

  // Bit identificado. Avanzamos hasta dejarlo atras.
  robot.alante();
  if (bit) {
    while (SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA);
  } else {
    while (!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA);
  }

  /*
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
  */
  robot.para();
  Serial.println("Bit leido");
  delay(TIEMPO_PENSAR);
  return bit;
}

byte Cnosos::lee_numero() {
  byte x = 0;
  for (byte i = 0; i < BITS; i++) {
    x = x << 1;
    if(siguiente() == 1){
      x++;
    }
  }
  return x;
}

/*
 * Recorre el perimetro del nodo, y devuelve el numero de cruces que se encuentre
 * (tambien reconoce y devuelve por referencia el identificador del nodo actual).
 * Este metodo no sabe desde que parte del nodo empieza, por lo que
 * crucesEncontrados es menor o igual que el grado.
 */
byte lee_nodo_A(Cnosos* cn, byte &etiq) {
  byte crucesEncontrados = 0;  // caminos contados desde la entrada
  while (cn->siguiente()){
    crucesEncontrados++;
  }

  etiq = cn->lee_numero();

  return crucesEncontrados;
}

/*
 * Despues de lee_nodo_A sabemos que estamos detras del identificador de nodo.
 *
 * Calcula el grado del nodo (numero aristas), y lo devuelve por referencia.
 * Calcula la arista desde la que ha empezado contando desde despues de la etiqueta
 *  (Si ha empezado lee_nodo() 2 aristas despues del identificador, entrada = 2).
 * El identificador leido en lee_nodo_A debe ser el mismo que el leido en lee_nodo_B.
 */
void lee_nodo_B(Cnosos* cn, byte crucesEncontrados, byte &grado, byte &entrada,
                        byte etiq) {
  grado = 0;
  while (cn->siguiente()){
    grado++;
  }

  entrada = grado - crucesEncontrados + 1;

  if (etiq != cn->lee_numero()){
    cn->error();
  }
}

/*
 * Despues de dos vueltas al nodo, devuelve por referencia
 * el identificador del nodo, el grado del nodo,
 * y cuantos cruces debe saltarse para llegar desde el final del identificador
 * al cruce por el que ha empezado a investigar el nodo.
 */
void Cnosos::lee_nodo(byte &etiq, byte &grado, byte &entrada) {
  byte aux = lee_nodo_A(this, etiq);
  lee_nodo_B(this, aux, grado, entrada, etiq);
}

/*
 *
 */
void Cnosos::sal_aqui() {
  sal_izq();
  if (this->siguiente()){
    sal_izq();
  }
  else error();
}

void Cnosos::sal(byte i, byte grado, byte pos) {
  while (pos != i) {
    pos++;
    if (pos == grado + 1) {
      if (this->siguiente()) error();
      lee_numero();
      pos = 1;
    }
    if (!this->siguiente()) error();
  }
  sal_aqui();
}

void Cnosos::sal_izq() {
  //TODO
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
  robot.BLUETOOTH.enviaLinea("¡ERROR!");
  while (true){
    robot.MORSE.sos();
  }
}

#endif
