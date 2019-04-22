/*
----------------------------------------------------------------
  Bluetooth.h
  Clase controlador del modulo Bluetooth.
  Permite que la Arduino pueda enviar y recibir mensajes.
  
  Adaptado por Alvar Tapia, Abril 2019.
  Legado de Algorítmica y Complejidad, Universidad de Cantabria.
----------------------------------------------------------------
*/

#ifndef siguelineas_h
#define siguelineas_h

#include "Arduino.h"

class Siguelineas {
  protected:
    //
    byte PIN_SIGUELINEAS_IZDA;
    byte PIN_SIGUELINEAS_CENTRO;
    byte PIN_SIGUELINEAS_DCHA;

  public:
    //Constructor
    /**
     *
     */
    Siguelineas(byte = 255, byte = 255, byte = 255);
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
