
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
  robotActual.inicializa();
  setupInterseccion();
}

void loop(){
  loopInterseccion();  
}
