// switch_polling4.ino
// http://www.martyncurrey.com/switching-things-on-and-off-with-an-arduino/


//  Sketch: SwitchingThings_03a
//  An  example of using a button switch as a toggle switch to turn an LED on or off
//  now with a simple debounce
//  D10 to resister and LED
//  D2 to push button switch
 
int pin_LED = 10;
int pin_switch = 2;
 
boolean oldSwitchState  = LOW;
boolean newSwitchState1 = LOW;
boolean newSwitchState2 = LOW;
boolean newSwitchState3 = LOW;
boolean LEDstatus = LOW;


void setup() 
{
  Serial.begin(9600);
  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println(" ");
 
  pinMode(pin_LED, OUTPUT);  
  digitalWrite(pin_LED,LOW); 
  pinMode(pin_switch, INPUT); 
}


void loop()
{
  newSwitchState1 = digitalRead(pin_switch);
  delay(1);
  
  newSwitchState2 = digitalRead(pin_switch);
  delay(1);
  
  newSwitchState3 = digitalRead(pin_switch);
 
  // if all 3 values are same we can continue
  if (  (newSwitchState1==newSwitchState2) && (newSwitchState1==newSwitchState3) )
  {
    if ( newSwitchState1 != oldSwitchState ) 
    {
      // has the button switch been closed?
      if ( newSwitchState1 == HIGH )
      {
        if ( LEDstatus == LOW )
        {
          digitalWrite(pin_LED, HIGH);
          LEDstatus = HIGH; 
        }
        else
        {
          digitalWrite(pin_LED, LOW);
          LEDstatus = LOW;
        }
      }
      oldSwitchState = newSwitchState1;
    }  
  }
}
