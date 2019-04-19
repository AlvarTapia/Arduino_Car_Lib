#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"

/**
 * Clase controlador del modulo Bluetooth.
 * Permite que la Arduino pueda enviar y recibir mensajes.
 */
class Bluetooth{
  #define BAUDIOS_DEFECTO 9600
  private:
    //Señales por segundo a la que se establece la comunicacion.
    int BAUDIOS;
    //Caracter de sincronizacion.
    char START_CHAR;

  public:
    //Constructor
    /**
     * Constructor del controlador.
     * 1. Baudios.
     *    Señales por segundo de la comunicacion.
     *    Por defecto, Bluetooth se comunica a 9600 baudios.
     * 2. Caracter de sincronizacion.
     *    Si se utiliza el metodo inicializa(), se esperara
     *    este caracter para seguir con el codigo.
     */
    Bluetooth(int = BAUDIOS_DEFECTO, char  = 'x');
    //Destructor
    /**
     * Si el objeto se ha inicializado, al eliminarlo
     * se finaliza la conexion.
     */
    ~Bluetooth();

    //Inicializador
    /**
     * Inicializa las conexiones de la Arduino para que pueda
     * enviar datos a otro dispositivo.
     */
    void inicializa();

    //Funciones
    /**
     * Desactiva la comunicacion de la Arduino
     * con otros dispositivos.
     */
    void finaliza();

    /**
     * La Arduino envia un String a otro dispositivo
     * (sin retorno de carro).
     */
    void envia(String);

    /**
     * La Arduino envia un String a otro dispositivo
     * e introduce un retorno de carro al final.
     */
    void enviaLinea(String);

    /**
     * La Arduino esperara al caracter de
     * sincronizacion (definido en el constructor)
     * antes de ejecutar mas instrucciones.
     */
    void sincroniza();
};
#endif
