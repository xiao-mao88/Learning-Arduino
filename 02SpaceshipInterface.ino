/*materials:
- arduino uno board
- 3 leds
- wires (get a few)
- one button
- three 1200 ohm resistors
- one 300 ohm resistor
*/

int switchstate = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(2, INPUT);

  //3 is the green LED
  //4 & 5 refer to the two red LEDs
}

void loop() {
  // put your main code here, to run repeatedly:
  switchstate = digitalRead(2);

  if (switchstate == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);
  }
}