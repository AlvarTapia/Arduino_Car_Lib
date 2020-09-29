/**
 * ----------------------------------------------------------------
 * Bluetooth.cpp
 * Clase controlador del modulo Bluetooth.
 * Permite que la Arduino pueda enviar y recibir mensajes.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef bluetooth_cpp
#define bluetooth_cpp

#include "Bluetooth.h"

//Constructor
Bluetooth::Bluetooth(int bauds, char startChar) {
  BAUDS = bauds;
  START_CHAR = startChar;
}
//Destructor
Bluetooth::~Bluetooth() {
  //No funciona como se espera.
  //A Abril 2019 se deja sin implementar.
  //if (Serial) Serial.end();
  //while(!Serial) {}; Serial.end();
}

//Inicializador
void Bluetooth::init() {
  Serial.begin(BAUDS);
  //Espera mientras no se puedan mandar/recibir mensajes
  while(!Serial){};
}

//Funciones
void Bluetooth::finish() {
  Serial.end();
}

void Bluetooth::send(String s) {
  Serial.print(s);
}

void Bluetooth::sendNewLine(String s) {
  Serial.println(s);
}

void Bluetooth::sync() {
  char xtart = 0;
  while (xtart != START_CHAR) {
    if ( Serial.available() ) {
      xtart = Serial.read();
      Serial.println("Char read");
    }
  }
  Serial.println("Synchronized!");
}

#endif
