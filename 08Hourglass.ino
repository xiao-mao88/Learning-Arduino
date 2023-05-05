/*materials:
- arduino board
- wires (get a few)
- 6 leds
- 6 1200 ohm resistors
- 1 300 ohm resistor
- 1 tilt switch

tilt the switch and the 'hourglass' will reset (this code is modified
to be much shorter than the original for pratical purposes)
leds will light up every second
*/

const int switchPin = 8;

unsigned long previousTime = 0; // store the last time an LED was updated
int switchState = 0; // the current switch state
int prevSwitchState = 0; // the previous switch state
int led = 2; // a variable to refer to the LEDs


long interval = 1000; 

void setup() {
  // set the LED pins as outputs
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  // set the tilt switch pin as input
  pinMode(switchPin, INPUT);
}

void loop() {
  // store the time since the Arduino started running in a variable
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;

    digitalWrite(led, HIGH);
    
    
    led++;

    if (led == 7) {
      // time up
    }
  }

  
  switchState = digitalRead(switchPin);

  
  if (switchState != prevSwitchState) {
    
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    // reset the LED variable to the first one
    led = 2;

    //reset the timer
    previousTime = currentTime;
  }
  
  prevSwitchState = switchState;
}