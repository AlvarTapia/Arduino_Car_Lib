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
  #define NO_READ 0xFF
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
    /// Pin al que se conecta el sensor de infrarrojos.
    byte INFRARED_PIN;
    /// Libreria que usaremos para decodificar los infrarrojos.
    IRrecv irrecv = IRrecv(255); //C++ obliga a poner un valor.
    //El pin 255 no existe, pero permite inicializar el objeto.

    int NUM_DIGITS = 10
    int codeToDigit[NUM_DIGITS] =
      [ CERO, UNO, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, OCHO, NUEVE ];


    byte redToDigit(unsigned long redCode){
      return redToDigitArray(redCode);
    }


    byte redToDigitArray(unsigned long redCode){
      for(int i=0; i<NUM_DIGITS; i++){
        if( codeToDigit[i] == redCode ){
          return i;
        }
      }
      return NO_READ;
    }

    /** DEPRECATED */
    byte redToDigitSwitch(unsigned long redCode){
      digit = NO_READ;
      switch (redCode) {
        case CERO:
          digit = 0;
          break;
        case UNO:
          digit = 1;
          break;
        case DOS:
          digit = 2;
          break;
        case TRES:
          digit = 3;
          break;
        case CUATRO:
          digit = 4;
          break;
        case CINCO:
          digit = 5;
          break;
        case SEIS:
          digit = 6;
          break;
        case SIETE:
          digit = 7;
          break;
        case OCHO:
          digit = 8;
          break;
        case NUEVE:
          digit = 9;
          break;
      }
      return digit;
    }
    
    /** DEPRECATED */
    byte redToDigitSwitchNoBreaks(unsigned long redCode){
      digit = 0;
      switch (redCode) {
        case NUEVE:
          digit++;
        case OCHO:
          digit++;
        case SIETE:
          digit++;
        case SEIS:
          digit++;
        case CINCO:
          digit++;
        case CUATRO:
          digit++;
        case TRES:
          digit++;
        case DOS:
          digit++;
        case UNO:
          digit++;
        case CERO:
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
    Infrarrojos(byte = 255);
    //Destructor


    //Inicializador
    /**
     * Permite al pin establecido en el constructor
     * recibir la informacion del sensor.
     */
    void inicializa();

    /**
     * La Arduino no realiza ninguna otra instruccion hasta
     * que reciba un numero valido del mando infrarrojo.
     * @return Numero recibido del mando.
     */
    byte esperaMando();
};

#endif
