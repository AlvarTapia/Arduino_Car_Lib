#ifndef cnosos_h
#define cnosos_h

#include "robot.cpp"

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
    byte siguiente();

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
