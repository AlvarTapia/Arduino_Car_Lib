Robot robotActual = arduino;


void setupPruebaMotores();
void loopPruebaMotores();
void setupPruebaRotacion();
void loopPruebaRotacion();
void setupPruebaSensores();
void loopPruebaSensores();



void setup(){
  setupPruebaRotacion();
}

void loop(){
  loopPruebaRotacion();
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


void setupPruebaRotacion(){
  robotActual.setTodosSiguelineas(A0, A2, A4);
}

void loopPruebaRotacion(){
  robotActual.alante();
  delay(2000);
  robotActual.giraIzda();
  delay(2000);
  
  /*
  robotActual.rotaDcha();
  delay(1000);
  robotActual.rotaIzda();
  delay(5000);
  */
}
