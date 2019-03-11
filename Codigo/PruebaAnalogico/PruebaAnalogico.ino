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
  digitalWrite(VEL_MOTOR_A, HIGH);
  digitalWrite(VEL_MOTOR_B, HIGH);
  pinMode(ANALOG_MOTOR_A, OUTPUT);
  pinMode(ANALOG_MOTOR_B, OUTPUT);
}

void loop(){
  
  analogWrite(ANALOG_MOTOR_A, 0b10000000); //Lento
  analogWrite(ANALOG_MOTOR_B, 0b10000000); //Lento
  delay(3000);
  
  analogWrite(ANALOG_MOTOR_A, 0b11111111); //Max velocidad
  analogWrite(ANALOG_MOTOR_B, 0b11111111); //Max velocidad
  delay(1000);

  //EDIT: Los motores van siempre a la misma velocidad
