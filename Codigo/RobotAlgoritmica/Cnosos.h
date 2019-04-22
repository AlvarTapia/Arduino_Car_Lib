/*
----------------------------------------------------------------
  Cnosos.h
  Libreria que lee, reconoce y navega grafos con robots Arduino.
  
  Adaptado por Alvar Tapia, Abril 2019.
  Legado de Algorítmica y Complejidad, Universidad de Cantabria.
----------------------------------------------------------------
*/

#ifndef cnosos_h
#define cnosos_h

#include "robot.h"

class Cnosos {
  //
  #define SENSOR_IZDA robot.SIGUELINEAS.readIzda()
  #define SENSOR_CENTRO robot.SIGUELINEAS.readCentro()
  #define SENSOR_DCHA robot.SIGUELINEAS.readDcha()
  //
  #define TIEMPO_PENSAR 500
  private:
    //
    Robot robot;
    //
    byte BITS;
  public:
    //Constructores
    /**
     *
     */
    Cnosos(Robot, byte = 3);
    //Destructor


    //Funciones
    /**
     *
     */
    byte siguiente();
    
    /**
     *
     */
    byte lee_numero();

    /**
     *
     */
    void lee_nodo(byte&, byte&, byte&);

    /**
     *
     */
    byte calcula_entrada(byte, byte);

    /**
     *
     */
    void sal_aqui();

    /**
     *
     */
    void sal(byte, byte, byte);

    /**
     *
     */
    void sal_izq();

    /**
     *
     */
    void luce_numero(byte);

    /**
     *
     */
    void error();
};

#endif
