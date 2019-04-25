#include <morse.h>

Morse morseActual; //Objeto con el que se va a trabajar

void setup() {
  //Instanciamos los objetos
  //Morse en pin 4, modo 'sirena', frecuencia de 15000 Hz
  Morse morseSirena = Morse(4, 's', 15000); 
  //Morse en pin 13, modo 'LED'
  Morse morseLed = Morse(13, 'l'); 

  //Guardamos el que vayamos a utilizar
  morseActual = morseSirena;
  //morseActual = morseLed;
  
  //Lo inicializamos
  morseActual.inicializa();

  //Mandamos un punto
  morseActual.punto();
  //Mandamos una raya
  morseActual.raya();
  //Mandamos una señal de SOS
  morseActual.sos();
}

//No necesitamos loop, se haria muy molesto
void loop() { }
