Robot robotActual = arduino;


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


bool yendoDcha, yendoCentro, yendoIzda;

void setupPruebaSensores(){
  robotActual.setTodosSiguelineas(A0, A2, A4);
  robotActual.alante();
  yendoDcha = false;
  yendoCentro = false;
  yendoIzda = false;
}


void loopPruebaSensores(){
  if(!robotActual.readSiguelineasCentro()){
    if(!yendoCentro){
      robotActual.alante();
      yendoCentro = true;
    }
  }else if(robotActual.readSiguelineasDcha()){
    yendoCentro = false;
    robotActual.rotaDcha();
  }else if(robotActual.readSiguelineasIzda()){
    yendoCentro = false;
    robotActual.rotaIzda();
  }else{
    yendoCentro = false;
    robotActual.atras();
  }
}

