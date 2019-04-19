#ifndef siguelineas_h
#define siguelineas_h

#include "Arduino.h"

class Siguelineas {
  protected:
    //
    byte PIN_SIGUELINEAS_IZDA = 255;
    byte PIN_SIGUELINEAS_CENTRO = 255;
    byte PIN_SIGUELINEAS_DCHA = 255;

  public:
    //Constructor
    /**
     *
     */
    Siguelineas(byte, byte, byte) {
      PIN_SIGUELINEAS_IZDA = izda;
      PIN_SIGUELINEAS_CENTRO = centro;
      PIN_SIGUELINEAS_DCHA = dcha;
    }
    //Destructor

    //Inicializador
    /**
     *
     */
    void inicializa();


    //Reads
    /** Devuelve true si hay una linea debajo del sensor izquierdo */
    bool readIzda();

    /** Devuelve true si hay una linea debajo del sensor central */
    bool readCentro();

    /** Devuelve true si hay una linea debajo del sensor derecho */
    bool readDcha();
};
#endif
