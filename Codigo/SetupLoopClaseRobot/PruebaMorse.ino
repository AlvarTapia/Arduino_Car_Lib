void setupMorse(){
  //robotActual.inicializa(); //No hace falta inicializar los motores
  robotActual.MORSE = Morse(4, 's');
  robotActual.MORSE.inicializa();
  robotActual.MORSE.sos();
}
