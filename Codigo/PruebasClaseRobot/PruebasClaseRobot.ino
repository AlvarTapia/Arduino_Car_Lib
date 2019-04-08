#include "robot.h"
Robot robotActual = elegoo;//arduino;


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
  Serial.begin(9600); //Bluetooth
  setupInterseccion();
}

void loop(){
  loopInterseccion();
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


void setupInterseccion(){
  //robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
}

void loopInterseccion(){
  bool izda = robotActual.SIGUELINEAS.readIzda();
  bool centro = robotActual.SIGUELINEAS.readCentro();
  bool dcha = robotActual.SIGUELINEAS.readDcha();

  if(izda && centro && dcha){
    Serial.println("Desvio");
    robotActual.para();
    delay(500);
    //Rota hasta que solo vea negro el sensor de la dcha
    robotActual.rotaIzda();
    Serial.println("Esperando solo dcha");
    while(robotActual.SIGUELINEAS.readIzda() || robotActual.SIGUELINEAS.readCentro() || !robotActual.SIGUELINEAS.readDcha()) {};
    //Alante hasta que solo vea negro el sensor de la izda
    robotActual.alante();
    Serial.println("Esperando solo izda");
    while(!robotActual.SIGUELINEAS.readIzda() || robotActual.SIGUELINEAS.readCentro() || robotActual.SIGUELINEAS.readDcha()) {};
    //Rota a la izda hasta que vea negro el sensor del centro
    robotActual.rotaIzda();
    Serial.println("Esperando centro");
    while(!robotActual.SIGUELINEAS.readCentro()) {};
    //Ya enderezado, continua con el programa
    Serial.println("FIN DESVIO");
  }else if(izda){
    //Serial.println("Giro izda");
    robotActual.rotaIzda();
  }else if(dcha){
    //Serial.println("Giro dcha");
    robotActual.rotaDcha();
  }else if(centro){
    //Serial.println("Todo recto");
    robotActual.alante();
  }else{
    //Serial.println("Quieto");
    robotActual.para();
  }
}
