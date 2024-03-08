// led8_4ledByPot.ino
// 4 leds controlled by a potentiometer
// A potentiometer with 4 leds divided into 4 25% to light up
// uses 8 led module

// pot_led_4Lightup.ino
// led_lightUpByPercent.ino
// led_lightUp1to4.ino
// led_4byPot.ino
// 4 leds controlled by a potentiometer

// test_pot_leds.ino


// Boards to run the sketch:
// my general purpose LED board and a potentiometer

// LED board:
// pin # Name to Uno Pin
// =====================
// 1  LED1	D2
// 2  LED2	D3
// 3  LED3	D4
// 4  LED4	D5

// potentiometer:
// 
// pin # Name to Uno Pin
// =====================
// 1  VCC     +5V
// 2  Output  A0
// 3  GND     GND
// 


int potPin = A0;

// with normal leds on breadboard
// int led1 = 2;
// int led2 = 3;
// int led3 = 4;
// int led4 = 5;

// with the 8 led module and mega
//const int led1 = 39;
//const int led2 = 41;
//const int led3 = 43;
//const int led4 = 45;

// with the 8 led module and nano
const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;


int potValue;
int percent;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
}


void loop()
{
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);     // convert to a percentage

  if (percent <= 5) 
  {
    // all 4 leds off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else
  {
    if (percent > 5 && percent <= 25)
    {
      // 25%: light up 1 led
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    else
    {
      if (percent > 25 && percent <= 50)
      {
        // 25-50%: light up 2 leds
        digitalWrite(led1, HIGH); 
        digitalWrite(led2, HIGH); 
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
      }
      else
      {
        if (percent > 50 && percent <=75)
        {
          // 51-75%: light up 3 leds
          digitalWrite(led1, HIGH); 
          digitalWrite(led2, HIGH); 
          digitalWrite(led3, HIGH);
          digitalWrite(led4, LOW); 
        }
        else
        { 
          // 76-100%: light up all 4 leds
          digitalWrite(led1, HIGH); 
          digitalWrite(led2, HIGH); 
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
        }
      }
    }
  }
}
