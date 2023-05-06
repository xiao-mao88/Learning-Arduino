#include <Servo.h>
/*materials:
- arduino board
- one 10k ohm potentiometer
- 2 100 microfarad electrolytic capacitors 
- one servo motor with a pointer

when you turn the potentiometer, the servo will also spin, causing 
the pointer to spin; you can add a chart so that the pointer will spin
to your current mood
*/

//creates servo object
Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);

  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);

  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);

  //wait for servo
  delay(15);
}