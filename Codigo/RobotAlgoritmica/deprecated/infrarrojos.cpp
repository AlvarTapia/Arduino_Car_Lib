/**
 * ----------------------------------------------------------------
 * infrarrojos.cpp
 * Clase controlador del sensor infrarrojos.
 * Permite que la Arduino reciba señales de un mando a distancia.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef infrarrojos_cpp
#define infrarrojos_cpp

#include "infrarrojos.h"

//Constructor
Infrarrojos::Infrarrojos(byte pinInfrarrojos) {
  PIN_INFRARROJOS = pinInfrarrojos;

  irrecv = IRrecv(PIN_INFRARROJOS);
}
//Destructor


//Inicializador
void Infrarrojos::inicializa() {
  pinMode(PIN_INFRARROJOS, INPUT);
}

//Funciones
byte Infrarrojos::esperaMando() {
  decode_results results;
  unsigned long RED;
  byte aux = 0xFF;
  while (aux == 0xFF) {
    if (irrecv.decode(&results)) {
      irrecv.resume();
      RED = results.value;
      switch (RED) {
        case CERO:
          aux = 0;
          break;
        case UNO:
          aux = 1;
          break;
        case DOS:
          aux = 2;
          break;
        case TRES:
          aux = 3;
          break;
        case CUATRO:
          aux = 4;
          break;
        case CINCO:
          aux = 5;
          break;
        case SEIS:
          aux = 6;
          break;
        case SIETE:
          aux = 7;
          break;
        case OCHO:
          aux = 8;
          break;
        case NUEVE:
          aux = 9;
          break;
      }
    }
  }
  return aux;
}

#endif
