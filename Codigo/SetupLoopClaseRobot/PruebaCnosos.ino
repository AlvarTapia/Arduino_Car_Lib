#include "Cnosos.h"
void setupCnosos(){
  robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4);//Arduino
  robotActual.MORSE = Morse(4, 's');//Arduino
  //robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
  //robotActual.MORSE = Morse(13, 'l');//ELEGOO
  
  robotActual.inicializa();
  robotActual.SIGUELINEAS.inicializa();
  robotActual.MORSE.inicializa();
  
  Cnosos c = Cnosos(robotActual);
  byte numero = c.lee_numero();
  c.luce_numero(numero);
}

void loopCnosos(){
  
}
