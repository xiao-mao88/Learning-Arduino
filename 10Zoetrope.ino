/*materials:
- arduino board
- wires (get a few)
- 2 10k ohm resistors
- 1 10k ohm potentiometer
- 2 buttons
- 1 H-bridge
- 1 9v battery
- 1 motor

can control speed of the motor, supposed to create an optical illusion
of moving pictures utilizing the motor (didn't work with arduino stuff
from starter kit)
*/

//constant ints
const int contrlPin1 = 2;
const int contrlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int ofOffSwitchStateSwitchPin = 5;

//holds inputs
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  //initializing inputs/outputs
  pinMode(directionSwitchPin, INPUT);
  pinMode(OnOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);

}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);

  directionSwitchState = digitalRead(directionSwitchPin);

  motorSpeed = analogRead(potPin)/4;
 
  //if the on/off button changed state since the last loop()
  if (onOffSwitchState != previousOnOffSwitchState) {
    // change the value of motorEnabled if pressed
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  //the direction button changed state since last loop()
  if (directionSwitchState != previousDirectionSwitchState) {
    // change the value of motorDirection if pressed
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  //change the direction the motor spins
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  // if the motor supposed to be on
  if (motorEnabled == 1) {

    analogWrite(enablePin, motorSpeed);
  }
  else {
    // if the motor not supposed to be on
    analogWrite(enablePin, 0);
  }
 
  //current becomes previous
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}