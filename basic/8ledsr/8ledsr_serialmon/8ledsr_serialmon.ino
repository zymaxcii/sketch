// 8ledsr_serialmon.ino

/*
Adafruit Arduino - Lesson 5. Serial Monitor
*/

// 74HC595 pins DS, ST_CP, SH_CP: 14, 12, 11 (data, storage, shift register)
// pin headers bottom to top:
// 11 SH_CP D8
// 12 ST_CP D7
// 14 DS    D6
int clockpin = 8;
int latchpin = 7;
int datapin  = 6;     // bottom pin

byte leds = 0;


void setup()
{
  pinMode(latchpin, OUTPUT);
  pinMode(datapin,  OUTPUT);
  pinMode(clockpin, OUTPUT);
  
  updateShiftRegister();    // clear leds
  Serial.begin(9600);

  while (! Serial);         // wait until Serial is ready - Leonardo
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}


void loop()
{
  if (Serial.available())  
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      int led = ch - '0';
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    else if (ch == 'x')
      {
        leds = 0;
        updateShiftRegister();
        Serial.println("Cleared");
      }
      else 
      {
        if (ch != '\n')
        {
          Serial.println("Haiya! Don't be so stupid...");
        }
      }
  }
}


void updateShiftRegister()
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, leds);
  digitalWrite(latchpin, HIGH);
}
