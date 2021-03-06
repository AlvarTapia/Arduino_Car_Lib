void setupInterseccion(){
  robotActual.inicializa();
  robotActual.SIGUELINEAS = Siguelineas(A0, A2, A4); //ARDUINO
  //robotActual.SIGUELINEAS = Siguelineas(10, 4, 2); //ELEGOO
  robotActual.SIGUELINEAS.inicializa();
  robotActual.BLUETOOTH.inicializa();
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
    //Espera hasta que a la izda dejes de ver negro
    Serial.println("Izda lee negro");
    while(robotActual.SIGUELINEAS.readIzda()) {
      Serial.println(robotActual.SIGUELINEAS.readIzda() ? "1" : "0");
      Serial.println(robotActual.SIGUELINEAS.readCentro() ? "1" : "0");
      Serial.println(robotActual.SIGUELINEAS.readDcha() ? "1" : "0");
      Serial.println(".");
    };
    //Ahora empieza a rotar
    robotActual.giraIzda();
    //Espera hasta que a la izda dejes de ver blanco
    Serial.println("Izda lee blanco");
    long i = 0;
    while(!robotActual.SIGUELINEAS.readIzda()) {
      //Reduce los mensajes para no saturar la aplicacion
      if(i % 100){
        Serial.println(robotActual.SIGUELINEAS.readIzda() ? "1" : "0");
        Serial.println(robotActual.SIGUELINEAS.readCentro() ? "1" : "0");
        Serial.println(robotActual.SIGUELINEAS.readDcha() ? "1" : "0");
        Serial.println(".");
      }
    };
    //Queremos seguir esta cinta
    //Por lo tanto, el giro esta completo. Control normal
    Serial.println("FIN DESVIO");
  }else if(izda){
    robotActual.giraIzda();
  }else if(dcha){
    robotActual.giraDcha();
  }else if(centro){
    robotActual.alante();
  }else{
    robotActual.para();
  }
}
