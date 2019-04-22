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


//Funciones del robot
//Motores
//Inicializar
/** Inicializa los pines para que el robot funcione correctamente */
void Robot::inicializa() {
  pinMode(PIN_IZDA_ALANTE, OUTPUT);
  pinMode(PIN_IZDA_ATRAS, OUTPUT);
  pinMode(PIN_DCHA_ALANTE, OUTPUT);
  pinMode(PIN_DCHA_ATRAS, OUTPUT);

  pinMode(PIN_VEL_IZDA, OUTPUT);
  pinMode(PIN_VEL_DCHA, OUTPUT);
}


//Velocidad del robot
/** Permite modificar el tiempo que va a estar arrancando el robot */
void Robot::setTiempoArranque(byte tiempoArranque) {
  TIEMPO_ARRANQUE = tiempoArranque;
}

/** Se aplica mucha tension durante un corto periodo de tiempo para que los motores empiecen a funcionar */
void Robot::arranca() {
  analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
  analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
  delay(TIEMPO_ARRANQUE);
}

/** Declara la velocidad del robot */
void Robot::setVelocidad(byte velocidad) {
  analogWrite(PIN_VEL_IZDA, velocidad);
  analogWrite(PIN_VEL_DCHA, velocidad);
}

/** Deja de alimentar los motores */
void Robot::para() {
  this->setVelocidad(0);
  dirActual = dirNull;
}

/** Mueve el robot al 40% de la capacidad de las pilas */
void Robot::lento() {
  this->setVelocidad(VELOCIDAD_LENTA);
}

/** Velocidad moderada, el robot es capaz de girar */
void Robot::velGiro() {
  this->setVelocidad(VELOCIDAD_GIRO);
}

/** Mueve el robot al 100% de la capacidad de las pilas */
void Robot::maxVelocidad() {
  this->setVelocidad(MAX_VELOCIDAD);
}


/** El robot para los motores de la izda */
void Robot::giraIzda(byte velocidad) {
  if (dirActual != dirGiroIzda) {
    this->arranca();
    dirActual = dirGiroIzda;
  }
  analogWrite(PIN_VEL_IZDA, velocidad);
  analogWrite(PIN_VEL_DCHA, 0);

}

/** El robot para los motores de la dcha */
void Robot::giraDcha(byte velocidad) {
  if (dirActual != dirGiroDcha) {
    this->arranca();
    dirActual = dirGiroDcha;
  }
  analogWrite(PIN_VEL_IZDA, 0);
  analogWrite(PIN_VEL_DCHA, velocidad);
}


//Direccion del robot
/** Los motores giran de manera que el robot va hacia alante */
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

/** Los motores giran de manera que el robot va hacia atras */
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

/** El robot pivota hacia la izda retrocediendo con la izda y avanzando con la dcha */
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

/** El robot pivota hacia la izda retrocediendo con la dcha y avanzando con la izda */
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
