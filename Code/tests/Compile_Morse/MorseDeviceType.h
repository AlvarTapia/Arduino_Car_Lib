/**
 * ----------------------------------------------------------------
 * MorseDeviceType.h
 * Libreria que permite que la Arduino pueda enviar señales en Morse.
 * Necesita de un dispositivo que pueda cambiar notablemente de estado,
 * como un LED o una sirena.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef morsedevicetype_h
#define morsedevicetype_h

#include "Arduino.h"

class MorseDeviceType{

  #define INVALID_PIN 255

  protected:
    /**
     *
     */
    byte devicePin;

  public:
    /**
     *
     */
    MorseDeviceType(byte = INVALID_PIN);

    /**
     * 
     */
    byte getDevicePin();

    /**
     *
     */
    void startSignaling();

    /**
     *
     */
    void stopSignaling();
};

class Led : public MorseDeviceType{
  public:
    void startSignaling();

    void stopSignaling();
};

class Siren : public MorseDeviceType{
  /// Frecuencia por defecto de la sirena, en hercios.
  #define DEFAULT_SIREN_FREC 18000

  private:
    /// Frecuencia a la que funcionara la sirena.
    unsigned int sirenFrec;

  public:
    Siren(byte = INVALID_PIN, unsigned int = DEFAULT_SIREN_FREC);

    void startSignaling();

    void stopSignaling();
};


const MorseDeviceType noneDevice = MorseDeviceType();

#endif
