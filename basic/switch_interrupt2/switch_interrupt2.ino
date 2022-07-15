// switch_interrupt2.ino
// www.martyncurrey.com/switching-things-on-and-off-with-an-arduino/

//  Sketch: SwitchingThings_Interuupt_02
//  An example of using an interrupt and a button switch to turn an LED on and off
//  Now with rudimentary debounce
//  D10 to resister and LED
//  D2 to push button switch
 
int pin_LED = 10;
int pin_switch = 2;        // pin2 is an interrupt pin
volatile boolean keyPressed = false;
boolean LEDstatus = LOW;
 
// variable used for the debounce
unsigned long timeNewKeyPress = 0;
unsigned long timeLastKeyPress = 0;
unsigned int timeDebounce = 10;

 
void setup() 
{
  Serial.begin(9600);
  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println(" ");

  pinMode(pin_LED, OUTPUT);  
  digitalWrite(pin_LED,LOW); 
  pinMode(pin_switch, INPUT); 
  attachInterrupt( digitalPinToInterrupt(pin_switch), keyIsPressed, RISING );
}


void loop()
{
  if (keyPressed)
  {
    keyPressed = false;
    timeNewKeyPress = millis();

    if ( timeNewKeyPress - timeLastKeyPress >= timeDebounce)
    {
      blink();
    }
    
    timeLastKeyPress = timeNewKeyPress;
  }
}
 

// interrupt service routine 
void keyIsPressed()
{
  keyPressed = true;
}


void blink()
{
  if (LEDstatus == LOW) { LEDstatus = HIGH; } else { LEDstatus = LOW; }   
  digitalWrite(pin_LED, LEDstatus);
}
