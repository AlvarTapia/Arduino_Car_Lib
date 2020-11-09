#include "MorseDevice.h"

void setup() {
  // put your setup code here, to run once:
  Led led;
  Serial.println( "LED bound to fail: " + led.startSignaling() );
  Siren siren;
  Serial.println( "Siren bound to fail: " + siren.startSignaling() );
  
  led = Led(10);
  Serial.println("LED testing... " + led.startSignaling() );
  siren = Siren(5);
  Serial.println("Siren testing... " + led.startSignaling() );  
}

void loop() {
  // put your main code here, to run repeatedly:

}
