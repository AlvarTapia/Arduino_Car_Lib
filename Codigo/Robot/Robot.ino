#include "siguelineas.h"

class Robot {
  private:
    enum Direccion {dirNull = -1, dirAlante, dirAtras, dirGiroDcha, dirGiroIzda, dirRotaDcha, dirRotaIzda};
    Direccion dirActual = dirNull;
  protected: //Solo la clase y sus hijos pueden ver estos elementos
    byte const VELOCIDAD_LENTA = 100;
    byte const VELOCIDAD_GIRO = 175;
    byte const MAX_VELOCIDAD = 255;
    bool NECESITA_ARRANCAR;

    byte PIN_IZDA_ALANTE;
    byte PIN_IZDA_ATRAS;
    byte PIN_DCHA_ALANTE;
    byte PIN_DCHA_ATRAS;

    byte PIN_VEL_IZDA;
    byte PIN_VEL_DCHA;

  public:
    //Modulo siguelineas
    /** No tiene gets ni sets. Inicializar directamente. Leer Siguelineas.ino para conocer las funciones de esta clase */
    Siguelineas siguelineas;
    
    //Constructores
    /** 
     * Inicializa un robot cuyo driver solo tiene 4 entradas para 8 cables de motores 
     * 4 primeros argumentos, pines de control de direccion de los motores
     * 2 siguientes, pines de control de velocidad de los motores
     * ultimo, si es necesario arrancar el coche para cambiar de direccion
     */
    Robot(byte pinIzdaAlante, byte pinIzdaAtras, byte pinDchaAlante, byte pinDchaAtras, byte pinVelIzda, byte pinVelDcha, bool necesitaArrancar) {
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

      NECESITA_ARRANCAR = necesitaArrancar;
    }
    //Destructores


    //Funciones del robot
    //Motores
    //Relacionado con velocidad
    /** Se aplica mucha tension durante un corto periodo de tiempo para que los motores empiecen a funcionar */
    void arranca() {
      analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
      analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
      delay(100);
    }

    /** Mueve el coche al 40% de la capacidad de las pilas */
    void lento() {
      analogWrite(PIN_VEL_IZDA, VELOCIDAD_LENTA);
      analogWrite(PIN_VEL_DCHA, VELOCIDAD_LENTA);
    }
    /** Velocidad a la que el coche es capaz de girar */
    void velGiro() {
      analogWrite(PIN_VEL_IZDA, VELOCIDAD_GIRO);
      analogWrite(PIN_VEL_DCHA, VELOCIDAD_GIRO);
    }

    /** Mueve el coche al 100% de la capacidad de las pilas */
    void maxVelocidad() {
      analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
      analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
    }

    /** Deja de alimentar los motores. Debe arrancarse de nuevo cuando quiera retomar la marcha */
    void para() {
      analogWrite(PIN_VEL_IZDA, 0);
      analogWrite(PIN_VEL_DCHA, 0);
    }

    /** El robot gira hacia la izda parando los motores de la izda */
    void giraIzda() {
      analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
      analogWrite(PIN_VEL_DCHA, 0);
    }

    /** El robot gira hacia la dcha parando los motores de la dcha */
    void giraDcha() {
      analogWrite(PIN_VEL_IZDA, 0);
      analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
    }

    /** El robot hace que los motores giren hacia alante del robot */
    void alante() {
      if (dirActual != dirAlante) {
        digitalWrite(PIN_IZDA_ALANTE, HIGH);
        digitalWrite(PIN_IZDA_ATRAS, LOW);
        digitalWrite(PIN_DCHA_ALANTE, HIGH);
        digitalWrite(PIN_DCHA_ATRAS, LOW);
        if(NECESITA_ARRANCAR){
          this->arranca();
        }
        dirActual = dirAlante;
      }
      this->lento();
    }

    /** El robot hace que los motores giren hacia atras del robot */
    void atras() {
      if (dirActual != dirAtras) {
        digitalWrite(PIN_IZDA_ALANTE, LOW);
        digitalWrite(PIN_IZDA_ATRAS, HIGH);
        digitalWrite(PIN_DCHA_ALANTE, LOW);
        digitalWrite(PIN_DCHA_ATRAS, HIGH);
        if(NECESITA_ARRANCAR){
          this->arranca();
        }
        dirActual = dirAtras;
      }
      this->lento();
    }

    /** El robot pivota hacia la izda cambiando la direccion de giro de los motores de la izda */
    void rotaIzda() {
      if (dirActual != dirRotaIzda) {
        digitalWrite(PIN_IZDA_ALANTE, HIGH);
        digitalWrite(PIN_IZDA_ATRAS, LOW);
        digitalWrite(PIN_DCHA_ALANTE, LOW);
        digitalWrite(PIN_DCHA_ATRAS, HIGH);
        if(NECESITA_ARRANCAR){
          this->arranca();
        }
        dirActual = dirRotaIzda;
      }
      this->velGiro();
    }

    /** El robot pivota hacia la dcha cambiando la direccion de giro de los motores de la dcha */
    void rotaDcha() {
      if (dirActual != dirRotaDcha) {
        digitalWrite(PIN_IZDA_ALANTE, LOW);
        digitalWrite(PIN_IZDA_ATRAS, HIGH);
        digitalWrite(PIN_DCHA_ALANTE, HIGH);
        digitalWrite(PIN_DCHA_ATRAS, LOW);
        if(NECESITA_ARRANCAR){
          this->arranca();
        }
        dirActual = dirRotaDcha;
      }
      this->velGiro();
    }    
};



/** OBJETOS YA DISEÑADOS */
Robot arduino(9, 12, 9, 13, 10, 11, true); //El pin 9 no esta siendo usado,
//y me permite escribir "digitalWrite"s sin afectar al funcionamiento del robot

Robot elegoo(6, 7, 9, 8, 5, 11, false);
