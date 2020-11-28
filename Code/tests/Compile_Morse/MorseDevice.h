/**
 * ----------------------------------------------------------------
 * MorseDevice.h
 * Libreria que permite que la Arduino pueda enviar señales en Morse.
 * Necesita de un dispositivo que pueda cambiar notablemente de estado,
 * como un LED o una sirena.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef morsedevice_h
#define morsedevice_h

#include "Arduino.h"

class MorseDevice{
  protected:

    /**
     *
     */
    byte devicePin;

  public:
    static const String MD_EXCEPTION;
    static const byte INVALID_PIN = 255;
    /**
     *
     */
    MorseDevice(byte = INVALID_PIN);

    /**
     *
     */
    byte getDevicePin();

    /**
     *
     */
    virtual String startSignaling();

    /**
     *
     */
    virtual String stopSignaling();
};

class Led : public MorseDevice{
  public:
    Led(byte = INVALID_PIN);

    String startSignaling();

    String stopSignaling();
};

class Siren : public MorseDevice{
  protected:
    /// Frecuencia a la que funcionara la sirena.
    unsigned int sirenFrec;

  public:
    /// Frecuencia por defecto de la sirena, en hercios.
    const static unsigned int DEFAULT_SIREN_FREC = 18000;

    Siren(byte = INVALID_PIN, unsigned int = DEFAULT_SIREN_FREC);

    String startSignaling();

    String stopSignaling();
};


const MorseDevice noneDevice = MorseDevice();

#endif
