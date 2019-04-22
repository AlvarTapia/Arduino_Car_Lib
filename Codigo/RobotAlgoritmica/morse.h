#ifndef morse_h
#define morse_h

#include "Arduino.h"

/**
 *
 */
class Morse{
  //
  #define DEFAULT_FREC_SIRENA 15000
  //
  #define TIEMPO_RAYA 300
  //
  #define TIEMPO_PUNTO 100
  //
  #define TIEMPO_ENTRE_SIMBOLOS 100

  private:
    //
    byte PIN_MORSE;
    //
    char DISPOSITIVO;
    //
    unsigned int FREC_SIRENA = DEFAULT_FREC_SIRENA;
  public:
    //Constructor
    /**
     *
     */
    Morse(byte = 255, char = 'x', int = DEFAULT_FREC_SIRENA);
    //Destructor


    //Inicializador
    /**
     *
     */
    void inicializa();

    //Funciones
    /**
     *
     */
    void raya();

    /**
     *
     */
    void punto();

    /**
     *
     */
    void sos();
};
#endif
