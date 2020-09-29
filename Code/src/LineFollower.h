/**
 * ----------------------------------------------------------------
 * LineFollower.h
 * Clase que permite utilizar los sensores siguelineas.
 * Se espera que se usen como mucho tres sensores por objeto.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef linefollower_h
#define linefollower_h

#include "Arduino.h"

class LineFollower {
  protected:
    /// Pines a los que estan conectados los siguelineas.
    byte LEFT_LINE_SENSOR_PIN;
    byte CENTRE_LINE_SENSOR_PIN;
    byte RIGHT_LINE_SENSOR_PIN;

  public:
    //Constructores
    /**
     * Establece tres pines para los sensores siguelineas.
     * @param Pin siguelineas izquierdo
     *    Pin conectado al siguelineas izquierdo.
     * @param Pin siguelineas central
     *    Pin conectado al siguelineas central.
     * @param Pin siguelineas derecho
     *    Pin conectado al siguelineas derecho.
     */
    LineFollower(byte, byte, byte);
    /**
     * Establece dos pines para los sensores siguelineas.
     * @param Pin siguelineas izquierdo
     *    Pin conectado al siguelineas izquierdo.
     * @param Pin siguelineas derecho
     *    Pin conectado al siguelineas derecho.
     */
    LineFollower(byte, byte);
    /**
     * Establece un pin para el sensor siguelineas.
     * @param Pin siguelineas central
     *    Pin conectado al siguelineas central.
     */
    LineFollower(byte);
    //Constructor por defecto
    /**
     * Constructor que no necesita argumentos,
     * y que permite inicializar variables como las presentes en robot.h.
     * Las variables se inicializan a valores no recomendables
     * como pines inaccesibles.
     * IMPORTANTE: Sustituir todas las instancias no inicializadas
     *    o inicializadas de esta manera para que el modulo
     *    funcione como se espera.
     */
    LineFollower();
    //Destructor


    //Inicializador
    /**
     * Permite a los pines establecidos en el constructor
     * recibir señales de los modulos siguelineas.
     */
    void init();

    //Funciones
    /**
     * Accede al sensor izquierdo y devuelve su lectura.
     * @return TRUE si hay una linea debajo del sensor izquierdo.
     */
    bool leftRead();

    /**
     * Accede al sensor central y devuelve su lectura.
     * @return TRUE si hay una linea debajo del sensor central.
     */
     bool centreRead();

    /**
     * Accede al sensor derecho y devuelve su lectura.
     * @return TRUE si hay una linea debajo del sensor derecho.
     */
     bool rightRead();

     /**
      * Access all available sensors and returns its collective reading.
      * @return 3 bit number.
      *         If sensors are detecting lines, left, centre or right
      *         adds 1, 2 or 4 respectively to the default value (0).
      */
     byte read();
};

#endif
