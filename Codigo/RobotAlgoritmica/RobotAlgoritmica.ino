#include "Cnosos.h"

Robot robotActual;
Cnosos cn;
void setup(){
  robotActual = arduino;
  //robotActual = elegoo;

  //Arduino
  Siguelineas siguelineas = Siguelineas(A0, A2, A4);
  //Morse morse = Morse(4, 's');

  //Elegoo
  //Siguelineas siguelineas = Siguelineas(10, 4, 2);
  //Morse morse = Morse(13, 'l'); 
  
  robotActual.SIGUELINEAS = siguelineas;
  //robotActual.MORSE = morse;
  robotActual.BLUETOOTH = Bluetooth();

  
  robotActual.inicializa();
  robotActual.SIGUELINEAS.inicializa();
  //robotActual.MORSE.inicializa();
  robotActual.BLUETOOTH.inicializa();
    

  cn = Cnosos(robotActual);
  cn.luce_numero(cn.lee_numero());
}

void loop(){
}
