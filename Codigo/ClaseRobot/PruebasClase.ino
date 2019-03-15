int const VEL_MOTOR_A = 10;
int const VEL_MOTOR_B = 11;
int const GIRO_MOTOR_A = 12;
int const GIRO_MOTOR_B = 13;

Robot robotPrueba(GIRO_MOTOR_A, GIRO_MOTOR_B, VEL_MOTOR_A, VEL_MOTOR_B);
void setup(){
  robotPrueba.arranca();
}

void loop(){
  robotPrueba.lento();
  delay(3000);
  robotPrueba.maxVelocidad();
  delay(500);
}
