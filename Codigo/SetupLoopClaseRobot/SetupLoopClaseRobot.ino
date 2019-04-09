
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
  setupInterseccion();
}

void loop(){
  loopInterseccion();  
}
