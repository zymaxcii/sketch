// re_lcd_stepper.ino
// status: compile ok, upload 


// https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
// https://www.youtube.com/watch?v=v4BbSzJ-hz4

/*     Stepper Motor using a Rotary Encoder
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
*/


#include <LiquidCrystal.h>

// Creates an LC object
// Parameters: (rs, enable, d4, d5, d6, d7) 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 

// defines pins
#define stepPin 8 
#define dirPin  9
#define outputA 10
#define outputB 11

int counter = 0;
int angle = 0; 
int aState;
int aLastState;  


void setup()
{
  // Sets the two pins as Output
  pinMode(stepPin, OUTPUT); 
  pinMode(dirPin, OUTPUT);
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  
  aLastState = digitalRead(outputA);
  lcd.begin(16,2); 
}


void loop()
{
  aState = digitalRead(outputA);
  
  if (aState != aLastState)
  {
    if (digitalRead(outputB) != aState)
    {
      counter ++;
      angle ++;
      rotateCW();  
    }
    else
    {
      counter--;
      angle --;
      rotateCCW(); 
    }
    
    if (counter >=30 )
    {
      counter = 0;
    }
     
    lcd.clear();
    lcd.print("Position: ");
    lcd.print(int(angle*(-1.8)));
    lcd.print("deg"); 
    lcd.setCursor(0,0);
  }
  aLastState = aState;
}


void rotateCW()
{
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(2000); 
}


void rotateCCW()
{
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(2000);   
}
