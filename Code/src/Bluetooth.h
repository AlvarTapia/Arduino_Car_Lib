/**
 * ----------------------------------------------------------------
 * Bluetooth.h
 * Clase controlador del modulo Bluetooth.
 * Permite que la Arduino pueda enviar y recibir mensajes.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"


class Bluetooth{
  #define DEFAULT_BAUDS 9600
  private:
    /// Señales por segundo a la que se establece la comunicacion.
    int BAUDS;
    /// Caracter de sincronizacion.
    char START_CHAR;

  public:
    //Constructor
    /**
     * Constructor del controlador.
     * @param Baudios
     *    Señales por segundo de la comunicacion.
     *    Por defecto, Bluetooth se comunica a 9600 baudios.
     * @param Caracter de sincronizacion
     *    Si se utiliza el metodo init(), se esperara
     *    este caracter para seguir con el codigo.
     *    Por defecto, sera el caracter 'x'.
     */
    Bluetooth(int = DEFAULT_BAUDS, char = 'x');
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
    void init();

    //Funciones
    /**
     * Desactiva la comunicacion de la Arduino
     * con otros dispositivos.
     */
    void finish();

    /**
     * La Arduino envia un String a otro dispositivo
     * (sin retorno de carro).
     * @param String con la informacion a enviar.
     */
    void send(String);

    /**
     * La Arduino envia un String a otro dispositivo
     * e introduce un retorno de carro al final.
     * @param String con la informacion a enviar.
     */
    void sendNewLine(String);

    /**
     * La Arduino esperara al caracter de
     * sincronizacion (definido en el constructor)
     * antes de ejecutar mas instrucciones.
     */
    void sync();
};

#endif
