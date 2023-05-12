/*materials:
- arduino board
- wires (get a few)
- 1 led
- 1 220 ohm resistor
- 1 mil ohm resistor

one of the wires will have one end in the board and the other just 
sticking out; if you put your fingers on the wire part of that then
the led can light up
*/

#include <CapacitiveSensor.h>

CapacitiveSensor capSens = CapacitiveSensor(4,2);

int limit = 1000;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensorValue = capSens.capacitiveSensor(30);

  //turns LED on
  if(sensorValue>limit){
    digitalWrite(ledPin,HIGH);
  }

  //LED off
  else{
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}