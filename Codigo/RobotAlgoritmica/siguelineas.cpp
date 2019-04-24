/**
 * ----------------------------------------------------------------
 * TODO.h
 * TODO
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef siguelineas_cpp
#define siguelineas_cpp

#include "siguelineas.h"

//Constructor
Siguelineas::Siguelineas(byte izda, byte centro, byte dcha) {
  PIN_SIGUELINEAS_IZDA = izda;
  PIN_SIGUELINEAS_CENTRO = centro;
  PIN_SIGUELINEAS_DCHA = dcha;
}
//Destructor


void Siguelineas::inicializa() {
  pinMode(PIN_SIGUELINEAS_IZDA, INPUT);
  pinMode(PIN_SIGUELINEAS_CENTRO, INPUT);
  pinMode(PIN_SIGUELINEAS_DCHA, INPUT);
}


//Reads
/** Devuelve true si hay una linea debajo del sensor izquierdo */
bool Siguelineas::readIzda() {
  if (PIN_SIGUELINEAS_IZDA == 255) { //Error
    return false;
  } else {
    return digitalRead(PIN_SIGUELINEAS_IZDA);
  }
}

/** Devuelve true si hay una linea debajo del sensor central */
bool Siguelineas::readCentro() {
  if (PIN_SIGUELINEAS_CENTRO == 255) { //Error
    return false;
  } else {
    return digitalRead(PIN_SIGUELINEAS_CENTRO);
  }
}

/** Devuelve true si hay una linea debajo del sensor derecho */
bool Siguelineas::readDcha() {
  if (PIN_SIGUELINEAS_DCHA == 255) { //Error
    return false;
  } else {
    return digitalRead(PIN_SIGUELINEAS_DCHA);
  }
}

#endif
