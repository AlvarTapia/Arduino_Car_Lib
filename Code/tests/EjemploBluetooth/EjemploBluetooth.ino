#include <bluetooth.h>

Bluetooth bt; //Nombre con el que guardaremos este objeto

void setup() {
  //Instancia el objeto a 9600 baudios y con 'x' como caracter de sincronizacion
  bt = Bluetooth(9600, 'x');

  //Inicializa el objeto para que pueda recibir/transmitir informacion
  bt.inicializa();
}

void loop() {
  //Envia una linea 
  bt.enviaLinea("Esperando input...");
  //Espera 1 segundo despues de enviar esa linea
  delay(1000);

  //Si se ha recibido alguna informacion
  if(Serial.available()){
    //Inicia el metodo sincroniza
    bt.sincroniza();
  }
  //Sino, se repite el loop
}
