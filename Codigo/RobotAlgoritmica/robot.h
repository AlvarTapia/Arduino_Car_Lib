/**
 * ----------------------------------------------------------------
 * robot.h
 * Clase que gestiona los motores de un robot implementado con placas Arduino.
 * Pueden aplicarse modulos para mejorar la gestion del movimiento del robot.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef robot_h
#define robot_h

#include "siguelineas.h"
//#include "infrarrojos.h" //A Abril 2019, esta biblioteca no se utiliza
#include "morse.h"
#include "bluetooth.h"

#include "Arduino.h"


class Robot {
  /// Velocidades por defecto de los motores del robot. 
  /// Valores de 0-255, siendo 0 = motores parados, 255 = maxima potencia.
  #define VELOCIDAD_LENTA 100
  #define VELOCIDAD_GIRO 200
  #define MAX_VELOCIDAD 255

  private:
    /// Enumerados que representan la direccion a la que va el robot. Necesario para saber cuando arrancar.
    enum Direccion {dirNull = -1, dirAlante, dirAtras, dirGiroDcha, dirGiroIzda, dirRotaDcha, dirRotaIzda};
    /// Direccion actual del robot. Se encuentra parado por defecto.
    Direccion dirActual = dirNull;

  protected:
    /// Tiempo que necesita arrancar el robot, en milisegundos.
    byte TIEMPO_ARRANQUE;

    /// Pines que controlan la direccion en la que giran los motores.
    byte PIN_IZDA_ALANTE;
    byte PIN_IZDA_ATRAS;
    byte PIN_DCHA_ALANTE;
    byte PIN_DCHA_ATRAS;
    /* 
     * Para que el robot se mueva, ALANTE != ATRAS.
     * p.ej. ALANTE = HIGH y ATRAS = LOW hace que el motor se mueva hacia delante.
     * Pero ALANTE == ATRAS deja de alimentar los motores, independientemente de que valgan HIGH o LOW.
     */

    /// Pines que controlan la velocidad a la que giran los motores.
    byte PIN_VEL_IZDA;
    byte PIN_VEL_DCHA;

  public:
    /**
     *  Variables para modulos. Se acceden de forma directa, tanto para modificar como para usar funciones.
     *  Para utilizar los modulos, los objetos deben establecerse e inicializarse.
     */
    /// Modulo siguelineas
    Siguelineas SIGUELINEAS;
    /// Modulo mando infrarrojo
    //Infrarrojos INFRARROJOS; //A Abril 2019, este objeto no se utiliza
    /// Modulo morse
    Morse MORSE;
    /// Modulo bluetooth
    Bluetooth BLUETOOTH;

    //Constructores
    /**
     * Inicializa un robot cuyo driver tiene 4 entradas para 8 cables de motores.
     * @param Pin motor izquierdo hacia alante
     * @param Pin motor izquierdo hacia atras
     * @param Pin motor derecho hacia alante
     * @param Pin motor derecho hacia atras
     *    Pines de direccion de los motores.
     * @param Pin de velocidad del motor izquierdo
     * @param Pin de velocidad del motor derecho
     *    Pines de control de velocidad de los motores.
     * @param Tiempo de arranque
     *    Tiempo que necesita el robot para arrancar, en milisegundos. Valores entre 0-255 ms.
     */
    Robot(byte, byte, byte, byte, byte, byte, byte);
    //Constructor por defecto
    Robot();
    //Destructores


	//Inicializar
    /**
     * Inicializa los pines para que el robot pueda alimentar los motores.
     */
    void inicializa();


    //Funciones del robot
    /**
     * Permite modificar el tiempo que va a estar arrancando el robot.
     * @param Tiempo de arranque
     *    Tiempo en milisegundos que estara el robot a maxima velocidad. Valores entre 0-255 ms.
     */
    void setTiempoArranque(byte);
    
    
    //Velocidad del robot
    /**
     * Aplica mucha tension durante un periodo de tiempo definido
     * para que los motores puedan empezar a girar.
     */
    void arranca();

    /** 
     * Establece la velocidad actual del robot.
     * @param Velocidad
     *    Velocidad a la que ira el robot. Valores entre 0-255.
     */
    void setVelocidad(byte);

    /** 
     * Deja de alimentar los motores y para el robot.
     * Puede no ser inmediato dependiendo de la inercia que lleve.
     */
    void para();

    /**
     * Alimenta los motores al 40% de la capacidad de las pilas.
     */
    void lento();

    /**
     * Establece una velocidad moderada, en la que el robot es siempre capaz de girar.
     */
    void velGiro();

    /**
     * Alimenta los motores al 100% de la capacidad de las pilas.
     */
    void maxVelocidad();


	//Cambios de direccion
    /**
     * El robot deja de alimentar los motores de la izquierda para poder girar a la izquierda.
     * Permite girar mientras el robot va marcha atras.
     * @param Velocidad
     *    Se puede indicar la velocidad a la que el robot hace la maniobra.
     *    Por defecto, se utiliza VELOCIDAD_GIRO.
     */
    void giraIzda(byte = VELOCIDAD_GIRO);
	
	/**
     * El robot deja de alimentar los motores de la derecha para poder girar a la derecha.
     * Permite girar mientras el robot va marcha atras.
     * @param Velocidad
     *    Se puede indicar la velocidad a la que el robot hace la maniobra.
     *    Por defecto, se utiliza VELOCIDAD_GIRO.
     */
    void giraDcha(byte = VELOCIDAD_GIRO);


    //Cambios de direccion de los motores
    /** 
     * Los motores giran de manera que el robot vaya hacia delante. 
     * @param Velocidad
     *    Se puede indicar la velocidad a la que el robot hace la maniobra.
     *    Por defecto, se utiliza VELOCIDAD_LENTA.
     */
    void alante(byte = VELOCIDAD_LENTA);

    /** Los motores giran de manera que el robot vaya hacia atras.
     * @param Velocidad
     *    Se puede indicar la velocidad a la que el robot hace la maniobra.
     *    Por defecto, se utiliza VELOCIDAD_LENTA.
     */
    void atras(byte = VELOCIDAD_LENTA);

    /** 
     * El robot pivota hacia la izquierda haciendo 
     * que los motores de la izquierda vayan hacia atras y
     * que los motores de la derecha vayan hacia delante.
     * @param Velocidad
     *    Se puede indicar la velocidad a la que el robot hace la maniobra.
     *    Por defecto, se utiliza VELOCIDAD_GIRO.
     */
    void rotaIzda(byte = VELOCIDAD_GIRO);

    /**
     * El robot pivota hacia la derecha haciendo 
     * que los motores de la derecha vayan hacia atras y
     * que los motores de la izquierda vayan hacia delante.
     * @param Velocidad
     *    Se puede indicar la velocidad a la que el robot hace la maniobra.
     *    Por defecto, se utiliza VELOCIDAD_GIRO.
     */
    void rotaDcha(byte = VELOCIDAD_GIRO);
};

/* OBJETOS YA DISEÑADOS */
/// Configuracion de los robots Arduino
const Robot arduino(255, 12, 255, 13, 10, 11, 80); //El pin 255 es inaccesible,
//y permite escribir "digitalWrite"s sin afectar al funcionamiento del robot

/// Configuracion de los robots Elegoo
const Robot elegoo(6, 7, 9, 8, 5, 11, 0);

#endif
