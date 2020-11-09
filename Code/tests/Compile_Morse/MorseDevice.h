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

const String MORSE_DEVICE_EXCEPTION = "MorseDevice not initialized correctly";

class MorseDevice{

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
    explicit MorseDevice(byte = INVALID_PIN);

    /**
     *
     */
    byte getDevicePin();

    /**
     *
     */
    String startSignaling();

    /**
     *
     */
    String stopSignaling();
};

class Led : public MorseDevice{
  public:
    explicit Led(byte = INVALID_PIN);

    String startSignaling();

    String stopSignaling();
};

class Siren : public MorseDevice{
  /// Frecuencia por defecto de la sirena, en hercios.
  #define DEFAULT_SIREN_FREC 18000

  private:
    /// Frecuencia a la que funcionara la sirena.
    unsigned int sirenFrec;

  public:
    explicit Siren(byte = INVALID_PIN, unsigned int = DEFAULT_SIREN_FREC);

    String startSignaling();

    String stopSignaling();
};


const MorseDevice noneDevice = MorseDevice();

#endif
