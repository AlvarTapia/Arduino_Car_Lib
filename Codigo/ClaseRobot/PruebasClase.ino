Robot robotActual = elegoo;


void setupPruebaMotores();
void loopPruebaMotores();
void setupPruebaSensores();
void loopPruebaSensores();



void setup(){
  setupPruebaSensores();
}

void loop(){
  loopPruebaSensores();
}





void setupPruebaMotores(){
  robotActual.arranca();
}

void loopPruebaMotores(){
  robotActual.alante();
  robotActual.lento();
  delay(2000);
  robotActual.giraIzda();
  delay(1000);
  robotActual.giraDcha();
  delay(1000);
  
  robotActual.atras();
  robotActual.arranca();
  robotActual.maxVelocidad();//No pivota bien en "lento"
  delay(500);
  robotActual.rotaIzda();
  delay(1000);
  robotActual.rotaDcha();
  delay(1000);
}


void setupPruebaSensores(){
  robotActual.setTodosSiguelineas(A0, A2, A4);
  robotActual.arranca();
  robotActual.lento();
}

void loopPruebaSensores(){
  robotActual.rotaDcha();
  delay(1000);
  robotActual.rotaIzda();
  delay(5000);
}
