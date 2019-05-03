#include "Cnosos.h"

Robot robotActual;
Siguelineas siguelineas;
Morse morse;

Cnosos cn;
void setup(){
  
  //Arduino
  robotActual = arduino;

  siguelineas = Siguelineas(A0, A2, A4);
  morse = Morse(4, 's');
  
  /*
  //Elegoo
  robotActual = elegoo;

  siguelineas = Siguelineas(10, 4, 2);
  morse = Morse(13, 'l'); 
  */
  
  robotActual.SIGUELINEAS = siguelineas;
  robotActual.MORSE = morse;

  robotActual.inicializa();
  robotActual.SIGUELINEAS.inicializa();
  //robotActual.MORSE.inicializa();
  robotActual.BLUETOOTH.inicializa();

  
  cn = Cnosos(robotActual);
  //robotActual.BLUETOOTH.sincroniza();
  //delay(20000);
  if(cn.siguiente() == 1){
    cn.sal_aqui();
    robotActual.para();
  }
}

void loop(){
  
}
