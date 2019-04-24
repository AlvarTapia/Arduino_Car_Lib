/**
 * ----------------------------------------------------------------
 * robot.cpp
 * Clase que gestiona los motores de un robot implementado con placas Arduino.
 * Pueden aplicarse modulos para mejorar la gestion del movimiento del robot.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef robot_cpp
#define robot_cpp

#include "robot.h"

//Constructor
Robot::Robot(byte pinIzdaAlante, byte pinIzdaAtras, byte pinDchaAlante, byte pinDchaAtras,
             byte pinVelIzda, byte pinVelDcha,
             byte tiempoArranque) {
  PIN_IZDA_ALANTE = pinIzdaAlante;
  PIN_IZDA_ATRAS = pinIzdaAtras;

  PIN_DCHA_ALANTE = pinDchaAlante;
  PIN_DCHA_ATRAS = pinDchaAtras;

  PIN_VEL_IZDA = pinVelIzda;
  PIN_VEL_DCHA = pinVelDcha;

  TIEMPO_ARRANQUE = tiempoArranque;
}
//Destructores


//Inicializar
void Robot::inicializa() {
  pinMode(PIN_IZDA_ALANTE, OUTPUT);
  pinMode(PIN_IZDA_ATRAS, OUTPUT);
  pinMode(PIN_DCHA_ALANTE, OUTPUT);
  pinMode(PIN_DCHA_ATRAS, OUTPUT);

  pinMode(PIN_VEL_IZDA, OUTPUT);
  pinMode(PIN_VEL_DCHA, OUTPUT);
}


//Funciones del robot
void Robot::setTiempoArranque(byte tiempoArranque) {
  TIEMPO_ARRANQUE = tiempoArranque;
}

//Velocidad del robot
void Robot::arranca() {
  analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
  analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
  delay(TIEMPO_ARRANQUE);
}

void Robot::setVelocidad(byte velocidad) {
  analogWrite(PIN_VEL_IZDA, velocidad);
  analogWrite(PIN_VEL_DCHA, velocidad);
}

void Robot::para() {
  this->setVelocidad(0);
  dirActual = dirNull;
}

void Robot::lento() {
  this->setVelocidad(VELOCIDAD_LENTA);
}

void Robot::velGiro() {
  this->setVelocidad(VELOCIDAD_GIRO);
}

void Robot::maxVelocidad() {
  this->setVelocidad(MAX_VELOCIDAD);
}

//Cambios de direccion
void Robot::giraIzda(byte velocidad) {
  if (dirActual != dirGiroIzda) {
    this->arranca();
    dirActual = dirGiroIzda;
  }
  analogWrite(PIN_VEL_IZDA, velocidad);
  analogWrite(PIN_VEL_DCHA, 0);

}

void Robot::giraDcha(byte velocidad) {
  if (dirActual != dirGiroDcha) {
    this->arranca();
    dirActual = dirGiroDcha;
  }
  analogWrite(PIN_VEL_IZDA, 0);
  analogWrite(PIN_VEL_DCHA, velocidad);
}


//Cambios de direccion de los motores
void Robot::alante(byte velocidad) {
  if (dirActual != dirAlante) {
    digitalWrite(PIN_IZDA_ALANTE, HIGH);
    digitalWrite(PIN_IZDA_ATRAS, LOW);
    digitalWrite(PIN_DCHA_ALANTE, HIGH);
    digitalWrite(PIN_DCHA_ATRAS, LOW);
    this->arranca();
    dirActual = dirAlante;
  }
  this->setVelocidad(velocidad);
}

void Robot::atras(byte velocidad) {
  if (dirActual != dirAtras) {
    digitalWrite(PIN_IZDA_ALANTE, LOW);
    digitalWrite(PIN_IZDA_ATRAS, HIGH);
    digitalWrite(PIN_DCHA_ALANTE, LOW);
    digitalWrite(PIN_DCHA_ATRAS, HIGH);
    this->arranca();
    dirActual = dirAtras;
  }
  this->setVelocidad(velocidad);
}

void Robot::rotaIzda(byte velocidad) {
  if (dirActual != dirRotaIzda) {
    digitalWrite(PIN_IZDA_ALANTE, HIGH);
    digitalWrite(PIN_IZDA_ATRAS, LOW);
    digitalWrite(PIN_DCHA_ALANTE, LOW);
    digitalWrite(PIN_DCHA_ATRAS, HIGH);
    this->arranca();
    dirActual = dirRotaIzda;
  }
  this->setVelocidad(velocidad);
}

void Robot::rotaDcha(byte velocidad) {
  if (dirActual != dirRotaDcha) {
    digitalWrite(PIN_IZDA_ALANTE, LOW);
    digitalWrite(PIN_IZDA_ATRAS, HIGH);
    digitalWrite(PIN_DCHA_ALANTE, HIGH);
    digitalWrite(PIN_DCHA_ATRAS, LOW);
    this->arranca();
    dirActual = dirRotaDcha;
  }
  this->setVelocidad(velocidad);
}

#endif
