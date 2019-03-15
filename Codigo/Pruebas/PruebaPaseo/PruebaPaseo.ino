int const VEL_MOTOR_A = 10;
int const VEL_MOTOR_B = 11;
int const GIRO_MOTOR_A = 12;
int const GIRO_MOTOR_B = 13;


void setup(){
  pinMode(GIRO_MOTOR_A, OUTPUT);
  pinMode(GIRO_MOTOR_B, OUTPUT);
  
  pinMode(VEL_MOTOR_A, OUTPUT);
  pinMode(VEL_MOTOR_B, OUTPUT);
  
  digitalWrite(VEL_MOTOR_A, HIGH);
  digitalWrite(VEL_MOTOR_B, HIGH);
  delay(200);
}

void loop(){
  digitalWrite(GIRO_MOTOR_A, LOW);
  digitalWrite(GIRO_MOTOR_B, LOW);
  delay(10000);
  digitalWrite(GIRO_MOTOR_B, HIGH);
  delay(1000); //Gira casi 180º
}