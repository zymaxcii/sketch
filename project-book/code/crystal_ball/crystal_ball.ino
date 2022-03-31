// crystal_ball.ino
// chapter 11
// Arduino project book

#include <LiquidCrystal.h>

// rs, enable, d4, d5, d6, d7
LiquidCrystal lcd(6, 7, 2, 3, 4, 5);

const int switchPin = 8;    // tilt switch

int switchState = 0;
int prevSwitchState = 0;
int reply;


void setup()
{
  Serial.begin(9600);
  Serial.println("Setting up...");
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);  // active low; input_pullup?
  
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}


void loop()
{
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  
  if (switchState != prevSwitchState)
  {
    // switch pressed?
    if (switchState == LOW)
    {
      // yes
      reply = random(8);
      Serial.println(reply);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print ( "The ball says:" );
      lcd.setCursor(0, 1);

      switch(reply)
      {
        case 0:
          lcd.print("Yes");
          break;

        case 1:
          lcd.print("Most likely");
          break;

        case 2:
          lcd.print("Certainly");
          break;

        case 3:
          lcd.print("Outlook good");
          break;

        case 4:
          lcd.print("Unsure");
          break;

        case 5:
          lcd.print("Ask again");
          break;

        case 6:
          lcd.print("Doubtful");
          break;

        case 7:
          lcd.print("No");
          break;
      }
    }
  }
  prevSwitchState = switchState;
}
