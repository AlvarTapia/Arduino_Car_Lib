
int const SIRENA = 4;
int const LED_FUNDU = 10;
int const LED_DES = 11; 
void setup(){
  for(int i=2; i<14; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  digitalWrite(2, HIGH);
}
