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

#ifndef morsedevice_cpp
#define morsedevice_cpp

#include "MorseDevice.h"


MorseDevice::MorseDevice(byte devicePin){
  this->devicePin = devicePin;
}

byte MorseDevice::getDevicePin(){
  return this->devicePin;
}

void MorseDevice::startSignaling(){
  throw MORSE_DEVICE_EXCEPTION;
}

void MorseDevice:stopSignaling(){
  throw MORSE_DEVICE_EXCEPTION;
}


void Led::startSignaling(){
  if (this->devicePin == INVALID_PIN){
    throw MORSE_DEVICE_EXCEPTION;
  }
  digitalWrite(this->devicePin, HIGH);
}

void Led::stopSignaling(){
  if (this->devicePin == INVALID_PIN){
    throw MORSE_DEVICE_EXCEPTION;
  }
  digitalWrite(this->devicePin, LOW);
}


Siren::Siren(byte devicePin, unsigned int sirenFrec){
  this->devicePin = devicePin;
  this->sirenFrec = sirenFrec;
}

void Siren::startSignaling(){
  if (this->devicePin == INVALID_PIN){
    throw MORSE_DEVICE_EXCEPTION;
  }
  tone(this->devicePin, this->sirenFrec);
}
void Siren::stopSignaling(){
  if (this->devicePin == INVALID_PIN){
    throw MORSE_DEVICE_EXCEPTION;
  }
  noTone(this->devicePin);
}
#endif
