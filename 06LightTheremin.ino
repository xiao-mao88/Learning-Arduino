/*materials:
- arduino board
- wires (get a few)
- 1 10k ohm resistor
- 1 piezo
- 1 photoresistor

when light hits the photoresistor, the piezo will let out a frequency 
if you cover the photoresistor, then the frequency will be lower
*/

//variables: hold sensor value, low value, high value
int sensVal;
int sensLow = 1023;
int sensHigh = 0;
const int ledPin = 13;

void setup() {
  //LED turns on and the pin is an output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //calibration
  while(millis()<500){
    sensVal = analogRead(A0);

    if(sensVal > sensHigh){
      sensHigh = sensVal;
    }

    if(sensVal < sensLow){
      sensLow = sensVal;
    }
  }

  digitalWrite(ledPin, LOW);

}

void loop() {
  sensVal = analogRead(A0);

  int pitch = map(sensVal, sensLow, sensHigh, 50, 4000);
 
  tone(8, pitch, 20);
 
  delay(10);
}