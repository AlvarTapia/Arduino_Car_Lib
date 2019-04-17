//bool yendoDcha, yendoCentro, yendoIzda;

void setupPruebaSensores(){
  robotActual.inicializa();
  //robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  //robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
  robotActual.SIGUELINEAS.inicializa();
}


void loopPruebaSensores(){
  if(robotActual.SIGUELINEAS.readCentro()){
    robotActual.alante();
  }else if(robotActual.SIGUELINEAS.readDcha()){
    robotActual.rotaDcha();
  }else if(robotActual.SIGUELINEAS.readIzda()){
    robotActual.rotaIzda();
  }else{
    robotActual.atras();
  }
}
