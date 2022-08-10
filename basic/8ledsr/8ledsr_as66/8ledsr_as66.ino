// 8ledsr_as66
// modfied from 8ledsr_on1by1.ino
// simulate the display of Panasonic AS66 alkaline water machine
// https://lastminuteengineers.com/74hc595-shift-register-arduino-tutorial/

// 74HC595 pins DS, ST_CP, SH_CP: 14, 12, 11 (data, storage, shift register)
// pin headers bottom to top:
// 11 SH_CP D8
// 12 ST_CP D7
// 14 DS    D6
int clockpin = 8;
int latchpin = 7;
int datapin  = 6;     // bottom pin

byte leds = 0;		// Variable to hold the pattern of which LEDs are currently turned on or off
int delayTime = 100;

void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchpin, OUTPUT);
  pinMode(datapin,  OUTPUT);  
  pinMode(clockpin, OUTPUT);
}


void loop() 
{
  leds = B10000000;	  // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  updateShiftRegister();
  delay(500);
  
  for (int i = 0; i < 7; i++)	// Turn all the LEDs ON one by one.
  {
    bitSet(leds, i);		// Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister();
    delay(delayTime);
  }
}


// This function sets the latchpin to low, then calls the Arduino function 'shiftOut' to shift out
// contents of variable 'leds' in the shift register before putting the 'latchpin' high again
void updateShiftRegister()
{
   digitalWrite(latchpin, LOW);
   shiftOut(datapin, clockpin, LSBFIRST, leds);
   digitalWrite(latchpin, HIGH);
}
