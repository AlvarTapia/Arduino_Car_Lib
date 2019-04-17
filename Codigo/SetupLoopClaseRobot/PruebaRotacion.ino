void setupPruebaRotacion(){
  robotActual.inicializa();
}

void loopPruebaRotacion(){
  robotActual.alante();
  delay(2000);
  robotActual.giraIzda();
  delay(2000);
}
