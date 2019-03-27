#include "robot.h"
Robot robotActual = arduino;//elegoo;


void setupPruebaMotores();
void loopPruebaMotores();
void setupPruebaRotacion();
void loopPruebaRotacion();
void setupPruebaSensores();
void loopPruebaSensores();



void setup(){
  //setupPruebaSensores();
  setupPruebaMotores();
}

void loop(){
  //loopPruebaSensores();
  loopPruebaMotores();
}





void setupPruebaMotores(){
}

void loopPruebaMotores(){
  robotActual.alante();
  delay(2000);
  robotActual.giraIzda();
  delay(1000);
  robotActual.giraDcha();
  delay(1000);
  
  robotActual.atras();
  delay(500);
  robotActual.rotaIzda();
  delay(1000);
  robotActual.rotaDcha();
  delay(1000);
  robotActual.para();
  delay(1000);
}


void setupPruebaRotacion(){
}

void loopPruebaRotacion(){
  robotActual.alante();
  delay(2000);
  robotActual.giraIzda();
  delay(2000);
}


//bool yendoDcha, yendoCentro, yendoIzda;

void setupPruebaSensores(){
  //robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
}


void loopPruebaSensores(){
  if(robotActual.SIGUELINEAS.readCentro()){
    robotActual.alante();
  }else if(robotActual.SIGUELINEAS.readDcha()){
    robotActual.rotaDcha();
  }else if(robotActual.SIGUELINEAS.readIzda()){
    robotActual.rotaIzda();
  }else{
    robotActual.atras();
  }
}
