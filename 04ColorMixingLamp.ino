/*materials:
- arduino board
- wires (get a few)
- 3 10k ohm resistors
- 3 220 ohm resistors
- 3 photoresistors
- 1 RGB led (has 4 legs)
- 3 colored gels (red, blue, green)

put colored gels on top of the photoresistors and watch as the RGB led 
changes color as well
*/

//where the LEDs are connected
const int greenPin = 9;
const int redPin = 10;
const int bluePin = 11;

//where the photoresistors are connected
const int redSensPin = A0;  
const int greenSensPin = A1;
const int blueSensPin = A2;

//value to LEDs
int redVal = 0;
int greenVal = 0;
int blueVal = 0;

//value from sensors
int redSensVal = 0;
int greenSensVal = 0;
int blueSensVal = 0;


void setup() {
  Serial.begin(9600);

  //sets the pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //reads the values from the photoresistors
  redSensVal = analogRead(redSensPin);
  delay(5);
 
  greenSensVal = analogRead(greenSensPin);
  delay(5);
 
  blueSensVal = analogRead(blueSensPin);
  delay(5);

  //to serial monitor
  Serial.print("raw sensor Values \t red: ");
  Serial.print(redSensPin);
  Serial.print("\t green: ");
  Serial.print(greenSensPin);
  Serial.print("\t Blue: ");
  Serial.println(blueSensPin);

  //keep your stuff in the range of the output
  redVal = redSensPin / 4;
  greenVal = greenSensPin / 4;
  blueVal = blueSensPin / 4;

  //print mapped values
  Serial.print("Mapped sensor Values \t red: ");
  Serial.print(redVal);
  Serial.print("\t green: ");
  Serial.print(greenVal);
  Serial.print("\t Blue: ");
  Serial.println(blueVal);

  //changing the LED
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}