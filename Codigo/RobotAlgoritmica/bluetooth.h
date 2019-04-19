#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"

/**
 * 
 */
class Bluetooth{
  #define BAUDIOS_DEFECTO 9600
  private:
    int BAUDIOS;
    char START_CHAR;

  public:
    //Constructor
    /**
     * Constructor del módulo Bluetooth.
     */
    Bluetooth(int = BAUDIOS_DEFECTO, char  = 'x');
    //Destructor

    /** 
     * Inicializa el modulo Bluetooth para que pueda enviar datos 
     */
    void inicializa();

    /** 
     * Una vez este inicializado el modulo Bluetooth, tenemos 
     * que sincronizarlo con la aplicacion para que la Arduino reciba datos 
     */
    void sincroniza();
};
#endif
