/**
 * ----------------------------------------------------------------
 * robot.cpp
 * Clase que gestiona los motores de un robot implementado
 * con placas Arduino.
 * Pueden aplicarse modulos para mejorar la gestion
 * del movimiento del robot.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef robot_cpp
#define robot_cpp

#include "robot.h"

//Constructores
Robot::Robot(byte frontLeftPin, byte backLeftPin,
             byte frontRightPin, byte backRightPin,
             byte leftVelPin, byte rightVelPin,
             byte startUpTime) {

  FRONT_LEFT_PIN = frontLeftPin;
  BACK_LEFT_PIN = backLeftPin;

  FRONT_RIGHT_PIN = frontRightPin;
  BACK_RIGHT_PIN = backRightPin;

  LEFT_VEL_PIN = leftVelPin;
  RIGHT_VEL_PIN = rightVelPin;

  START_UP_TIME = startUpTime;
}

Robot::Robot(){
  Robot(255, 255, 255, 255, 255, 255, 255);
}
//Destructores


//Inicializar
void Robot::init() {
  pinMode(FRONT_LEFT_PIN, OUTPUT);
  pinMode(BACK_LEFT_PIN, OUTPUT);
  pinMode(FRONT_RIGHT_PIN, OUTPUT);
  pinMode(BACK_RIGHT_PIN, OUTPUT);

  pinMode(LEFT_VEL_PIN, OUTPUT);
  pinMode(RIGHT_VEL_PIN, OUTPUT);
}


//Funciones del robot
void Robot::setStartUpTime(byte startUpTime) {
  START_UP_TIME = startUpTime;
}

//Velocidad del robot
void Robot::startUp() {
  analogWrite(LEFT_VEL_PIN, MAX_VEL);
  analogWrite(RIGHT_VEL_PIN, MAX_VEL);
  delay(START_UP_TIME);
}

void Robot::setVelocity(byte velocity) {
  analogWrite(LEFT_VEL_PIN, velocity);
  analogWrite(RIGHT_VEL_PIN, velocity);
}

void Robot::stop() {
  this->setVelocity(0);
  currentMotion = nullMotion;
}

void Robot::slow() {
  this->setVelocity(SLOW_VEL);
}

void Robot::turnVelocity() {
  this->setVelocity(TURN_VEL);
}

void Robot::maxVelocity() {
  this->setVelocity(MAX_VEL);
}

//Cambios de direccion
void Robot::turnLeft(byte velocity) {
  if (currentMotion != leftTurnMotion) {
    this->startUp();
    currentMotion = leftTurnMotion;
  }
  analogWrite(LEFT_VEL_PIN, velocity);
  analogWrite(RIGHT_VEL_PIN, 0);

}

void Robot::turnRight(byte velocity) {
  if (currentMotion != rightTurnMotion) {
    this->startUp();
    currentMotion = rightTurnMotion;
  }
  analogWrite(LEFT_VEL_PIN, 0);
  analogWrite(RIGHT_VEL_PIN, velocity);
}


//Cambios de direccion de los motores
void Robot::forwards(byte velocity) {
  if (currentMotion != forwardMotion) {
    digitalWrite(FRONT_LEFT_PIN, HIGH);
    digitalWrite(BACK_LEFT_PIN, LOW);
    digitalWrite(FRONT_RIGHT_PIN, HIGH);
    digitalWrite(BACK_RIGHT_PIN, LOW);
    this->startUp();
    currentMotion = forwardMotion;
  }
  this->setVelocity(velocity);
}

void Robot::backwards(byte velocity) {
  if (currentMotion != backwardsMotion) {
    digitalWrite(FRONT_LEFT_PIN, LOW);
    digitalWrite(BACK_LEFT_PIN, HIGH);
    digitalWrite(FRONT_RIGHT_PIN, LOW);
    digitalWrite(BACK_RIGHT_PIN, HIGH);
    this->startUp();
    currentMotion = backwardsMotion;
  }
  this->setVelocity(velocity);
}

void Robot::leftRotation(byte velocity) {
  if (currentMotion != leftRotMotion) {
    digitalWrite(FRONT_LEFT_PIN, HIGH);
    digitalWrite(BACK_LEFT_PIN, LOW);
    digitalWrite(FRONT_RIGHT_PIN, LOW);
    digitalWrite(BACK_RIGHT_PIN, HIGH);
    this->startUp();
    currentMotion = leftRotMotion;
  }
  this->setVelocity(velocity);
}

void Robot::rightRotation(byte velocity) {
  if (currentMotion != rightRotMotion) {
    digitalWrite(FRONT_LEFT_PIN, LOW);
    digitalWrite(BACK_LEFT_PIN, HIGH);
    digitalWrite(FRONT_RIGHT_PIN, HIGH);
    digitalWrite(BACK_RIGHT_PIN, LOW);
    this->startUp();
    currentMotion = rightRotMotion;
  }
  this->setVelocity(velocity);
}

#endif
