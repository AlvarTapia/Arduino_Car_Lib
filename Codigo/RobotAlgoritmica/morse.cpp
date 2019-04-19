#ifndef morse_cpp
#define morse_cpp

#include "morse.h"

//Constructores
Morse::Morse(byte pinMorse, char outputDevice, int sirenFrec = DEFAULT_SIREN_FREC){
      PIN_MORSE = pinMorse;
      DISPOSITIVO = outputDevice;
      SIREN_FREC = sirenFrec;
    }
    //Constructor por defecto
    Morse(){
      Morse(255, 'x');
    }

    //Destructor

    void inicializa(){
      pinMode(PIN_MORSE, OUTPUT);
    }

    void dash(){
      switch(DISPOSITIVO){
        case 's':
          tone(PIN_MORSE, SIREN_FREC);
        case 'l':
          digitalWrite(PIN_MORSE, HIGH);
      }
      delay(DASH_DELAY);
      switch(DISPOSITIVO){
        case 's':
          noTone(PIN_MORSE);
        case 'l':
          digitalWrite(PIN_MORSE, LOW);
      }
      delay(INBETWEEN_DELAY);
    }

    void point(){
      switch(DISPOSITIVO){
        case 's':
          tone(PIN_MORSE, SIREN_FREC);
        case 'l':
          digitalWrite(PIN_MORSE, HIGH);
      }
      delay(DOT_DELAY);
      switch(DISPOSITIVO){
        case 's':
          noTone(PIN_MORSE);
        case 'l':
          digitalWrite(PIN_MORSE, LOW);
      }
      delay(INBETWEEN_DELAY);
    }

    void sos(){
      this->point(); this->point(); this->point();
      delay(INBETWEEN_DELAY);
      this->dash(); this->dash(); this->dash();
      delay(INBETWEEN_DELAY);
      this->point(); this->point(); this->point();
      delay(1000);
    }
};
#endif
