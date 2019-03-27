#ifndef infrarrojos_h
#define infrarrojos_h

#include <RobotIRremote.h>

#include "Arduino.h"


class Infrarrojos{
  
  #define CERO 16730805
  #define UNO 16738455
  #define DOS 16750695
  #define TRES 16756815
  #define CUATRO 16724175
  #define CINCO 16718055
  #define SEIS 16743045
  #define SIETE 16716015
  #define OCHO 16726215
  #define NUEVE 16734885

  private:
    byte PIN_INFRARROJOS;
    IRrecv irrecv = IRrecv(255);
    
  public:
    //Constructores
    Infrarrojos() {  }
    Infrarrojos(byte pinInfrarrojos){
      PIN_INFRARROJOS = pinInfrarrojos;
      
      irrecv = IRrecv(PIN_INFRARROJOS);
      pinMode(PIN_INFRARROJOS, INPUT);
    }
    //Destructor


    byte esperaMando(){
      decode_results results;
      unsigned long RED;
      byte aux = 0xFF;
      while (aux == 0xFF) {
        if (irrecv.decode(&results)) {
          irrecv.resume();
          RED = results.value;
          switch (RED) {
            case CERO:
              aux = 0;
              break;
            case UNO:
              aux = 1;
              break;
            case DOS:
              aux = 2;
              break;
            case TRES:
              aux = 3;
              break;
            case CUATRO:
              aux = 4;
              break;
            case CINCO:
              aux = 5;
              break;
            case SEIS:
              aux = 6;
              break;
            case SIETE:
              aux = 7;
              break;
            case OCHO:
              aux = 8;
              break;
            case NUEVE:
              aux = 9;
              break;
          }
        }
      }
      return aux;  
    }
};

#endif
