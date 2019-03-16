void setup(){
  arduino.alante();
  arduino.arranca();
}

void loop(){
  arduino.lento();
  delay(3000);
  arduino.maxVelocidad();
  delay(500);
}
