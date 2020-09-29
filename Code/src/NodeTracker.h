/**
 * ----------------------------------------------------------------
 * NodeTracker.h
 * Libreria que lee, reconoce y navega grafos con robots Arduino.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef nodetracker_h
#define nodetracker_h

#include "Robot.h"

class NodeTracker {
  /// Redefiniciones de metodos que se usaran a lo largo de la clase.
  // Reducen y hacen mas intuitivo el codigo.
  #define LEFT_SENSOR robot.SIGUELINEAS.leftRead()
  #define CENTRE_SENSOR robot.SIGUELINEAS.centreRead()
  #define RIGHT_SENSOR robot.SIGUELINEAS.rightRead()

  /**
   * Se espera este tiempo en milisegundos
   * para confirmar que se ha leido una marca.
   */
  #define CONFIRMATION_TIME 0

  /** Cada vez que tiene que procesar una entrada, el robot "pensara"
   * (se quedara quieto) este numero de milisegundos.
   */
  #define THINKING_TIME 300
  private:
    /// Guarda la configuracion del robot que se va a usar en este objeto.
    Robot robot;
    /// Numero de bits que usaran los nodos para identificarse.
    byte BITS_OF_ID;
  protected:
    const byte DEFAULT_ID_LENGTH = 3;
  public:
    //Constructores
    /**
     * Constructor de la libreria NodeTracker.
     * No necesita un metodo inicializar,
     * dado que se supone que los parametros ya estan inicializados.
     * @param Robot a controlar
     *    Objeto Robot con el que se va a trabajar.
     *    Se espera que el Robot este inicializado,
     *    asi como su Siguelineas.
     *    Si se necesita debuggear o que el robot
     *    se comunique con el usuario, es necesario inicializar
     *    el modulo Morse o el modulo Bluetooth, o ambos.
     * @param Numero bits en las etiquetas
     *    Numero de bits que se usaran para identificar
     *    cada nodo del mapa.
     *    Se espera que el tamaño del parametro sea adecuado,
     *    dado que si se utiliza el valor maximo (255),
     *    se podrian identificar 2^255 nodos, que son mas de 10^76 nodos.
     *    Por defecto, se utilizaran 3 marcas
     *    para el identificador de cada nodo.
     */
    NodeTracker(Robot, byte = DEFAULT_ID_LENGTH);
    //Constructor por defecto
    /**
     * Constructor que no necesita argumentos,
     * y que permite inicializar un objeto NodeTracker.
     * Las variables se inicializan a valores inaccesibles.
     * IMPORTANTE: Sustituir todas las instancias no inicializadas o
     *    inicializadas de esta manera para que el objeto
     *    funcione correctamente.
     */
    NodeTracker();
    //Destructor


    //Funciones
    /**
     * Avanza por la linea hasta encontrar un hueco en la cinta
     * o una cinta atravesada. Sobrepasa el indicador.
     * @return  0 si ha encontrado un hueco en la cinta,
     *          1 si ha encontrado una cinta atravesada.
     */
    byte nextBit();

    /**
     * Lee un identificador de nodo.
     * Este metodo supone que se acaba de cruzar
     * el marcador de comienzo del identificador.
     * Por defecto, ese marcador es un hueco en la cinta.
     */
    byte readNumber();

    /**
     * Recorre dos veces el perimetro del nodo
     * para obtener gran cantidad de datos.
     * Al terminar el metodo, el robot estara situado
     * despues del identificador del nodo.
     * @param[out] Identificador del nodo
     *    Devuelve el numero que identifica a este nodo.
     * @param[out] Grado del nodo
     *    Devuelve el grado (o el numero de cruces)
     *    que tiene este nodo.
     * @param[out] Cruce por el que ha entrado el robot al nodo
     *    Devuelve el numero del cruce por el que ha entrado el nodo.
     *    Si el robot empezo a recorrer el nodo justo detras
     *    del identificador, este numero sera 0,
     *    si se empezo detras del primer cruce sera 1...
     *    asi hasta 'grado', que significaria que el robot
     *    ha empezado a recorrer el nodo antes del identificador.
     */
    void readNode(byte&, byte&, byte&);

    /**
     * En cuanto se encuentre un cruce,
     * toma ese cruce y el robot pasa al nextBit nodo.
     */
    void takeThisTurn();

    /**
     * Toma un cruce en concreto desde la posicion
     * en la que este el robot.
     * @param Cruce a tomar
     *    Numero del cruce que se quiere tomar,
     *    siendo 1 el primer cruce de la etiqueta.
     * @param Grado del nodo
     *    Ultimo cruce que puede tomar el robot.
     *    Tambien representa el grado (o el numero de cruces)
     *    que hay en el nodo.
     * @param Cruce actual
     *    Indica cual es el ultimo cruce que el robot se ha saltado.
     *    Por defecto, se considera que el robot esta
     *    justo detras de la etiqueta, por lo que
     *    no se ha saltado ningun cruce (este valor es 0).
     */
    void takeExit(byte, byte, byte = 0);

    /**
     * Toma una salida a la izquierda.
     */
    void takeLeft();

    /**
     * Comunica un numero al usuario por medio de modulos.
     * Necesita tener inicializado el modulo Morse
     * o el modulo Bluetooth para comunicarse con el usuario.
     * @param Numero a comunicar
     *    Envia este numero, ya sea con el mismo numero de pitidos,
     *    o con un mensaje Bluetooth.
     */
    void showNumber(byte);

    /**
     * Se ha encontrado un suceso inesperado. Se para y grita SOS.
     * Necesita tener inicializado el modulo Morse
     * o el modulo Bluetooth para comunicarse con el usuario.
     */
    void error();
};

#endif
