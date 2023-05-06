/*materials
- arduino board
- wires (get a few)
- motor
- button
- 9V battery
- 1 10k ohm resistor
- 1 1N4007 diode
- 1 IRF520 MOSFET transistor

hit the button and the motor will start spinning; you can add a pinwheel
to it
*/

//switch & motor pin constants
const int switchPin = 2;
const int motorPin = 9;

int switchState = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState == HIGH){
    digitalWrite(motorPin, HIGH);
  }

  else{
    digitalWrite(motorPin, LOW);
  }
}