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
Morse::Morse(byte pinMorse, MorseDeviceType outputDevice, unsigned int sirenFrec) {
  morsePin = pinMorse;
  device = outputDevice;
  sirenFrec = sirenFrec;
}
//Constructor por defecto
Morse::Morse(){
  Morse(INVALID_PIN, MorseDeviceType::NONE, DEFAULT_SIREN_FREC);
}
//Destructor


//Inicializador
void Morse::init() {
  pinMode(morsePin, OUTPUT);
}

//Funciones
void Morse::symbol(int symbolTime) {
  switch (device) {
    case MorseDeviceType::SIREN:
      tone(morsePin, sirenFrec);
    case MorseDeviceType::LED:
      digitalWrite(morsePin, HIGH);
  }

  delay(symbolTime);

  switch (device) {
    case MorseDeviceType::SIREN:
      noTone(morsePin);
    case MorseDeviceType::LED:
      digitalWrite(morsePin, LOW);
  }
  
  delay(TIME_BETWEEN_SYMBOLS);
}

void Morse::dash() {
  symbol(DASH_TIME);
}

void Morse::dot() {
  symbol(DOT_TIME);
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
