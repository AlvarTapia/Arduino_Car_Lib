/**
 * ----------------------------------------------------------------
 * MorseDevice.cpp
 * Libreria que permite que la Arduino pueda enviar señales en Morse.
 * Necesita de un dispositivo que pueda cambiar notablemente de estado,
 * como un LED o una sirena.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef morsedevicetype_cpp
#define morsedevicetype_cpp

#include "MorseDevice.h"


MorseDevice::MorseDevice(byte devicePin){
  devicePin = devicePin;
}

byte MorseDevice::getDevicePin(){
  return devicePin;
}


void Led::startSignaling(){
  digitalWrite(this->devicePin, HIGH);
}

void Led::stopSignaling(){
  digitalWrite(this->devicePin, LOW);
}


Siren::Siren(byte devicePin, unsigned int sirenFrec){
  this->devicePin = devicePin;
  this->sirenFrec = sirenFrec;
}

void Siren::startSignaling(){
  tone(this->devicePin, this->sirenFrec);
}
void Siren::stopSignaling(){
  noTone(this->devicePin);
}
#endif
