void setup(){
  arduino.arranca();
}

void loop(){
  arduino.alante();
  arduino.lento();
  delay(2000);
  arduino.giraIzda();
  delay(1000);
  arduino.giraDcha();
  delay(1000);
  
  arduino.atras();
  arduino.arranca();
  arduino.maxVelocidad();//No pivota bien en "lento"
  delay(500);
  arduino.rotaIzda();
  delay(1000);
  arduino.rotaDcha();
  delay(1000);
}
