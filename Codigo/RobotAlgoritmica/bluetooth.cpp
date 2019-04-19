#ifndef bluetooth_cpp
#define bluetooth_cpp

#include "bluetooth.h"

//Constructor
Bluetooth::Bluetooth(int baudios, char startChar){
  BAUDIOS = baudios;
  START_CHAR = startChar;
}
//Destructor
Bluetooth::~Bluetooth(){
  if(Serial){
    Serial.end();
  }
}

//Inicializador
void Bluetooth::inicializa(){
  Serial.begin(BAUDIOS);
}

//Funciones
void Bluetooth::finaliza(){
  Serial.end();
}

void Bluetooth::sincroniza(){
  char xtart = 0;
  while(xtart != START_CHAR){
    if( Serial.available() ){
      xtart = Serial.read();
      Serial.println("Char leido");
    }
  }
  Serial.println("Sincronizados!");
}


#endif
