/**
 * ----------------------------------------------------------------
 * TODO.h
 * TODO
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef robot_h
#define robot_h

#include "siguelineas.h"
#include "infrarrojos.h"
#include "morse.h"
#include "bluetooth.h"

#include "Arduino.h"


class Robot {
  /// TODO
  #define VELOCIDAD_LENTA 100
  #define VELOCIDAD_GIRO 200
  #define MAX_VELOCIDAD 255

  private:
    /// TODO
    enum Direccion {dirNull = -1, dirAlante, dirAtras, dirGiroDcha, dirGiroIzda, dirRotaDcha, dirRotaIzda};
    /// TODO
    Direccion dirActual = dirNull;

  protected:
    /// TODO
    byte TIEMPO_ARRANQUE;

    /// TODO
    byte PIN_IZDA_ALANTE;
    byte PIN_IZDA_ATRAS;
    byte PIN_DCHA_ALANTE;
    byte PIN_DCHA_ATRAS;

    /// TODO
    byte PIN_VEL_IZDA;
    byte PIN_VEL_DCHA;

  public:
    /**
     *  Variables modulos. Se acceden directamente.
     *  Para utilizar los modulos, los objetos deben establecerse e inicializarse.
     */
    /// Modulo siguelineas
    Siguelineas SIGUELINEAS;
    /// Modulo mando infrarrojo
    Infrarrojos INFRARROJOS;
    /// Modulo morse
    Morse MORSE;
    /// Modulo bluetooth
    Bluetooth BLUETOOTH;

    //Constructores
    /**
     * Inicializa un robot cuyo driver tiene 4 entradas para 8 cables de motores.
     * @param 4 primeros argumentos, pines de control de direccion de los motores.
     * @param 2 siguientes argumentos, pines de control de velocidad de los motores.
     * @param tiempo que necesita el robot para arrancar.
    */
    Robot(byte, byte, byte, byte, byte, byte, byte);
    //Constructor por defecto
    Robot();
    //Destructores


    //Funciones del robot
    //Motores
    //Inicializar
    /**
     * Inicializa los pines para que el robot funcione correctamente.
     */
    void inicializa();


    //Velocidad del robot
    /**
     * Permite modificar el tiempo que va a estar arrancando el robot.
     * @param Tiempo de arranque
     *    Tiempo en milisegundos que estara el robot a maxima velocidad.
     */
    void setTiempoArranque(byte);

    /**
     * Se aplica mucha tension durante un corto periodo de tiempo
     * para que los motores puedan empezar a girar.
     */
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
const Robot arduino(255, 12, 255, 13, 10, 11, 80); //El pin 255 no se puede usar,
//y me permite escribir "digitalWrite"s sin afectar al funcionamiento del robot

const Robot elegoo(6, 7, 9, 8, 5, 11, 0);

#endif
