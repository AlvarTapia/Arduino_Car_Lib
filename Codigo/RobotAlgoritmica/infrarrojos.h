/*
----------------------------------------------------------------
  Bluetooth.h
  Clase controlador del modulo Bluetooth.
  Permite que la Arduino pueda enviar y recibir mensajes.
  
  Adaptado por Alvar Tapia, Abril 2019.
  Legado de Algorítmica y Complejidad, Universidad de Cantabria.
----------------------------------------------------------------
*/

#ifndef infrarrojos_h
#define infrarrojos_h

#include <RobotIRremote.h>

#include "Arduino.h"

/*
 * IMPORTANTE
 * La libreria RobotIRremote.h puede causar conflictos.
 * Esta ubicada en C:/Program Files (x86)/Arduino/libraries/RobotIRremote.
 *
 * En primer lugar, RobotIRremoteTools.h y IRremoteTools.cpp no se van a usar.
 * Si causan problemas, borrar esos archivos es una solucion.
 *
 * Si la funcion tone() y la libreria RobotIRremote causan problemas,
 * se recomienda abrir el archivo RobotIRremoteInt.h y
 * cambiar el IR_USE_TIMER de Arduino Duemilanove al timer 1.
 * Eso deberia permitir la compilacion.
 */

/**
 * Clase controlador del sensor infrarrojos.
 * Permite que la Arduino reciba señales de un mando a distancia.
 */
class Infrarrojos{
  //Valores que se pueden recibir del mando a distancia.
  #define CERO 16730805
  #define UNO 16738455
  #define DOS 16750695
  #define TRES 16756815
  #define CUATRO 16724175
  #define CINCO 16718055
  #define SEIS 16743045
  #define SIETE 16716015
  #define OCHO 16726215
  #define NUEVE 16734885

  private:
    //Pin al que se conecta el sensor de infrarrojos.
    byte PIN_INFRARROJOS;
    //Libreria que usaremos para decodificar los infrarrojos.
    IRrecv irrecv = IRrecv(255); //C++ obliga a poner un valor.
    //El pin 255 no existe, pero permite inicializar el objeto.

  public:
    //Constructor
    /**
     * Constructor del controlador.
     * 1. Pin input infrarrojos.
     *    Guarda el pin que se va a utilizar para recibir
     *    las señales del sensor infrarrojo.
     *    Si no se introduce ningun valor, se asignara un pin inaccesible.
     */
    Infrarrojos(byte = 255);
    //Destructor


    //Inicializador
    /**
     *
     */
    void inicializa();

    /**
     *
     */
    byte esperaMando();
};

#endif
