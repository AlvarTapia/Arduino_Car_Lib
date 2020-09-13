/**
 * ----------------------------------------------------------------
 * morse.cpp
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

#include "morse.h"

//Constructores
Morse::Morse(byte pinMorse, char outputDevice, unsigned int sirenFrec) {
  PIN_MORSE = pinMorse;
  DISPOSITIVO = outputDevice;
  FREC_SIRENA = sirenFrec;
}
//Constructor por defecto
Morse::Morse(){
  PIN_MORSE = 255;
  DISPOSITIVO = 'x';
  FREC_SIRENA = DEFAULT_FREC_SIRENA;
}
//Destructor


//Inicializador
void Morse::inicializa() {
  pinMode(PIN_MORSE, OUTPUT);
}

//Funciones
void Morse::raya() {
  switch (DISPOSITIVO) {
    case 's':
      tone(PIN_MORSE, FREC_SIRENA);
    case 'l':
      digitalWrite(PIN_MORSE, HIGH);
  }
  delay(TIEMPO_RAYA);
  switch (DISPOSITIVO) {
    case 's':
      noTone(PIN_MORSE);
    case 'l':
      digitalWrite(PIN_MORSE, LOW);
  }
  delay(TIEMPO_ENTRE_SIMBOLOS);
}

void Morse::punto() {
  switch (DISPOSITIVO) {
    case 's':
      tone(PIN_MORSE, FREC_SIRENA);
    case 'l':
      digitalWrite(PIN_MORSE, HIGH);
  }
  delay(TIEMPO_PUNTO);
  switch (DISPOSITIVO) {
    case 's':
      noTone(PIN_MORSE);
    case 'l':
      digitalWrite(PIN_MORSE, LOW);
  }
  delay(TIEMPO_ENTRE_SIMBOLOS);
}

void Morse::sos() {
  this->punto(); this->punto(); this->punto();
  delay(TIEMPO_ENTRE_SIMBOLOS);
  this->raya(); this->raya(); this->raya();
  delay(TIEMPO_ENTRE_SIMBOLOS);
  this->punto(); this->punto(); this->punto();
  delay(1000);
}

#endif
