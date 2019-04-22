#ifndef cnosos_cpp
#define cnosos_cpp

#include "Cnosos.h"

Cnosos::Cnosos(Robot r, byte bits = 3) {
  robot = r;
  BITS = bits;
}
//Destructor


//Funciones
byte Cnosos::lee_numero() {
  byte x = 0;
  for (byte i = 0; i < BITS; i++) {
    x = x << 1;
    x += this->siguiente();
  }
  return x;
}

byte lee_nodo_A(Cnosos* cn, byte &etiq) {
  byte aux = 0;  // caminos contados desde la entrada
  do aux++; while (cn->siguiente());
  etiq = cn->lee_numero();
  return aux;
}

void lee_nodo_B(Cnosos* cn, byte aux, byte &grado, byte &entrada,
                        byte etiq) {
  grado = 0;
  while (cn->siguiente()) grado++;
  entrada = cn->calcula_entrada(aux, grado);
  if (etiq != cn->lee_numero()) cn->error();
}

void Cnosos::lee_nodo(byte &etiq, byte &grado, byte &entrada) {
  byte aux = lee_nodo_A(this, etiq);
  lee_nodo_B(this, aux, grado, entrada, etiq);
}

byte Cnosos::calcula_entrada(byte aux, byte grado) {
  return grado - aux + 1;
}



void Cnosos::sal_aqui() {
  sal_izq();
  if (this->siguiente()) sal_izq();
  else error();
}

void Cnosos::sal(byte i, byte grado, byte pos) {
  while (pos != i) {
    pos++;
    if (pos == grado + 1) {
      if (this->siguiente()) error();
      lee_numero();
      pos = 1;
    }
    if (!this->siguiente()) error();
  }
  sal_aqui();
}

byte Cnosos::siguiente() {
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
      Serial.println("Todos activados");
      if (SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA) {
        // cinta atravesada confirmada
        bit = 1;
        sigo = false;
      }
    } else if (!izda && !centro && !dcha) {
      Serial.println("Ninguno activado");
      if (!SENSOR_IZDA && !SENSOR_CENTRO && !SENSOR_DCHA) {
        // hueco confirmado
        bit = 0;
        sigo = false;
      }
    }
    //No hay ni hueco ni cinta atravesada todavia. Avanza normalmente.
    else if (centro) {
      robot.alante();
    } else if (izda) {
      robot.rotaIzda();
    } else if (dcha) {
      robot.rotaDcha();
    }
  }

  // Bit identificado. Avanzamos hasta dejarlo atras.
  robot.alante();
  if (bit) {
    while (SENSOR_IZDA && SENSOR_CENTRO && SENSOR_DCHA);
  } else {
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
  Serial.println("Bit leido");
  delay(TIEMPO_PENSAR);
  return bit;
}

void Cnosos::sal_izq() {
  //TODO
  robot.rotaIzda();
  robot.alante();
  robot.rotaIzda();
  robot.para();
}

/** Necesita modulo Morse para funcionar */
void Cnosos::luce_numero(byte n) {
  for (byte i = 0; i < n; i++) {
    robot.MORSE.punto();
  }
  Serial.print("Numero: ");
  Serial.println(n);
}

void Cnosos::error() {
  Serial.println("¡ERROR!");
  while (true);
  // while (true) {
  //   punto();
  //   raya();
  // }
}

#endif
