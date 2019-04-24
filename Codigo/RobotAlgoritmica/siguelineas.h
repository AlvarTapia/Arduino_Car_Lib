/**
 * ----------------------------------------------------------------
 * siguelineas.h
 * Clase que permite utilizar los sensores siguelineas.
 * Se espera que se usen tres sensores por objeto.
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
    //Constructor
    /**
     * Establece los pines de los sensores siguelineas.
     * @param Pin siguelineas izquierdo
     *    Pin conectado al siguelineas izquierdo.
     *    Por defecto, se asignara un pin inaccesible.
     * @param Pin siguelineas central
     *    Pin conectado al siguelineas central.
     *    Por defecto, se asignara un pin inaccesible.
     * @param Pin siguelineas derecho
     *    Pin conectado al siguelineas derecho.
     *    Por defecto, se asignara un pin inaccesible.
     */
    Siguelineas(byte = 255, byte = 255, byte = 255);
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
     * @return true si hay una linea debajo del sensor izquierdo.
     */
    bool readIzda();

    /**
     * Accede al sensor central y devuelve su lectura.
     * @return true si hay una linea debajo del sensor central.
     */
     bool readCentro();

    /**
     * Accede al sensor derecho y devuelve su lectura.
     * @return true si hay una linea debajo del sensor derecho.
     */
     bool readDcha();
};

#endif
