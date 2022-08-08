// lazySusan.ino
// https://www.mauroalfieri.it/elettronica/photo-lazy-susan-foto-360-gradi.html
// https://www.thingiverse.com/thing:13269

// include the library code
#include <LiquidCrystal.h>
#include <Servo.h>
 
//LCD Declarations
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
int focusPin = 8;
int shutterPin = 9;
 
int directionPin = 7;
int stepPin = 6;
int speedDelay = 8;    //delay in ms between a pulse (controls rotation speed)
 
static int CW = HIGH;
static int CCW = LOW;
 
 
void setup()
{
  pinMode(shutterPin, OUTPUT);
  pinMode(focusPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin, OUTPUT);      
 
  digitalWrite(focusPin,HIGH);
  digitalWrite(shutterPin,HIGH);
 
  Serial.begin(9600);
 
  //LCDSetup
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.noCursor();
  lcd.print("    .:WPLS:.");

  lcd.setCursor(0,1);
  lcd.print("Photo Lazy Susan");
  delay(2000);
  lcd.clear();
}
 
int photosPerRotation = 10;
int photoDelay = 10;

 
void loop()
{
   int state = checkButtons();
   if (state == 0)
   {
     runSequence();
   }
   else
   {
     if (state == 3)
     {
       softReset();
     }
     else
     {
     updateDisplay();
     }
   }
}
 
 
void updateDisplay()
{
  photosPerRotation = analogRead(1) / 10;
  photoDelay = (analogRead(2) / 50) * 1000;

  lcd.setCursor(0,0);
  lcd.print("# Photos: ");
  lcd.print(photosPerRotation);
  lcd.print(" ");

  lcd.setCursor(0,1);
  lcd.print("delay: ");
  lcd.print(photoDelay / 1000);
  lcd.print(" ");
}
 
void runSequence()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Running");

  for (int i = 0; i <photosPerRotation; i++)
  {
    lcd.setCursor(0,1);
    lcd.print("Photo #");
    lcd.print(i + 1);
    lcd.print(" of");
    lcd.print(photosPerRotation);
    takePhoto();
    delay(photoDelay);
    rotateTable((double)360 / (double)photosPerRotation);
  
    if (checkButtons() == 3)
    {
      softReset();
    }
  }
 
  //complete loop
  boolean running = true;
  int timesThrough = 0;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   COMPLETE");
  
  while (running)
  {
    timesThrough++;
    if (checkButtons() == 3)
    {
      softReset();
    }
    else
    {
      if (checkButtons() == 0)
      {
        running=false;
      }
      else
        if (timesThrough > 10000)
        {
          running=false;
        }
    }
  }
}

 
int checkButtons()
{
 int returnValue = -1;
 int buttonPin = 0;            //analog pin the button is attached to
 
 int buttValue[] = {470, 398, 305, 178};
 int bufferValue = 40;
 int numButtons = 4;
 
 int reading = analogRead(buttonPin);
 for (int i = 0; i < numButtons; i++)
 {
   if (abs(reading - buttValue[i]) < bufferValue)
   {
     returnValue = i;
   }
 }
 return returnValue;
}
 
 
void takePhoto()
{
  digitalWrite(focusPin,LOW);
  delay(2000);
  digitalWrite(focusPin,HIGH);
  digitalWrite(shutterPin,LOW);
  delay(2000);
  digitalWrite(shutterPin,HIGH);
} 
 
void rotateTable(double deg)
{
   double stepsPerRotation = 2667;
 
   int stepsToTake = ((double)deg / (double)360 ) * (double)stepsPerRotation;
 
   for (int i = 0; i < stepsToTake; i++)
   {
      pulsePin(stepPin);
   }
}
 
 
void pulsePin(int pinToPulse)
{
  int delayInMicroSeconds = 500; 
 
  digitalWrite(pinToPulse, HIGH);
  delayMicroseconds(delayInMicroSeconds / 2);
  digitalWrite(pinToPulse, LOW);
  delayMicroseconds(delayInMicroSeconds / 2);
  delay(speedDelay);

  if (checkButtons() == 3)
  {
      softReset();
  }
}
 
void softReset()
{
  asm volatile ("  jmp 0");
}

