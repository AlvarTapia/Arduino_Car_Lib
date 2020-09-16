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
void Infrared::inicializa() {
  pinMode(INFRARED_PIN, INPUT);
}

//Funciones
byte Infrared::esperaMando() {
  decode_results results;
  unsigned long RED;
  byte aux = 0xFF;
  while (aux == 0xFF) {
    if (irrecv.decode(&results)) {
      irrecv.resume();
      RED = results.value;
      
  }
  return aux;
}

#endif
