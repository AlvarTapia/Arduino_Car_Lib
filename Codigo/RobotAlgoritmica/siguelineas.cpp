#ifndef siguelineas_cpp
#define siguelineas_cpp

#include "siguelineas.h"

class Siguelineas {
  protected:
    byte PIN_SIGUELINEAS_IZDA = 255;
    byte PIN_SIGUELINEAS_CENTRO = 255;
    byte PIN_SIGUELINEAS_DCHA = 255;

  public:
    //Constructores
    Siguelineas(byte izda, byte centro, byte dcha) {
      PIN_SIGUELINEAS_IZDA = izda;
      PIN_SIGUELINEAS_CENTRO = centro;
      PIN_SIGUELINEAS_DCHA = dcha;
    }
    //Constructor por defecto
    Siguelineas(){
      Siguelineas(255, 255, 255);
    }
    //Destructor


    void inicializa(){
      pinMode(PIN_SIGUELINEAS_IZDA, INPUT);
      pinMode(PIN_SIGUELINEAS_CENTRO, INPUT);
      pinMode(PIN_SIGUELINEAS_DCHA, INPUT);
    }


    //Reads
    /** Devuelve true si hay una linea debajo del sensor izquierdo */
    bool readIzda() {
      if (PIN_SIGUELINEAS_IZDA == 255) { //Error
        return false;
      } else {
        return digitalRead(PIN_SIGUELINEAS_IZDA);
      }
    }

    /** Devuelve true si hay una linea debajo del sensor central */
    bool readCentro() {
      if (PIN_SIGUELINEAS_CENTRO == 255) { //Error
        return false;
      } else {
        return digitalRead(PIN_SIGUELINEAS_CENTRO);
      }
    }

    /** Devuelve true si hay una linea debajo del sensor derecho */
    bool readDcha() {
      if (PIN_SIGUELINEAS_DCHA == 255) { //Error
        return false;
      } else {
        return digitalRead(PIN_SIGUELINEAS_DCHA);
      }
    }
};
#endif
