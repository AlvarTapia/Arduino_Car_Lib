void setup() {
  //DDRD = 0b00111100; //Output = 2, 3, 4, 5
  DDRD = 0x3D; //Output = 2, 3, 4, 5
}

void loop() {
  int sensor = PIND & 0b10000000;  //Mascara para el valor del pin 7
  if(sensor > 0){
    para();
  }else{
    alante();
  }
}

void para(){
  PORTD &= 0b11000011; //Desactiva 2, 3, 4, 5
}

void alante(){
  PORTD |= 0b00101000; //Activa cables 3 y 5
}
