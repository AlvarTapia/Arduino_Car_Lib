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
}

void loop(){  
  analogWrite(VEL_MOTOR_A, 85);
  analogWrite(VEL_MOTOR_B, 85);
  delay(3000);
  
  analogWrite(VEL_MOTOR_A, 210);
  analogWrite(VEL_MOTOR_B, 210);
  delay(1000);
}
