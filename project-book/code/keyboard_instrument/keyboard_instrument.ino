// keyboard_instrument.ino
// chapter 7
// keyboard instrument

// connect a resistor ladder to analog input A0
// connect a buzzer to pin 8

// variable declared but not used!
// int buttons[6];      // set up an array with 6 integers
// int buttons[0] = 2;
// int buttons[0] = 2;      // give first element of array value 2

int notes[] = {262, 294, 330, 349};


void setup() 
{
  Serial.begin(9600);
}


void loop() 
{
  int keyVal = analogRead(A2);    // original A0

  Serial.println(keyVal);

  if (keyVal == 1023)
  {
    tone(8, notes[0]);
  }

  else
  {
    if (keyVal >= 990 && keyVal <= 1010)
    {
      tone(8, notes[1]);
    }
    else
    {
      if (keyVal >= 505 && keyVal <= 515)
      {
        tone(8, notes[2]);
      }
      else
      {
        if(keyVal >= 5 && keyVal <= 10)
        {
          tone(8, notes[3]);
        }
        else
        {
          noTone(8);
        }
      }
    }
  }
}
