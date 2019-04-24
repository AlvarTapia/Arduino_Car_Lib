/**
 * ----------------------------------------------------------------
 * siguelineas.cpp
 * Clase que permite utilizar los sensores siguelineas.
 * Se espera que se usen tres sensores por objeto.
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


//Inicializador
void Siguelineas::inicializa() {
  pinMode(PIN_SIGUELINEAS_IZDA, INPUT);
  pinMode(PIN_SIGUELINEAS_CENTRO, INPUT);
  pinMode(PIN_SIGUELINEAS_DCHA, INPUT);
}

//Funciones
bool Siguelineas::readIzda() {
  if (PIN_SIGUELINEAS_IZDA == 255) { //Error
    return false;
  } else {
    return digitalRead(PIN_SIGUELINEAS_IZDA);
  }
}

bool Siguelineas::readCentro() {
  if (PIN_SIGUELINEAS_CENTRO == 255) { //Error
    return false;
  } else {
    return digitalRead(PIN_SIGUELINEAS_CENTRO);
  }
}

bool Siguelineas::readDcha() {
  if (PIN_SIGUELINEAS_DCHA == 255) { //Error
    return false;
  } else {
    return digitalRead(PIN_SIGUELINEAS_DCHA);
  }
}

#endif
