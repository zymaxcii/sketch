// ledsr_patterns.ino
// led_8sr.ino
// Perform various test patterns on 8 leds connected via a 74HC595 shift register
// taken from robotic nation
//
// 74HC595 uses a type of serial connection called SPI
// Serial Peripheral Interface that requires three pins

void oneOnAtATime(), pingPong(), randomLED(), marquee(), binaryCount(), allOff(), allOn(); 

// 74HC595 pins DS, SH_CP, ST_CP: 14, 11, 12
// connect pins D8, D6, D7 
// connect pins 14, 11, 12: D2, D3, D4
//int datapin  = 8; 
//int clockpin = 6;
//int latchpin = 7;


int datapin  = 6; 
int clockpin = 7;
int latchpin = 8;

// data sent to shift register
byte data = 0;
const int delayTime = 100;

void setup()
{
  pinMode(datapin,  OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
  // Serial.begin(9600);
}


void loop()
{

  // allOn();
  binaryCount();          // Bit patterns from 0 to 255
  oneAfterAnother();      // All on, all off
  oneOnAtATime();         // Scroll down the line
  pingPong();             // Like above, but back and forth
  marquee();
  randomLED();            // Blink random LEDs
  allOff();
}


void shiftWrite(int desiredPin, boolean desiredState)
{
  bitWrite(data, desiredPin, desiredState);
 
  // Now we'll actually send that data to the shift register
  // shiftOut() function does all the hard work of
  // manipulating data and clock pins to move data
  // into shift register
  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Once data is in shift register, we still need to
  // make it appear at the outputs. We'll toggle the state of
  // latchPin, which will signal shift register to "latch"
  // data to outputs
  // latch activates on high-to-low transition
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}


/*
Light one LED, delay for delayTime, then light next LED
and repeat until all LEDs are on
It will then turn them off in the reverse order
*/
void oneAfterAnother()
{
  int index;
  // Turn all LEDs on
  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);                
  }

  // Turn all LEDs off
  for (index = 7; index >= 0; index--)
  {
    shiftWrite(index, LOW);
    delay(delayTime);
  }
}

 
/*
Step through LEDs, lighting one at at time
*/
void oneOnAtATime()
{
  int index;
  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);    // turn LED on
    delay(delayTime);        
    shiftWrite(index, LOW);    // turn LED off
  }
}

 
/*
Step through LEDs, lighting one at at time in both directions
*/
void pingPong()
{
  int index;
  // forward direction
  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);    // turn LED on
    delay(delayTime);
    shiftWrite(index, LOW);     // turn LED off
  }

  // reverse direction
  for (index = 7; index >= 0; index--)
  {
    shiftWrite(index, HIGH);    // turn LED on
    delay(delayTime);
    shiftWrite(index, LOW);     // turn LED off
  }
}


/*
Turn on random LEDs
Can you modify it so it also lights them for random times?
*/
void randomLED()
{
  int count;
  for (count = 0; count <= 7; count++)
  {
    int index;
    index = random(8);       // between 0 and 7
    shiftWrite(index, HIGH); // turn LED on
    delay(delayTime);
    shiftWrite(index, LOW);  // turn LED off
  }
}


/*
Mimic "chase lights" like those around signs
*/
void marquee()
{
  int index;
  // Step through first four LEDs
  // light up one in lower 4 and one in upper 4
  for (index = 0; index <= 3; index++)
  {
    shiftWrite(index, HIGH);    // Turn a LED on
    shiftWrite(index+4, HIGH);  // Skip four, and turn that LED on
    delay(delayTime);
    shiftWrite(index, LOW);     // Turn both LEDs off
    shiftWrite(index+4, LOW);
  }
}

// Count in binary
void binaryCount()
{
  int index;

  for (index = 0; index <= 255; index++)
  {
    // Send data byte to shift register
    shiftOut(datapin, clockpin, MSBFIRST, data);
  
    // Toggle latch pin to make data appear at outputs
    digitalWrite(latchpin, HIGH);
    digitalWrite(latchpin, LOW);
    data++;
    delay(delayTime);
  }
}


// Off all LEDs for 5 sec
void allOff()
{
  int index;
  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, LOW);    // Turn a LED off
  }
  delay(delayTime*5);
}



// On all LEDs for 5 sec
void allOn()
{
  int index;
  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);    // Turn a LED on
    // Serial.print("on: ");
    // Serial.println(index);
  }
  delay(delayTime*5);
}
