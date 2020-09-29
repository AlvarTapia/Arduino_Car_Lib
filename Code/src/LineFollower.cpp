/**
 * ----------------------------------------------------------------
 * LineFollower.cpp
 * Clase que permite utilizar los sensores siguelineas.
 * Se espera que se usen como mucho tres sensores por objeto.
 *
 * Adaptado por Alvar Tapia, Abril 2019.
 * Legado por Algorítmica y Complejidad, Universidad de Cantabria.
 * ----------------------------------------------------------------
 */

#ifndef linefollower_cpp
#define linefollower_cpp

#include "LineFollower.h"

//Constructores
LineFollower::LineFollower(byte left, byte centre, byte right) {
  LEFT_LINE_SENSOR_PIN = left;
  CENTRE_LINE_SENSOR_PIN = centre;
  RIGHT_LINE_SENSOR_PIN = right;
}
LineFollower::LineFollower(byte left, byte right){
  LineFollower(left, 255, right);
}
LineFollower::LineFollower(byte centre){
  LineFollower(255, centre, 255);
}
//Constructor por defecto
LineFollower::LineFollower(){
  LineFollower(255, 255, 255);
}
//Destructor


//Inicializador
void LineFollower::init() {
  pinMode(LEFT_LINE_SENSOR_PIN, INPUT);
  pinMode(CENTRE_LINE_SENSOR_PIN, INPUT);
  pinMode(RIGHT_LINE_SENSOR_PIN, INPUT);
}

//Funciones
bool LineFollower::leftRead() {
  if (LEFT_LINE_SENSOR_PIN == 255) { //Error
    return false;
  }

  return digitalRead(LEFT_LINE_SENSOR_PIN);
}

bool LineFollower::centreRead() {
  if (CENTRE_LINE_SENSOR_PIN == 255) { //Error
    return false;
  }

  return digitalRead(CENTRE_LINE_SENSOR_PIN);
}

bool LineFollower::rightRead() {
  if (RIGHT_LINE_SENSOR_PIN == 255) { //Error
    return false;
  }

  return digitalRead(RIGHT_LINE_SENSOR_PIN);
}

byte LineFollower::read() {
  byte readingValue = 0;

  bool readings[] = { this->leftRead(),
                      this->centreRead(),
                      this->rightRead() };

  int numReads = sizeof(readings)/sizeof(readings[0]);
  byte currentReadingValue = 1;
  for (byte i=0; i<numReads; i++){
    if (readings[i]){
      readingValue += currentReadingValue;
    }
    currentReadingValue *= 2; // == currentReadingValue << 1;
  }

  return readingValue;
}

#endif
