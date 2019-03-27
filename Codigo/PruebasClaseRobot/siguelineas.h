#ifndef siguelineas_h
#define siguelineas_h

#include "Arduino.h"

class Siguelineas {
  protected:
    byte PIN_SIGUELINEAS_IZDA = -1;
    byte PIN_SIGUELINEAS_CENTRO = -1;
    byte PIN_SIGUELINEAS_DCHA = -1;

  public:
    //Constructores    
    Siguelineas(byte izda, byte centro, byte dcha) {
      this->setIzda(izda);
      this->setCentro(centro);
      this->setDcha(dcha);
    }
    //Destructor
    

    //Sets
    /** Establece el pin del sensor siguelineas izquierdo */
    void setIzda(byte siguelineasIzda) {
      PIN_SIGUELINEAS_IZDA = siguelineasIzda;
      pinMode(PIN_SIGUELINEAS_IZDA, INPUT);
    }

    /** Establece el pin del sensor siguelineas central */
    void setCentro(byte siguelineasCentro) {
      PIN_SIGUELINEAS_CENTRO = siguelineasCentro;
      pinMode(PIN_SIGUELINEAS_CENTRO, INPUT);
    }

    /** Establece el pin del sensor siguelineas derecho */
    void setDcha(byte siguelineasDcha) {
      PIN_SIGUELINEAS_DCHA = siguelineasDcha;
      pinMode(PIN_SIGUELINEAS_DCHA, INPUT);
    }


    //Reads
    /** Devuelve true si hay una linea debajo del sensor izquierdo */
    bool readIzda() {
      if (PIN_SIGUELINEAS_IZDA > 200) { //Error
        return false;
      } else {
        bool lectura =  (bool) digitalRead(PIN_SIGUELINEAS_IZDA);
        return lectura;
      }
    }

    /** Devuelve true si hay una linea debajo del sensor central */
    bool readCentro() {
      if (PIN_SIGUELINEAS_CENTRO > 200) { //Error
        return false;
      } else {
        bool lectura =  (bool) digitalRead(PIN_SIGUELINEAS_CENTRO);
        return lectura;
      }
    }

    /** Devuelve true si hay una linea debajo del sensor derecho */
    bool readDcha() {
      if (PIN_SIGUELINEAS_DCHA > 200) { //Error
        return false;
      } else {
        bool lectura =  (bool) digitalRead(PIN_SIGUELINEAS_DCHA);
        return lectura;
      }
    }
};
#endif
