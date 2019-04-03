#ifndef robot_h
#define robot_h

#include "siguelineas.h"
#include "infrarrojos.h"
#include "morse.h"

#include "Arduino.h"

class Robot {
  #define VELOCIDAD_LENTA 100
  #define VELOCIDAD_GIRO 200
  #define MAX_VELOCIDAD 255
  
  private:
    /** Estados del robot */
    enum Direccion {dirNull = -1, dirAlante, dirAtras, dirGiroDcha, dirGiroIzda, dirRotaDcha, dirRotaIzda};
    Direccion dirActual = dirNull;

  protected: //Solo la clase y sus hijos pueden ver estos elementos
    byte TIEMPO_ARRANQUE;

    byte PIN_IZDA_ALANTE;
    byte PIN_IZDA_ATRAS;
    byte PIN_DCHA_ALANTE;
    byte PIN_DCHA_ATRAS;

    byte PIN_VEL_IZDA;
    byte PIN_VEL_DCHA;

  public:
    /** 
     *  Variables modulos. Se acceden directamente. 
     *  Para utilizarlas, los objetos deben ser inicializados con pines validos.
    */
    //Modulo siguelineas
    Siguelineas SIGUELINEAS = Siguelineas(255, 255, 255);
    //Modulo mando infrarrojo
    Infrarrojos INFRARROJOS = Infrarrojos(255);
    //Modulo morse
    Morse MORSE = Morse(255, 'x');

    //Constructores
    /**
       Inicializa un robot cuyo driver solo tiene 4 entradas para 8 cables de motores
       4 primeros argumentos, pines de control de direccion de los motores
       2 siguientes, pines de control de velocidad de los motores
       ultimo, si es necesario arrancar el robot para cambiar de direccion
    */
    Robot(byte pinIzdaAlante, byte pinIzdaAtras, byte pinDchaAlante, byte pinDchaAtras, byte pinVelIzda, byte pinVelDcha, byte tiempoArranque) {
      PIN_IZDA_ALANTE = pinIzdaAlante;
      pinMode(PIN_IZDA_ALANTE, OUTPUT);
      PIN_IZDA_ATRAS = pinIzdaAtras;
      pinMode(PIN_IZDA_ATRAS, OUTPUT);

      PIN_DCHA_ALANTE = pinDchaAlante;
      pinMode(PIN_DCHA_ALANTE, OUTPUT);
      PIN_DCHA_ATRAS = pinDchaAtras;
      pinMode(PIN_DCHA_ATRAS, OUTPUT);

      PIN_VEL_IZDA = pinVelIzda;
      pinMode(PIN_VEL_IZDA, OUTPUT);
      PIN_VEL_DCHA = pinVelDcha;
      pinMode(PIN_VEL_DCHA, OUTPUT);

      TIEMPO_ARRANQUE = tiempoArranque;
    }
    //Destructores


    //Funciones del robot
    //Motores
    //Relacionado con velocidad
    /** Se aplica mucha tension durante un corto periodo de tiempo para que los motores empiecen a funcionar */
    void arranca() {
      analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
      analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
      delay(TIEMPO_ARRANQUE);
    }
    
    /** Declara la velocidad del robot */
    void setVelocidad(byte velocidad) {
      analogWrite(PIN_VEL_IZDA, velocidad);
      analogWrite(PIN_VEL_DCHA, velocidad);
    }

    /** Deja de alimentar los motores */
    void para(){ 
      this->setVelocidad(0);
    }

    /** Mueve el robot al 40% de la capacidad de las pilas */
    void lento() {
      this->setVelocidad(VELOCIDAD_LENTA);
    }
    
    /** Velocidad moderada, el robot es capaz de girar */
    void velGiro() {
      this->setVelocidad(VELOCIDAD_GIRO);
    }

    /** Mueve el robot al 100% de la capacidad de las pilas */
    void maxVelocidad() {
      this->setVelocidad(MAX_VELOCIDAD);
    }

    //TODO Los giros son inestables en coches Arduino
    /** El robot gira hacia la izda parando los motores de la izda */
    void giraIzda(byte velocidad = MAX_VELOCIDAD) {
      analogWrite(PIN_VEL_IZDA, velocidad);
      analogWrite(PIN_VEL_DCHA, 0);
    }

    /** El robot gira hacia la dcha parando los motores de la dcha */
    void giraDcha(byte velocidad = MAX_VELOCIDAD) {
      analogWrite(PIN_VEL_IZDA, 0);
      analogWrite(PIN_VEL_DCHA, velocidad);
    }

    /** El robot hace que los motores giren hacia alante del robot */
    void alante(byte velocidad = VELOCIDAD_LENTA) {
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

    /** El robot hace que los motores giren hacia atras del robot */
    void atras(byte velocidad = VELOCIDAD_LENTA) {
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

    /** El robot pivota hacia la izda cambiando la direccion de giro de los motores de la izda */
    void rotaIzda(byte velocidad = VELOCIDAD_GIRO) {
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

    /** El robot pivota hacia la dcha cambiando la direccion de giro de los motores de la dcha */
    void rotaDcha(byte velocidad = VELOCIDAD_GIRO) {
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
};


/** OBJETOS YA DISEÑADOS */
Robot arduino(9, 12, 9, 13, 10, 11, 60); //El pin 9 no esta siendo usado,
//y me permite escribir "digitalWrite"s sin afectar al funcionamiento del robot

Robot elegoo(6, 7, 9, 8, 5, 11, 0);

#endif
