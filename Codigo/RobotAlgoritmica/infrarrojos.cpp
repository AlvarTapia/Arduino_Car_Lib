#ifndef infrarrojos_cpp
#define infrarrojos_cpp

#include "infrarrojos.h"

/*
 * IMPORTANTE
 * La libreria RobotIRremote.h puede causar conflictos.
 * Esta ubicada en C:/Program Files (x86)/Arduino/libraries/RobotIRremote.
 *
 * En primer lugar, RobotIRremoteTools.h y IRremoteTools.cpp no se van a usar.
 * Si causan problemas, borrar esos archivos es una solucion.
 *
 * Si la funcion tone() y la libreria RobotIRremote causan problemas,
 * se recomienda abrir el archivo RobotIRremoteInt.h y
 * cambiar el IR_USE_TIMER de Arduino Duemilanove al timer 1.
 * Eso deberia verificar la compilacion.
 */
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
    byte PIN_INFRARROJOS = 255;
    IRrecv irrecv = IRrecv(255);

  public:
    //Constructores
    Infrarrojos(byte pinInfrarrojos){
      PIN_INFRARROJOS = pinInfrarrojos;

      irrecv = IRrecv(PIN_INFRARROJOS);
    }
    //Constructor por defecto
    Infrarrojos(){
      Infrarrojos(255);
    }
    //Destructor


    void inicializa(){
      pinMode(PIN_INFRARROJOS, INPUT);
    }

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
