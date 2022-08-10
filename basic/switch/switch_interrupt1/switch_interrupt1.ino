// switch_interrupt1.ino
// www.martyncurrey.com/switching-things-on-and-off-with-an-arduino/

//  Sketch: SwitchingThings_Interuupt_01
//  An  example of using an interrupt and a button switch to turn an LED on and off
//  D10 to resister and LED
//  D2 to push button switch
 
int pin_LED = 10;
int pin_switch = 2;        // pin 2 is an interrupt pin
boolean LEDstatus = LOW;
 

void setup() 
{
  Serial.begin(9600);
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
 
  pinMode(pin_LED, OUTPUT);  
  digitalWrite(pin_LED,LOW); 
  pinMode(pin_switch, INPUT); 
 
  attachInterrupt( digitalPinToInterrupt(pin_switch), blink, RISING );
}


void loop()
{
  // nothing here
}


// interrupt service routine
void blink()
{
  if (LEDstatus == LOW)
  {
    LEDstatus = HIGH;
  }
  else
  {
    LEDstatus = LOW;
  }   
  digitalWrite(pin_LED, LEDstatus);
}
