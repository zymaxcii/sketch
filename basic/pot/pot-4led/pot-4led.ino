// pot-4led.ino
// https://mytectutor.com/how-to-use-a-potentiometer-with-arduino/
// display pot readings to 4 leds: 25% each

int potPin = A0;                 // potentiometer is connected to analog 0 pin
int led1 = 8;                    // red LED connected to digital PIN 13
int led2 = 9;                    // red LED connected to digital PIN 12
int led3 = 10;
int led4 = 11;
int potValue;                    // variable used to store the value coming from the sensor
int percent;                     // variable used to store the percentage value


void setup()
{
  pinMode(led1, OUTPUT);         // LED is declared as an output
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
}


void loop()
{
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);      // convert pot reading to percentage
  
  if (percent <= 5)
  {
    // if the percentage is less than 5%, all LEDs off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  } 
  else
    if (percent > 5 && percent <= 25)
    {
      digitalWrite(led1, HIGH);                   // between 5 and 25%: 1 LED on
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    else
      if (percent > 25 && percent <= 50)          // between 25 and 50%: 2 LED on
      {
         digitalWrite(led1, HIGH); 
         digitalWrite(led2, HIGH); 
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW);
      }
      else
        if (percent > 50 && percent <=75)          // between 50 and 75%: 3 LED on
        {
          digitalWrite(led1, HIGH); 
          digitalWrite(led2, HIGH); 
          digitalWrite(led3, HIGH);
          digitalWrite(led4, LOW); 
        }
        else
        { 
           digitalWrite(led1, HIGH);                // between 75 and 100%: all 4 LED on
           digitalWrite(led2, HIGH); 
           digitalWrite(led3, HIGH);
           digitalWrite(led4, HIGH);
        }
}
