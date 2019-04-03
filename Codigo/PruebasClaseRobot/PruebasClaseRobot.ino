#include "robot.h"
Robot robotActual = arduino;//elegoo;


void setupPruebaMotores();
void loopPruebaMotores();

void setupPruebaRotacion();
void loopPruebaRotacion();

void setupPruebaSensores();
void loopPruebaSensores();

void setupMorse();

void setupInterseccion();
void loopInterseccion();



void setup(){
  setupInterseccion();
}

void loop(){
  loopInterseccion();
  //robotActual.rotaDcha(255);
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


void setupMorse(){
  robotActual.MORSE = Morse(4, 's');
  robotActual.MORSE.sos();
}



//bool yendoDcha, yendoCentro, yendoIzda;

void setupPruebaSensores(){
  robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  //robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
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


void setupInterseccion(){
  robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  //robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
}

void loopInterseccion(){
  bool izda = robotActual.SIGUELINEAS.readIzda();
  bool centro = robotActual.SIGUELINEAS.readCentro();
  bool dcha = robotActual.SIGUELINEAS.readDcha();

  if(izda && centro && !dcha){
     //Pasate el desvio
    robotActual.alante();
    while(robotActual.SIGUELINEAS.readIzda()){};
    //Ahora rota hacia el desvio
    robotActual.rotaIzda();
    //Espera no encontrar lineas negras
    while(robotActual.SIGUELINEAS.readIzda() || robotActual.SIGUELINEAS.readCentro() || robotActual.SIGUELINEAS.readDcha()) {};
    //Hasta que no encuentres negro solo a la derecha, sigue girando
    while(robotActual.SIGUELINEAS.readIzda() || robotActual.SIGUELINEAS.readCentro() || !robotActual.SIGUELINEAS.readDcha()) {};
    //Sigue adelante mientras leas blanco a la izquierda
    robotActual.alante();
    while(!robotActual.SIGUELINEAS.readIzda()) {};
    //Acaba de enderezar hasta que no haya negro a la izquierda
    robotActual.rotaIzda();
    while(robotActual.SIGUELINEAS.readIzda()) {};
  }else if(izda){
    robotActual.rotaIzda();
  }else if(dcha){
    robotActual.rotaDcha();
  }else if(centro){
    robotActual.alante();
  }else{
    robotActual.para();
  }
}
