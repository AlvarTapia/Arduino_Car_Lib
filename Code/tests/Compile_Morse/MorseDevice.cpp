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

const String MorseDevice::MD_EXCEPTION = "MorseDevice not initialized correctly";

MorseDevice::MorseDevice(byte devicePin){
  this->devicePin = devicePin;
}

byte MorseDevice::getDevicePin(){
  return this->devicePin;
}

String MorseDevice::startSignaling(){
  return MD_EXCEPTION;
}

String MorseDevice::stopSignaling(){
  return MD_EXCEPTION;
}


Led::Led(byte devicePin) : MorseDevice(devicePin) {};

String Led::startSignaling(){
  if (this->devicePin == INVALID_PIN){
    return MD_EXCEPTION;
  }
  digitalWrite(this->devicePin, HIGH);
  return "";
}

String Led::stopSignaling(){
  if (this->devicePin == INVALID_PIN){
    return MD_EXCEPTION;
  }
  digitalWrite(this->devicePin, LOW);
  return "";
}


Siren::Siren(byte devicePin, unsigned int sirenFrec) : MorseDevice(devicePin){
  this->sirenFrec = sirenFrec;
}

String Siren::startSignaling(){
  if (this->devicePin == INVALID_PIN){
    return MD_EXCEPTION;
  }
  tone(this->devicePin, this->sirenFrec);
  return "";
}

String Siren::stopSignaling(){
  if (this->devicePin == INVALID_PIN){
    return MD_EXCEPTION;
  }
  noTone(this->devicePin);
  return "";
}
#endif
