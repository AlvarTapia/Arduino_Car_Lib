Robot robotActual = elegoo;


void setupPruebaMotores();
void loopPruebaMotores();
void setupPruebaRotacion();
void loopPruebaRotacion();
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


void setupPruebaRotacion(){
}

void loopPruebaRotacion(){
  robotActual.alante();
  delay(2000);
  robotActual.giraIzda();
  delay(2000);
}


//bool yendoDcha, yendoCentro, yendoIzda;

void setupPruebaSensores(){
  //robotActual.setTodosSiguelineas(A0, A2, A4); //ARDUINO
  robotActual.setTodosSiguelineas(A0, A2, A4); //ELEGOO
  
  robotActual.alante();
}


void loopPruebaSensores(){
  if(robotActual.readSiguelineasCentro()){
    robotActual.alante();
  }else if(robotActual.readSiguelineasDcha()){
    robotActual.rotaDcha();
  }else if(robotActual.readSiguelineasIzda()){
    robotActual.rotaIzda();
  }else{
    robotActual.atras();
  }
}

