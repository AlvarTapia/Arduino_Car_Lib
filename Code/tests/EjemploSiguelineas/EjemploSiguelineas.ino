#include <robot.h>
#include <siguelineas.h>

Robot robotActual; //Nombre del objeto que vamos a usar

void setup(){
  //Se elige el robot con el que estamos trabajando
  robotActual = arduino; //Pilas AA, cada una de 1.5V
  //robotActual = elegoo; //Pilas de 3.7V

  //Se establece tambien el modulo siguelineas
  robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  //robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
  
  //Y se inicializan los objetos
  robotActual.inicializa();
  robotActual.SIGUELINEAS.inicializa();
}


void loop(){
  //Algoritmo que sigue una linea, incluso si esta torcida/girada
  //No puede "saltarse huecos" en la cinta
  
  if(robotActual.SIGUELINEAS.readCentro()){ //Si el siguelineas del centro lee una linea:
    robotActual.alante(); //Sigue recto, vas bien
  }else if(robotActual.SIGUELINEAS.readDcha()){ //Sino, si el siguelineas de la derecha lee una linea:
    robotActual.rotaDcha(); //Rota a la dcha para volver a la linea
  }else if(robotActual.SIGUELINEAS.readIzda()){ //Sino, si el siguelineas de la izquierda lee una linea:
    robotActual.rotaIzda(); //Rota a la izquierda para volver a la linea
  }else{  //Si no se leen lineas debajo de los sensores:
    robotActual.atras(); //Te has pasado, retrocede
  }
  //Se repite indefinidamente
}
