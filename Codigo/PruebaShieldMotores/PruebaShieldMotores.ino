
int const SIRENA = 4;
int const LED_FUNDU = 10;
int const LED_DES = 11; 
void setup(){
  PORTD = 0b00000000;
  for(int i=10; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(11, HIGH);//Velocidad
}

void loop(){
  digitalWrite(13, LOW);//Direccion
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
}
