// keyboard_instrument.ino
// chapter 7
// keyboard instrument

// connect a resistor ladder to analog input A5
// connect a buzzer to pin 13

// variable declared but not used!
// int buttons[6];      // set up an array with 6 integers
// int buttons[0] = 2;
// int buttons[0] = 2;      // give first element of array value 2

// int notes[] = {262, 294, 330, 349};
int notes[] = {1000, 1200, 2000, 2500};



void setup() 
{
  Serial.begin(9600);
}


void loop() 
{
  int keyVal = analogRead(A5);    // original A0

  Serial.println(keyVal);

  if (keyVal == 1023)
  {
    tone(13, notes[0]);
  }

  else
  {
    if (keyVal >= 990 && keyVal <= 1010)
    {
      tone(13, notes[1]);   delay(1000);

    }
    else
    {
      if (keyVal >= 505 && keyVal <= 515)
      {
        tone(13, notes[2]);   delay(1000);

      }
      else
      {
        if(keyVal >= 5 && keyVal <= 10)
        {
          tone(13, notes[3]);   delay(1000);

        }
        else
        {
          noTone(13);
          Serial.println("no tone");
        }
      }
    }
  }
}
