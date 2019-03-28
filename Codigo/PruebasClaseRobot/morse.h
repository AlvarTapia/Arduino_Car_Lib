#ifndef morse_h
#define morse_h

#include "Arduino.h"

class Morse{
  private:
    byte PIN_MORSE;
    char OUTPUT_DEVICE;
    unsigned int SIREN_FREC = 15000;

    static int const DASH_DELAY = 300;
    static int const DOT_DELAY = 100;
    static int const INBETWEEN_DELAY = 100;
  public:
    Morse(){  }
    Morse(byte pinMorse, char outputDevice){
      PIN_MORSE = pinMorse;

      pinMode(PIN_MORSE, OUTPUT);
      OUTPUT_DEVICE = outputDevice;
    }

    void dash(){
      switch(OUTPUT_DEVICE){
        case 's':
          tone(PIN_MORSE, SIREN_FREC);
        case 'l':
          digitalWrite(PIN_MORSE, HIGH);
      }
      delay(DASH_DELAY);
      switch(OUTPUT_DEVICE){
        case 's':
          noTone(PIN_MORSE);
        case 'l':
          digitalWrite(PIN_MORSE, LOW);
      }
      delay(INBETWEEN_DELAY);
    }

    void point(){
      switch(OUTPUT_DEVICE){
        case 's':
          tone(PIN_MORSE, SIREN_FREC);
        case 'l':
          digitalWrite(PIN_MORSE, HIGH);
      }
      delay(DOT_DELAY);
      switch(OUTPUT_DEVICE){
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
