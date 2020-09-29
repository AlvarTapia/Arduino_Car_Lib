/**
 * ----------------------------------------------------------------
 * MorseDeviceType.cpp
 * Libreria que permite que la Arduino pueda enviar señales en Morse.
 * Necesita de un dispositivo que pueda cambiar notablemente de estado,
 * como un LED o una sirena.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef morsedevicetype_cpp
#define morsedevicetype_cpp

#include "MorseDeviceType.h"

class NoneDevice : public MorseDeviceType{};

class Led : public MorseDeviceType{

};

class Siren : public MorseDeviceType{
  /// Frecuencia por defecto de la sirena, en hercios.
  #define DEFAULT_SIREN_FREC 18000
  
  private:
    /// Frecuencia a la que funcionara la sirena.
    unsigned int sirenFrec;
};


#endif
