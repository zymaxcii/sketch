/*
Blink
Turns on an LED on for one second, then off for one second, repeatedly.
This example code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards
// connect an external LED with resistor to pin 13
// then change to pin D7
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);
  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // wait for a second
  digitalWrite(led, LOW);
  // turn the LED off by making the voltage LOW
  delay(1000);
  // wait for a second
}



/*
Adafruit Arduino - Lesson 3. RGB LED
*/
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}


void loop()
{
setColor(255, 0, 0); // red
delay(1000);

setColor(0, 255, 0); // green
delay(1000);

setColor(0, 0, 255); // blue
delay(1000);

setColor(255, 255, 0); // yellow
delay(1000);

setColor(80, 0, 80); // purple
delay(1000);

setColor(0, 255, 255); // aqua
delay(1000);
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif

analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}



/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void loop()
{
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}



/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register - Brightness
*/

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int outputEnablePin = 3;
byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT);
}


void loop()
{
  setBrightness(255);
  leds = 0;
  updateShiftRegister();
  delay(500);
  
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
  
  for (byte b = 255; b > 0; b--)
  {
    setBrightness(b);
    delay(50);
  }
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setBrightness(byte brightness) // 0 to 255
{
  analogWrite(outputEnablePin, 255-brightness);
}



/*
Adafruit Arduino - Lesson 5. Serial Monitor
*/

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  updateShiftRegister();
  Serial.begin(9600);

  while (! Serial); // Wait until Serial is ready - Leonardo
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

    if (ch == 'x')
    {
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}



/*
Adafruit Arduino - Lesson 6. Inputs
*/

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;
byte leds = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}


void loop()
{
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }

  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}



/*
Adafruit Arduino - Lesson 7. RGB Fader
*/

int redLEDPin = 11;
int greenLEDPin = 10;
int blueLEDPin = 9;

int redSwitchPin = 7;
int greenSwitchPin = 6;
int blueSwitchPin = 5;

int red = 0;
int blue = 0;
int green = 0;

void setup()
{
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  pinMode(redSwitchPin, INPUT_PULLUP);
  pinMode(greenSwitchPin, INPUT_PULLUP);
  pinMode(blueSwitchPin, INPUT_PULLUP);
}


void loop()
{
  if (digitalRead(redSwitchPin) == LOW)
  {
    red ++;
    if (red > 255) red = 0;
  }

  if (digitalRead(greenSwitchPin) == LOW)
  {
    green ++;
    if (green > 255) green = 0;
  }

  if (digitalRead(blueSwitchPin) == LOW)
  {
    blue ++;
    if (blue > 255) blue = 0;
  }

  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);
  delay(10);
}



/*
Adafruit Arduino - Lesson 8. Analog Inputs
*/

int potPin = 0;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  int reading = analogRead(potPin);
  Serial.println(reading);
  delay(500);
}



/*
Adafruit Arduino - Lesson 8. Analog Inputs - LEDs
*/

int potPin = 0;
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void loop()
{
  int reading = analogRead(potPin);
  int numLEDSLit = reading / 114; //1023 / 9
  leds = 0;

  for (int i = 0; i < numLEDSLit; i++)
  {
    bitSet(leds, i);
  }
  updateShiftRegister();
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}



/*
Adafruit Arduino - Lesson 9. Light sensing
*/

int lightPin = 0; // no pinMode needed
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void loop()
{
  int reading = analogRead(lightPin);
  int numLEDSLit = reading / 57; //1023 / 9 / 2

  if (numLEDSLit > 8) numLEDSLit = 8;
  leds = 0;
  // no LEDs lit to start
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i); // sets the i'th bit
  }
  updateShiftRegister();
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}



/*
Adafruit Arduino - Lesson 10. Simple Sounds
*/

int speakerPin = 12;
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C C#   D    D#   E    F    F#   G    G#   A

void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}


void loop()
{
}




/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/

int speakerPin = 12;
int photocellPin = 0;

void setup()
{
}


void loop()
{
  int reading = analogRead(photocellPin);
  int pitch = 200 + reading / 4;
  tone(speakerPin, pitch);
}


// Lesson 11 LCD Display part 1
// Examples → Liquid Crystal → HelloWorld



/*
Adafruit Arduino - Lesson 12. Light and Temperature
*/

#include <LiquidCrystal.h>

int tempPin = 0;
int lightPin = 1;

//                BS E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
lcd.begin(16, 2);
}


void loop()
{
  // Display Temperature in C
  int tempReading = analogRead(tempPin);
  float tempVolts = tempReading * 5.0 / 1024.0;
  float tempC = (tempVolts - 0.5) * 100.0;
  float tempF = tempC * 9.0 / 5.0 + 32.0;
  // ----------------
  lcd.print("Temp F ");
  lcd.setCursor(6, 0);
  lcd.print(tempF);
  
  // Display Light on second row
  int lightReading = analogRead(lightPin);
  lcd.setCursor(0, 1);
  // ----------------
  lcd.print("Light ");
  lcd.setCursor(6, 1);
  lcd.print(lightReading);
  delay(500);
}




/*
Adafruit Arduino - Lesson 13. DC Motor
*/

int motorPin = 3;

void setup()
{
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}


void loop()
{
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
}



/*
Adafruit Arduino - Lesson 14. Sweep
*/

#include <Servo.h>

int servoPin = 9;
Servo servo;
int angle = 0;
// servo position in degrees

void setup()
{
  servo.attach(servoPin);
}


void loop()
{
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)
  {
    servo.write(angle);
    delay(15);
  }

  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)
  {
    servo.write(angle);
    delay(15);
  }
}



/*
Adafruit Arduino - Lesson 14. Knob
*/

#include <Servo.h>

int potPin = 0;
int servoPin = 9;
Servo servo;

void setup()
{
  servo.attach(servoPin);
}


void loop()
{
  int reading = analogRead(potPin);  // 0 to 1023
  int angle = reading / 6;           // 0 to 180-ish
  servo.write(angle);
}



/*
Adafruit Arduino - Lesson 15. Bi-directional Motor
*/

int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int switchPin = 7;
int potPin = 0;

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}


void loop()
{
  int speed = analogRead(potPin) / 4;
  boolean reverse = digitalRead(switchPin);
  setMotor(speed, reverse);
}

void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}



/*
Adafruit Arduino - Lesson 16. Stepper
*/

#include <Stepper.h>

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  Serial.begin(9600);
  motor.setSpeed(20);
}


void loop()
{
  if (Serial.available())
  {
    int steps = Serial.parseInt();
    motor.step(steps);
  }
}

=======================================
// from youtube

// Pin definitions:

// The 74HC595 uses a type of serial connection called SPI

// (Serial Peripheral Interface) that requires three pins:

int datapin = 2; 

int clockpin = 3;

int latchpin = 4;

// We'll also declare a global variable for the data we're

// sending to the shift register:

byte data = 0;



void setup()

{

  // Set the three SPI pins to be outputs:

  pinMode(datapin, OUTPUT);

  pinMode(clockpin, OUTPUT);  

  pinMode(latchpin, OUTPUT);

}



void loop()

{

  oneAfterAnother();      // All on, all off
 

  oneOnAtATime();       // Scroll down the line
 

  pingPong();           // Like above, but back and forth

  randomLED();          // Blink random LEDs
 

  marquee();

  binaryCount();        // Bit patterns from 0 to 255

}



void shiftWrite(int desiredPin, boolean desiredState)

  bitWrite(data,desiredPin,desiredState);
 

  // Now we'll actually send that data to the shift register.

  // The shiftOut() function does all the hard work of

  // manipulating the data and clock pins to move the data

  // into the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Once the data is in the shift register, we still need to

  // make it appear at the outputs. We'll toggle the state of

  // the latchPin, which will signal the shift register to "latch"

  // the data to the outputs. (Latch activates on the high-to

  // -low transition).

  digitalWrite(latchpin, HIGH);

  digitalWrite(latchpin, LOW);

}



/*

oneAfterAnother()

This function will light one LED, delay for delayTime, then light

the next LED, and repeat until all the LEDs are on. It will then

turn them off in the reverse order.

*/

void oneAfterAnother()

{

  int index;

  int delayTime = 100; // Time (milliseconds) to pause between LEDs

                       // Make this smaller for faster switching

  // Turn all the LEDs on:
 

  // This for() loop will step index from 0 to 7

  // (putting "++" after a variable means add one to it)

  // and will then use digitalWrite() to turn that LED on.
 

  for(index = 0; index <= 7; index++)

  {

    shiftWrite(index, HIGH);

    delay(delayTime);                

  }

  // Turn all the LEDs off:

  // This for() loop will step index from 7 to 0

  // (putting "--" after a variable means subtract one from it)

  // and will then use digitalWrite() to turn that LED off.
 

  for(index = 7; index >= 0; index--)

  {

    shiftWrite(index, LOW);

    delay(delayTime);

  }

}

 

/*

oneOnAtATime()

This function will step through the LEDs, lighting one at at time.

*/

void oneOnAtATime()

{

  int index;

  int delayTime = 100; // Time (milliseconds) to pause between LEDs

                       // Make this smaller for faster switching
 

  // step through the LEDs, from 0 to 7
 

  for(index = 0; index <= 7; index++)

  {

    shiftWrite(index, HIGH);    // turn LED on

    delay(delayTime);        // pause to slow down the sequence

    shiftWrite(index, LOW);    // turn LED off

  }

}

 

/*

pingPong()

This function will step through the LEDs, lighting one at at time,

in both directions.

*/

void pingPong()

{

  int index;

  int delayTime = 100; // time (milliseconds) to pause between LEDs

                       // make this smaller for faster switching
 

  // step through the LEDs, from 0 to 7
 

  for(index = 0; index <= 7; index++)

  {

    shiftWrite(index, HIGH);    // turn LED on

    delay(delayTime);        // pause to slow down the sequence

    shiftWrite(index, LOW);    // turn LED off

  }

  // step through the LEDs, from 7 to 0
 

  for(index = 7; index >= 0; index--)

  {

    shiftWrite(index, HIGH);    // turn LED on

    delay(delayTime);        // pause to slow down the sequence

    shiftWrite(index, LOW);    // turn LED off

  }

}



/*

randomLED()

This function will turn on random LEDs. Can you modify it so it

also lights them for random times?

*/

void randomLED()

{

  int index;

  int delayTime = 100; // time (milliseconds) to pause between LEDs

                       // make this smaller for faster switching
 

  // The random() function will return a semi-random number each

  // time it is called. See http://arduino.cc/en/Reference/Random

  // for tips on how to make random() more random.
 

  index = random(8);    // pick a random number between 0 and 7
 

  shiftWrite(index, HIGH);    // turn LED on

  delay(delayTime);        // pause to slow down the sequence

  shiftWrite(index, LOW);    // turn LED off

}



/*

marquee()

This function will mimic "chase lights" like those around signs.

*/

void marquee()

{

  int index;

  int delayTime = 200; // Time (milliseconds) to pause between LEDs

                       // Make this smaller for faster switching
 

  // Step through the first four LEDs

  // (We'll light up one in the lower 4 and one in the upper 4)
 

  for(index = 0; index <= 3; index++)

  {

    shiftWrite(index, HIGH);    // Turn a LED on

    shiftWrite(index+4, HIGH);  // Skip four, and turn that LED on

    delay(delayTime);        // Pause to slow down the sequence

    shiftWrite(index, LOW);    // Turn both LEDs off

    shiftWrite(index+4, LOW);

  }

}



void binaryCount()

{

  int delayTime = 1000; // time (milliseconds) to pause between LEDs

                        // make this smaller for faster switching
 

  // Send the data byte to the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin, HIGH);

  digitalWrite(latchpin, LOW);
 

  // Add one to data, and repeat!

  // (Because a byte type can only store numbers from 0 to 255,

  // if we add more than that, it will "roll around" back to 0

  // and start over).

  data++;

  // Delay so you can see what's going on:

  delay(delayTime);

}

