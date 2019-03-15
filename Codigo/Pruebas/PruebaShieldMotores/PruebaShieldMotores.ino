int const VEL_MOTOR_A = 10;
int const VEL_MOTOR_B = 11;
int const DIR_MOTOR_A = 12;
int const DIR_MOTOR_B = 13;

void setup(){
  for(int i=10; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(VEL_MOTOR_A, HIGH);
  digitalWrite(VEL_MOTOR_B, HIGH);
}

void loop(){
  
  digitalWrite(DIR_MOTOR_A, LOW); //Alante
  digitalWrite(DIR_MOTOR_B, LOW);
  delay(3000);
  
  digitalWrite(DIR_MOTOR_A, HIGH); //Atras
  digitalWrite(DIR_MOTOR_B, HIGH);
  delay(1000);
  
}
