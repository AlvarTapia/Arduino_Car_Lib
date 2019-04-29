/**
 * ----------------------------------------------------------------
 * siguelineas.h
 * Clase que permite utilizar los sensores siguelineas.
 * Se espera que se usen como mucho tres sensores por objeto.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef siguelineas_h
#define siguelineas_h

#include "Arduino.h"

class Siguelineas {
  protected:
    /// Pines a los que estan conectados los siguelineas.
    byte PIN_SIGUELINEAS_IZDA;
    byte PIN_SIGUELINEAS_CENTRO;
    byte PIN_SIGUELINEAS_DCHA;

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
    Siguelineas(byte, byte, byte);
    /**
     * Establece dos pines para los sensores siguelineas.
     * @param Pin siguelineas izquierdo
     *    Pin conectado al siguelineas izquierdo.
     * @param Pin siguelineas derecho
     *    Pin conectado al siguelineas derecho.
     */
    Siguelineas(byte, byte);
    /**
     * Establece un pin para el sensor siguelineas.
     * @param Pin siguelineas central
     *    Pin conectado al siguelineas central.
     */
    Siguelineas(byte);
    //Constructor por defecto
    /**
     * Constructor que no necesita argumentos, y que permite inicializar variables
     * como las presentes en robot.h.
     * Las variables se inicializan a valores no recomendables como pines inaccesibles.
     * IMPORTANTE: Sustituir todas las instancias no inicializadas o inicializadas de esta manera
     *    para que el modulo funcione como se espera.
     */
    Siguelineas();
    //Destructor


    //Inicializador
    /**
     * Permite a los pines establecidos en el constructor
     * recibir señales de los modulos siguelineas.
     */
    void inicializa();

    //Funciones
    /**
     * Accede al sensor izquierdo y devuelve su lectura.
     * @return TRUE si hay una linea debajo del sensor izquierdo.
     */
    bool readIzda();

    /**
     * Accede al sensor central y devuelve su lectura.
     * @return TRUE si hay una linea debajo del sensor central.
     */
     bool readCentro();

    /**
     * Accede al sensor derecho y devuelve su lectura.
     * @return TRUE si hay una linea debajo del sensor derecho.
     */
     bool readDcha();
};

#endif
