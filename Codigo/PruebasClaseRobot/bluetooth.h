#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"


class Bluetooth{
  #define BAUDIOS_DEFECTO 9600
  private:
    int BAUDIOS;

  public:
    //Constructores
    Bluetooth(int baudios = BAUDIOS_DEFECTO){
      BAUDIOS = baudios;
      Serial.begin(BAUDIOS);
      while(!Serial){ }; //Espera a que el Serial este activo
    }
    //Destructor
    

    void sincronizaYEmpieza(){
      Serial.println("Buscando input");
      while(Serial.available() <= 0) {Serial.println("Checkeando available");};
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
