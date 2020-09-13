#include <robot.h>

Robot robotActual; //Nombre con el que guardaremos este objeto
void setup() {
  //Se elige el robot con el que estamos trabajando
  robotActual = arduino; //Pilas AA, cada una de 1.5V
  //robotActual = elegoo; //Pilas de 3.7V

  //Inicializamos el objeto
  robotActual.inicializa();


  //Hacemos una pequeña rutina para que el robot se mueva
  //Se mueve hacia alante un segundo
  robotActual.alante();
  delay(1000);
  //Rota a la dcha un segundo
  robotActual.rotaDcha();
  delay(1000);
  //Rota a la izda un segundo
  robotActual.rotaIzda();
  delay(1000);
  //Se mueve hacia atras un segundo
  robotActual.atras();
  delay(1000);
  //Se para
  robotActual.para();
  delay(1000);
}

void loop() {
  //Ahora rota a la derecha, luego a la izquierda, y luego se para, pero indefinidamente
  //Rota a la dcha un segundo
  robotActual.rotaDcha();
  delay(1000);
  //Rota a la izda un segundo
  robotActual.rotaIzda();
  delay(1000);
  //Se para
  robotActual.para();
  delay(1000);
}
