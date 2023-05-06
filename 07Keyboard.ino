/*materials:
- arduino board
- wires (get a few)
- 2 10k ohm resistors
- 1 220 ohm resistor
- 1 1mil ohm resistor
- 1 piezo
- 4 buttons

resistors on the board control the frequencies that the piezo emits
depending on the button you press, you will obtain a different frequency,
giving you a different note
*/

//keyboard notes: middle C, D, E, & F
int notes [] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  //local var for input on pin A0
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  //playing the notes
  if (keyVal == 1023) 
  {
    tone(8, notes[0]);
  }
  
  else if (keyVal >= 990 && keyVal <= 1010) 
  {
    tone(8, notes[1]);
  }

  else if (keyVal >= 505 && keyVal <= 515) 
  {
    tone(8, notes[2]);
  }

  else if (keyVal >= 5 && keyVal <= 10) 
  {
    tone(8, notes[3]);
  }

  else 
  {
    noTone(8);
  }
}