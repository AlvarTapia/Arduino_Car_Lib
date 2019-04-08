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
  /*
  robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
  */
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
  robotActual.BLUETOOTH.sincronizaYEmpieza();
}

void loopInterseccion(){
  bool izda = robotActual.SIGUELINEAS.readIzda();
  bool centro = robotActual.SIGUELINEAS.readCentro();
  bool dcha = robotActual.SIGUELINEAS.readDcha();

  if(izda && centro && dcha){
    Serial.println("DESVIO");
    //Ahora ve todos los sensores con negro
    //Primera cinta
    //Espera hasta que a la dcha dejes de ver negro
    while(robotActual.SIGUELINEAS.readDcha()) {};
    //Ahora empieza a rotar
    robotActual.rotaIzda();
    //Espera hasta que a la dcha dejes de ver blanco
    while(!robotActual.SIGUELINEAS.readDcha()) {};
    Serial.println("Pasa primera cinta");
    //Segunda cinta
    //Espera hasta que a la dcha dejes de ver negro
    while(robotActual.SIGUELINEAS.readDcha()) {};
    //Espera hasta que a la dcha dejes de ver blanco
    while(!robotActual.SIGUELINEAS.readDcha()) {};
    Serial.println("Pasa segunda cinta");
    //Queremos seguir esta cinta
    //Por lo tanto, el giro esta completo. Control normal
    Serial.println("FIN DESVIO");
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
