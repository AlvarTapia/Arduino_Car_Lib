int const VEL_MOTOR_A = 10;
int const VEL_MOTOR_B = 11;
int const GIRO_MOTOR_A = 12;
int const GIRO_MOTOR_B = 13;
int const ANALOG_MOTOR_A = A1;
int const ANALOG_MOTOR_B = A3;


void setup(){
  pinMode(GIRO_MOTOR_A, OUTPUT);
  pinMode(GIRO_MOTOR_B, OUTPUT);
  
  pinMode(VEL_MOTOR_A, OUTPUT);
  pinMode(VEL_MOTOR_B, OUTPUT);

  pinMode(4, OUTPUT);
}

void loop(){
  for(int i=255; i>0; i-=5){
    analogWrite(VEL_MOTOR_A, i);
    analogWrite(VEL_MOTOR_B, i);
    if(i==85){
      analogWrite(4, 130); //Sirena
    }else{
      digitalWrite(4, LOW);
    }
    delay(200);
  }
}
