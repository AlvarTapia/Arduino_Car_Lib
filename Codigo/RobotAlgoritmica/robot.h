#ifndef robot_h
#define robot_h

#include "siguelineas.cpp"
#include "infrarrojos.cpp"
#include "morse.cpp"
#include "bluetooth.cpp"

#include "Arduino.h"

/**
 *
 */
class Robot {
  //
  #define VELOCIDAD_LENTA 100
  #define VELOCIDAD_GIRO 200
  #define MAX_VELOCIDAD 255

  private:
    //
    enum Direccion {dirNull = -1, dirAlante, dirAtras, dirGiroDcha, dirGiroIzda, dirRotaDcha, dirRotaIzda};
    //
    Direccion dirActual = dirNull;

  protected:
    //
    byte TIEMPO_ARRANQUE;

    //
    byte PIN_IZDA_ALANTE;
    byte PIN_IZDA_ATRAS;
    byte PIN_DCHA_ALANTE;
    byte PIN_DCHA_ATRAS;

    //
    byte PIN_VEL_IZDA;
    byte PIN_VEL_DCHA;

  public:
    /**
     *  Variables modulos. Se acceden directamente.
     *  Para utilizarlas, los objetos deben ser inicializados con pines validos.
    */
    //Modulo siguelineas
    Siguelineas SIGUELINEAS;
    //Modulo mando infrarrojo
    Infrarrojos INFRARROJOS;
    //Modulo morse
    Morse MORSE;
    //Modulo bluetooth
    Bluetooth BLUETOOTH;//Queremos trabajar a 9600 baudios, y con 'x' como caracter de arranque

    //Constructor
    /**
       Inicializa un robot cuyo driver solo tiene 4 entradas para 8 cables de motores
       4 primeros argumentos, pines de control de direccion de los motores
       2 siguientes, pines de control de velocidad de los motores
       ultimo, si es necesario arrancar el robot para cambiar de direccion
    */
    Robot(byte, byte, byte, byte, byte, byte, byte);
    //Destructores


    //Funciones del robot
    //Motores
    //Inicializar
    /** Inicializa los pines para que el robot funcione correctamente */
    void inicializa();


    //Velocidad del robot
    /** Permite modificar el tiempo que va a estar arrancando el robot */
    void setTiempoArranque(byte tiempoArranque);

    /** Se aplica mucha tension durante un corto periodo de tiempo para que los motores empiecen a funcionar */
    void arranca();

    /** Declara la velocidad del robot */
    void setVelocidad(byte velocidad);

    /** Deja de alimentar los motores */
    void para();

    /** Mueve el robot al 40% de la capacidad de las pilas */
    void lento();

    /** Velocidad moderada, el robot es capaz de girar */
    void velGiro();

    /** Mueve el robot al 100% de la capacidad de las pilas */
    void maxVelocidad();


    /** El robot para los motores de la izda */
    void giraIzda(byte = VELOCIDAD_GIRO);

    /** El robot para los motores de la dcha */
    void giraDcha(byte = VELOCIDAD_GIRO);


    //Direccion del robot
    /** Los motores giran de manera que el robot va hacia alante */
    void alante(byte = VELOCIDAD_LENTA);

    /** Los motores giran de manera que el robot va hacia atras */
    void atras(byte = VELOCIDAD_LENTA);

    /** El robot pivota hacia la izda retrocediendo con la izda y avanzando con la dcha */
    void rotaIzda(byte = VELOCIDAD_GIRO);

    /** El robot pivota hacia la izda retrocediendo con la dcha y avanzando con la izda */
    void rotaDcha(byte = VELOCIDAD_GIRO);
};

/** OBJETOS YA DISEÑADOS */
Robot arduino(255, 12, 255, 13, 10, 11, 80); //El pin 255 no se puede usar,
//y me permite escribir "digitalWrite"s sin afectar al funcionamiento del robot

Robot elegoo(6, 7, 9, 8, 5, 11, 0);
#endif
