#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"


class Bluetooth{
  #define BAUDIOS_DEFECTO 9600
  private:
    int BAUDIOS;
    char START_CHAR;

  public:
    //Constructor    
    Bluetooth(int baudios = BAUDIOS_DEFECTO, char startChar = 'x'){
      BAUDIOS = baudios;
      START_CHAR = startChar;
      
      //while(!Serial){ }; //Espera a que el Serial este activo
      //Ya se activo el Serial, puede continuar
    }
    //Destructor
    

    /** Una vez este inicializado el modulo de Bluetooth, tenemos que sincronizarlo con la aplicacion */
    void sincroniza(){
      Serial.begin(BAUDIOS);
      char xtart = 0;
      while(xtart != START_CHAR){
        if( Serial.available() ){
          xtart = Serial.read();
          Serial.println("Caracter leido");
        }
      }
      Serial.println("Sincronizados!");
    }
};
#endif

/*
void setup()
{ 
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
}
void loop(){ 
  getstr=Serial.read();
  if(getstr=='f'){
    _mForward();
  } else if(getstr=='b'){
    _mBack();
    delay(200);
  } else if(getstr=='l'){
    _mleft();
    delay(200);
  } else if(getstr=='r'){
    _mright();
    delay(200);
  } else if(getstr=='s'){
    _mStop();     
  } else if(getstr=='A'){
    stateChange();
  }
}
*/
