void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop(){
  if(Serial.available()){
    Serial.read();
    digitalWrite(4, HIGH);
    delay(50);
  }else{
    digitalWrite(4, LOW);
  }
  //Serial.println("Probando");
}
