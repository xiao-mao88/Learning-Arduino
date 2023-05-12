/*materials:
- arduino board
- wires (get a few)
- 1 10k ohm resistor
- 3 220 ohm resistor
- 3 leds (one red, one yellow, one green)
- 1 button
- 1 piezo
- 1 100 microfarad capacitor
- 1 1mil ohm resistor
- 1 servo motor

knock on the piezo three times at just the right volume and the 
'lock' (servo motor) will unlock
*/

#include <Servo.h>

Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

bool locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);

  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  pinMode(switchPin, INPUT);

  Serial.begin(9600);

  digitalWrite(greenLed, HIGH);

  //currently unlocked
  myServo.write(0);

  Serial.println("the box is unlocked");
}

void loop() {
 
  if(locked==false){
    switchVal = digitalRead(switchPin);

    if(switchVal==HIGH){
      locked = true;

      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);

      myServo.write(90);

      Serial.println("the box is locked! T__T");

      delay(1000);
    }
  }

  if(locked==true){
    knockVal = analogRead(piezo);

    if(numberOfKnocks<3 && knockVal>0){
     
      if(checkForKnock(knockVal)==true){
        numberOfKnocks++;
      }
     
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    if(numberOfKnocks>=3){
      locked = false;

      myServo.write(0);

      delay(20);

      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("box is unlocked");

      numberOfKnocks = 0;
    }
  }
}

bool checkForKnock(int value){
  if(value>quietKnock && value<loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);

    Serial.println("valid knock value of: " + value);
    }

    else{
      Serial.println("bad knock value of: " + value);

      return false;
  }
}