/**
 * ----------------------------------------------------------------
 * infrared.h
 * Clase controlador del sensor infrarrojos.
 * Permite que la Arduino reciba señales de un mando a distancia.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef infrared_h
#define infrared_h

#include <RobotIRremote.h>
#include <RobotIRremoteInt.h>
#include <RobotIRremoteTools.h>

#include "Arduino.h"

/*
 * IMPORTANTE
 * La libreria RobotIRremote.h puede causar conflictos.
 * Esta ubicada en C:/Program Files (x86)/Arduino/libraries/RobotIRremote en Windows,
 * y en /usr/share/arduino/libraries en Linux
 *
 * En primer lugar, RobotIRremoteTools.h y IRremoteTools.cpp no se van a usar.
 * Si causan problemas, borrar esos archivos es una solucion.
 *
 * Si la funcion tone() y la libreria RobotIRremote causan problemas,
 * se recomienda abrir el archivo RobotIRremoteInt.h y
 * cambiar el IR_USE_TIMER de Arduino Duemilanove al timer 1.
 * Eso deberia permitir la compilacion.
 */

class Infrared{
  /// Valores que se pueden recibir del mando a distancia.
  static const byte NO_RED_READ = (-1);
  static const unsigned long RED_ZERO = 16730805;
  static const unsigned long RED_ONE = 16738455;
  static const unsigned long RED_TWO = 16750695;
  static const unsigned long RED_THREE = 16756815;
  static const unsigned long RED_FOUR = 16724175;
  static const unsigned long RED_FIVE = 16718055;
  static const unsigned long RED_SIX = 16743045;
  static const unsigned long RED_SEVEN = 16716015;
  static const unsigned long RED_EIGHT = 16726215;
  static const unsigned long RED_NINE = 16734885;
  
  static const int NUM_RED_DIGITS = 10;
  
  static const unsigned long codeToDigit[NUM_RED_DIGITS] = 
    {RED_ZERO, RED_ONE, RED_TWO, RED_THREE, RED_FOUR, RED_FIVE, RED_SIX, RED_SEVEN, RED_EIGHT, RED_NINE};
  
  private:
    /// Pin al que se conecta el sensor de infrarrojos.
    byte INFRARED_PIN;
    /// Libreria que usaremos para decodificar los infrarrojos.
    IRrecv irrecv = IRrecv(255); //C++ obliga a poner un valor.
    //El pin 255 no existe, pero permite inicializar el objeto.


    byte redToDigitArray(unsigned long redCode){
      for(int i=0; i<NUM_RED_DIGITS; i++){
        if( codeToDigit[i] == redCode ){
          return i;
        }
      }
      return NO_RED_READ;
    }

    /** DEPRECATED */
    byte redToDigitSwitch(unsigned long redCode){
      byte digit = NO_RED_READ;
      switch (redCode) {
        case RED_ZERO:
          digit = 0;
          break;
        case RED_ONE:
          digit = 1;
          break;
        case RED_TWO:
          digit = 2;
          break;
        case RED_THREE:
          digit = 3;
          break;
        case RED_FOUR:
          digit = 4;
          break;
        case RED_FIVE:
          digit = 5;
          break;
        case RED_SIX:
          digit = 6;
          break;
        case RED_SEVEN:
          digit = 7;
          break;
        case RED_EIGHT:
          digit = 8;
          break;
        case RED_NINE:
          digit = 9;
          break;
      }
      return digit;
    }

    /** DEPRECATED */
    byte redToDigitSwitchNoBreaks(unsigned long redCode){
      byte digit = 0;
      switch (redCode) {
        case RED_NINE:
          digit++;
        case RED_EIGHT:
          digit++;
        case RED_SEVEN:
          digit++;
        case RED_SIX:
          digit++;
        case RED_FIVE:
          digit++;
        case RED_FOUR:
          digit++;
        case RED_THREE:
          digit++;
        case RED_TWO:
          digit++;
        case RED_ONE:
          digit++;
        case RED_ZERO:
          break;
        default:
          digit = 0xFF;
          break;
      }
      return digit;
    }

  public:
    //Constructor
    /**
     * Constructor del controlador infrarrojo.
     * @param Pin input infrarrojos
     *    Guarda el pin que se va a utilizar para recibir
     *    las señales del sensor infrarrojo.
     *    Por defecto, se asignara un pin inaccesible.
     */
    Infrared(byte = 255);
    //Destructor


    //Inicializador
    /**
     * Permite al pin establecido en el constructor
     * recibir la informacion del sensor.
     */
    void init();

    /**
     * La Arduino no realiza ninguna otra instruccion hasta
     * que reciba un numero valido del mando infrarrojo.
     * @return Numero recibido del mando.
     */
    byte waitForRedSignal();

    byte redToDigit(unsigned long redCode){
      return redToDigitArray(redCode);
    }
};

#endif
