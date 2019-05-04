/**
 * ----------------------------------------------------------------
 * bluetooth.cpp
 * Clase controlador del modulo Bluetooth.
 * Permite que la Arduino pueda enviar y recibir mensajes.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef bluetooth_cpp
#define bluetooth_cpp

#include "bluetooth.h"

//Constructor
Bluetooth::Bluetooth(int baudios, char startChar) {
  BAUDIOS = baudios;
  START_CHAR = startChar;
}
//Destructor
Bluetooth::~Bluetooth() {
  //No funciona como se espera, a Abril 2019 se deja sin implementar
  //if (Serial) Serial.end();
}

//Inicializador
void Bluetooth::inicializa() {
  Serial.begin(BAUDIOS);
  while(!Serial){}; //Espera mientras no se puedan mandar/recibir mensajes
}

//Funciones
void Bluetooth::finaliza() {
  Serial.end();
}

void Bluetooth::envia(String s) {
  Serial.print(s);
}

void Bluetooth::enviaLinea(String s) {
  Serial.println(s);
}

void Bluetooth::sincroniza() {
  char xtart = 0;
  while (xtart != START_CHAR) {
    if ( Serial.available() ) {
      xtart = Serial.read();
      Serial.println("Caracter leido");
    }
  }
  Serial.println("Sincronizados!");
}

#endif
