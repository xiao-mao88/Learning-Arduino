#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;

int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);

  pinMode(switchPin, INPUT);

  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState!=prevSwitchState){
    if(switchState==LOW){
      reply = random(9);
     
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("the ball says");
      lcd.setCursor(0, 1);

      //random eight ball responses
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;

        case 1:
        lcd.print("No");
        break;

        case 2:
        lcd.print("Probably");
        break;

        case 3:
        lcd.print("Certainly");
        break;

        case 4:
        lcd.print("Outlook Good");
        break;

        case 5:
        lcd.print("IDK");
        break;

        case 6:
        lcd.print("Try again");
        break;

        case 7:
        lcd.print("I doubt it");
        break;

        case 8:
        lcd.print("bing bong ding dong walla walla bing bong");
        break;
      }
    }
  }

  prevSwitchState = switchState;
}