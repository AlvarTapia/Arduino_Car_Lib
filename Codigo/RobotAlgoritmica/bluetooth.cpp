#ifndef bluetooth_cpp
#define bluetooth_cpp

#include "bluetooth.h"

//Constructor
Bluetooth::Bluetooth(int baudios, char startChar){
  BAUDIOS = baudios;
  START_CHAR = startChar;
}


void Bluetooth::inicializa(){
  Serial.begin(BAUDIOS);
}

void Bluetooth::sincroniza(){
  char xtart = 0;
  while(xtart != START_CHAR){
    if( Serial.available() ){
      xtart = Serial.read();
      Serial.println("Caracter leido");
    }
  }
  Serial.println("Sincronizados!");
}
#endif
