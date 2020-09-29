/**
 * ----------------------------------------------------------------
 * Morse.cpp
 * Libreria que permite que la Arduino pueda enviar señales en Morse.
 * Necesita de un dispositivo que pueda cambiar notablemente de estado,
 * como un LED o una sirena.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef morse_cpp
#define morse_cpp

#include "Morse.h"

//Constructores
Morse::Morse(MorseDeviceType outputDevice) {
  device = outputDevice;
}
//Constructor por defecto
Morse::Morse(){
  Morse(noneDevice);
}
//Destructor


//Inicializador
void Morse::init() {
  pinMode(device->devicePin(), OUTPUT);
}

//Funciones
void Morse::symbol(int symbolTime) {
  device->startSignaling();
  delay(symbolTime);

  device->stopSignaling();
  delay(TIME_BETWEEN_SYMBOLS);
}

void Morse::dash() {
  this->symbol(DASH_TIME);
}

void Morse::dot() {
  this->symbol(DOT_TIME);
}

void Morse::sos() {
  this->dot(); this->dot(); this->dot();
  delay(TIME_BETWEEN_SYMBOLS);
  this->dash(); this->dash(); this->dash();
  delay(TIME_BETWEEN_SYMBOLS);
  this->dot(); this->dot(); this->dot();
  delay(1000);
}

#endif
