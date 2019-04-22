
#ifndef morse_cpp
#define morse_cpp

#include "morse.h"

//Constructor
Morse::Morse(byte pinMorse, char outputDevice, int sirenFrec) {
  PIN_MORSE = pinMorse;
  DISPOSITIVO = outputDevice;
  FREC_SIRENA = sirenFrec;
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
