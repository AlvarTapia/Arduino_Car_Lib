/**
 * ----------------------------------------------------------------
 * Cnosos.h
 * Libreria que lee, reconoce y navega grafos con robots Arduino.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef cnosos_h
#define cnosos_h

#include "robot.h"

class Cnosos {
  //TODO
  #define SENSOR_IZDA robot.SIGUELINEAS.readIzda()
  #define SENSOR_CENTRO robot.SIGUELINEAS.readCentro()
  #define SENSOR_DCHA robot.SIGUELINEAS.readDcha()
  //TODO
  #define TIEMPO_PENSAR 500
  private:
    //TODO
    Robot robot;
    //TODO
    byte BITS;
  public:
    //Constructores
    /**
     * TODO
     * @param
     * @param
     */
    Cnosos(Robot, byte = 3);
    //Destructor


    //Funciones
    /**
     * TODO
     */
    byte siguiente();

    /**
     * TODO
     */
    byte lee_numero();

    /**
     * TODO
     */
    void lee_nodo(byte&, byte&, byte&);

    /**
     * TODO
     */
    byte calcula_entrada(byte, byte);

    /**
     * TODO
     */
    void sal_aqui();

    /**
     * TODO
     */
    void sal(byte, byte, byte);

    /**
     * TODO
     */
    void sal_izq();

    /**
     * TODO
     */
    void luce_numero(byte);

    /**
     * TODO
     */
    void error();
};

#endif
