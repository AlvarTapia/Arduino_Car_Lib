
void setupInterseccion(){
  //robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
  robotActual.BLUETOOTH = Bluetooth(BAUDIOS_DEFECTO);
}

void loopInterseccion(){
  bool izda = robotActual.SIGUELINEAS.readIzda();
  bool centro = robotActual.SIGUELINEAS.readCentro();
  bool dcha = robotActual.SIGUELINEAS.readDcha();

  if(izda && centro && dcha){
    Serial.println("DESVIO");
    //Ahora ve todos los sensores con negro
    //Pasa esta cinta
    robotActual.alante();
    //Primera cinta
    //Espera hasta que a la dcha dejes de ver negro
    while(robotActual.SIGUELINEAS.readDcha()) {};
    //Ahora empieza a rotar
    robotActual.rotaIzda();
    //Espera hasta que a la dcha dejes de ver blanco
    while(!robotActual.SIGUELINEAS.readDcha()) {};
    Serial.println("Pasa primera cinta");
    //Segunda cinta
    //Espera hasta que a la dcha dejes de ver negro
    while(robotActual.SIGUELINEAS.readDcha()) {};
    //Espera hasta que a la dcha dejes de ver blanco
    while(!robotActual.SIGUELINEAS.readDcha()) {};
    Serial.println("Pasa segunda cinta");
    //Queremos seguir esta cinta
    //Por lo tanto, el giro esta completo. Control normal
    Serial.println("FIN DESVIO");
  }else if(izda){
    robotActual.rotaIzda();
  }else if(dcha){
    robotActual.rotaDcha();
  }else if(centro){
    robotActual.alante();
  }else{
    robotActual.para();
  }
}
