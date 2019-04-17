#ifndef cnosos_h
#define cnosos_h

#include "robot.h"

class Cnosos {
  #define SENSOR_IZDA robot.SIGUELINEAS.readIzda()
  #define SENSOR_CENTRO robot.SIGUELINEAS.readCentro()
  #define SENSOR_DCHA robot.SIGUELINEAS.readDcha()
  #define TIEMPO_PENSAR 500
  private:
    Robot robot;
    byte BITS;
  public:
    //Constructores
    Cnosos(Robot r, byte bits = 3){
      robot = r;
      BITS = bits;
    }
    //Destructor


    //Funciones
    byte lee_numero() {
      byte x = 0;
      for (byte i = 0; i < BITS; i++) {
        x = x << 1;
        x += siguiente();
      }
      return x;
    }

    void lee_nodo(byte &etiq, byte &grado, byte &entrada) {
      byte aux = lee_nodo_A(etiq);
      lee_nodo_B(aux, grado, entrada, etiq);
    }

    byte lee_nodo_A(byte &etiq) {
      byte aux = 0;  // caminos contados desde la entrada
      do aux++; while (siguiente());
      etiq = lee_numero();
      return aux;
    }

    byte calcula_entrada(byte aux, byte grado) {
      return grado - aux + 1;
    }

    void lee_nodo_B(byte aux, byte &grado, byte &entrada,
                    byte etiq) {
      grado = 0;
      while (siguiente()) grado++;
      entrada = calcula_entrada(aux, grado);
      if (etiq != lee_numero()) error();
    }

    void sal_aqui() {
      sal_izq();
      if (siguiente()) sal_izq();
      else error();
    }

    void sal(byte i, byte grado, byte pos) {
      while (pos != i) {
        pos++;
        if (pos == grado + 1) {
          if (siguiente()) error();
          lee_numero();
          pos = 1;
        }
        if (!siguiente()) error();
      }
      sal_aqui();
    }

    byte siguiente() {
      robot.alante();
      byte bit;
      bool sigo = true;
      bool izda, centro, dcha;
      //Avanza hasta encontrar un hueco o una cinta atravesada
      while (sigo) {
        izda = SENSOR_IZDA;
        centro = SENSOR_CENTRO;
        dcha = SENSOR_DCHA;
        if (izda && centro && dcha) {
          //Cinta atravesada
          bit = 1;
          sigo = false;
        } else if (!izda && !centro && !dcha) {
          // hueco
          bit = 0;
          sigo = false;
        } 
        //No hay ni hueco ni cinta atravesada todavia. Avanza normalmente.
        else if (izda) {
          robot.rotaIzda();
        } else if (dcha) {
          robot.rotaDcha();
        } else if (centro) {
          robot.alante();
        }
      }
      
      // Bit identificado. Avanzamos hasta dejarlo atrás.
      robot.alante();
      if (bit){
        while (SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA);
      }else {
        while (!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA);
      }

      /*
      // Bit sobrepasado. Enderezamos si es preciso.
      while (SENSOR_IZDA || SENSOR_DCHA) {
        if (SENSOR_IZDA) {
          robot.rotaIzda();
          while (SENSOR_IZDA);
        } else if (SENSOR_DCHA) {
          robot.rotaDcha();
          while (SENSOR_DCHA);
        }
      }
      */
      robot.para();
      delay(TIEMPO_PENSAR);
      return bit;
    }

    void sal_izq() {
      //TODO
      robot.rotaIzda();
      robot.alante();
      robot.rotaIzda();
      robot.para();
    }

    /** Necesita modulo Morse para funcionar */
    void luce_numero(byte n) {
      for (byte i = 0; i < n; i++)
        robot.MORSE.point();
    }

    void error() {
      Serial.println("¡ERROR!");
      while (true);
      // while (true) {
      //   punto();
      //   raya();
      // }
    }
};

#endif
