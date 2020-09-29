/**
 * ----------------------------------------------------------------
 * Morse.h
 * Libreria que permite que la Arduino pueda enviar señales en Morse.
 * Necesita de un dispositivo que pueda cambiar notablemente de estado,
 * como un LED o una sirena.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef morse_h
#define morse_h

#include "Arduino.h"
#include "MorseDeviceType.h"

class Morse{
  /**
   * Tiempo que va a estar la señal activa para representar una raya,
   * en ms.
   */
  #define DASH_TIME 300
  /**
   * Tiempo que va a estar la señal activa para representar un punto,
   * en ms.
   */
  #define DOT_TIME 100
  /**
   * Tiempo que va a estar la señal desactivada
   * para diferenciar simbolos morse, en ms.
   */
  #define TIME_BETWEEN_SYMBOLS 100

  private:
    /**
     * Caracter que guarda el dispositivo de salida.
     * 'l' = LED, dispositivo que funciona de manera binaria,
     *       ENCENDIDO o APAGADO.
     * 's' = sirena, dispositivo que produce sonidos.
     *       Puede variar de frecuencia ademas
     *       de poder estar ENCENDIDO o APAGADO.
     */
    MorseDeviceType device;
  public:
    //Constructor
    /**
     * Constructor de la libreria.
     * @param Pin output
     *    Guarda el pin que se va a utilizar para enviar las señales.
     *    Debe estar conectado a un dispositivo que cambie notablemente
     *    de estado.
     * @param Tipo dispositivo
     *    'l' = Dispositivo tipo LED.
     *    's' = Dispositivo tipo sirena.
     * @param Frecuencia sirena
     *    Frecuencia a la que va a trabajar la sirena, en hercios.
     *    Si se esta trabajando con LEDs, este campo se puede ignorar.
     *    Los humanos podemos oír entre 20 Hz y 20 kHz.
     *    Las frecuencias mas bajas se perciben con mas volumen
     *    y pueden llegar a ser muy molestas.
     *    Por defecto, toma el valor de DEFAULT_SIREN_FREC.
     */
    Morse(MorseDeviceType = noneDevice);
    //Constructor por defecto
    /**
     * Constructor que no necesita argumentos, y que permite
     * initr variables como las presentes en robot.h.
     * Las variables se initn a valores no recomendables como
     * pines inaccesibles y caracteres que no tiene significado en la clase.
     * IMPORTANTE: Sustituir todas las instancias no initdas
     *    o initdas de esta manera para que
     *    el modulo funcione como se espera.
     */
     // TODO
    //Destructor


    //Inicializador
    /**
     * Permite al pin establecido en el constructor
     * mandar señales en Morse.
     */
    void init();

    //Funciones

    void symbol(int);

    /**
     * Manda una señal "raya", y espera un tiempo callado.
     */
    void dash();

    /**
     * Manda una señal "punto", y espera un tiempo callado.
     */
    void dot();

    /**
     * Manda un conjunto de señales que comunican "sos".
     * Al terminar el mensaje, espera un largo tiempo callado.
     */
    void sos();
};

#endif
