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
Morse::Morse(byte pinMorse, char outputDevice, unsigned int sirenFrec) {
  morsePin = pinMorse;
  device = outputDevice;
  sirenFrec = sirenFrec;
}
//Constructor por defecto
Morse::Morse(){
  morsePin = INVALID_PIN;
  device = 'x';
  sirenFrec = DEFAULT_SIREN_FREC;
}
//Destructor


//Inicializador
void Morse::init() {
  pinMode(morsePin, OUTPUT);
}

//Funciones
void Morse::dash() {
  switch (device) {
    case 's':
      tone(morsePin, sirenFrec);
    case 'l':
      digitalWrite(morsePin, HIGH);
  }
  delay(DASH_TIME);
  switch (device) {
    case 's':
      noTone(morsePin);
    case 'l':
      digitalWrite(morsePin, LOW);
  }
  delay(TIME_BETWEEN_SYMBOLS);
}

void Morse::dot() {
  switch (device) {
    case 's':
      tone(morsePin, sirenFrec);
    case 'l':
      digitalWrite(morsePin, HIGH);
  }
  delay(DOT_TIME);
  switch (device) {
    case 's':
      noTone(morsePin);
    case 'l':
      digitalWrite(morsePin, LOW);
  }
  delay(TIME_BETWEEN_SYMBOLS);
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
