/**
 * ----------------------------------------------------------------
 * infrared.cpp
 * Clase controlador del sensor infrarrojos.
 * Permite que la Arduino reciba señales de un mando a distancia.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef infrared_cpp
#define infrared_cpp

#include "infrared.h"

//Constructor
Infrared::Infrared(byte infraredPin) {
  INFRARED_PIN = infraredPin;

  irrecv = IRrecv(INFRARED_PIN);
}
//Destructor


//Inicializador
void Infrared::init() {
  pinMode(INFRARED_PIN, INPUT);
}

//Funciones
byte Infrared::waitForRedSignal() {
  decode_results results;
  unsigned long redCode;
  byte aux = NO_RED_READ;
  while (aux == NO_RED_READ) {
    if (irrecv.decode(&results)) {
      irrecv.resume();
      redCode = results.value;
      aux = redToDigit(redCode);
    }
  }
  return aux;
}

#endif
