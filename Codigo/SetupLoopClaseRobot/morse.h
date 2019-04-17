#ifndef morse_h
#define morse_h

#include "Arduino.h"

class Morse{
  #define DEFAULT_SIREN_FREC 15000
  #define DASH_DELAY 300
  #define DOT_DELAY 100
  #define INBETWEEN_DELAY 100
  
  private:
    byte PIN_MORSE = 255;
    char OUTPUT_DEVICE = 'x';
    
    unsigned int SIREN_FREC = DEFAULT_SIREN_FREC;
  public:
    //Constructores
    Morse(byte pinMorse, char outputDevice, int sirenFrec = DEFAULT_SIREN_FREC){
      PIN_MORSE = pinMorse;
      OUTPUT_DEVICE = outputDevice;
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
