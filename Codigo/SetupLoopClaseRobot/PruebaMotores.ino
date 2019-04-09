void setupPruebaMotores() { };

void loopPruebaMotores(){
  robotActual.alante();
  delay(2000);
  robotActual.giraIzda();
  delay(1000);
  robotActual.giraDcha();
  delay(1000);
  
  robotActual.atras();
  delay(500);
  robotActual.rotaIzda();
  delay(1000);
  robotActual.rotaDcha();
  delay(1000);
  robotActual.para();
  delay(1000);
}
