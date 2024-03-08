// larsonScannerKitt.ino

// https://www.instructables.com/The-KITT-duino-DIY-Larson-Scanner-with-an-Arduino/
// 2024-03-07 modified for 8 leds

/*
  KITT-duino, a DIY Larson Scanner that if you already have an Arduino, should cost around $4.50 USD
  "Scans" 10 LEDs from right to left, left to right, meet in middle, left to right, right to left, meet in middle, repeat infinitly
 
  Circuitry
  * 10 LEDs, one on each pin from Pin 4 to Pin 13
  each LED has a 220 ohm resistor on the cathode side
  1 common ground wire
  created 2011
  by unonomehaha
  Last update, October 2011

  Feel free to modify, please improve and share it with me on instructables...
  Designed for use on Arduino Duemilanove 
*/

// hardware setup
// 10 leds: pins 4 to 13
// code requires consecutive pins
// cannot work with my 8 led module and mega
// hard-coded. Can modify it?
 
int timer = 75;  // Higher number = longer scan... adjust the meeting in middle to look in time if you change this number
int indLED = 75; //This is the delay on the meet in the middle sequence, updated to use an integer function


void setup()
{
  // use a for loop to initialize each pin as an output, this also takes care of digital output set-up:
  // for (int thisPin = 4; thisPin < 13; thisPin++)
  for (int thisPin = 6; thisPin < 13; thisPin++)
  {
    pinMode(thisPin, OUTPUT);      
  }
}


void loop()
{
  // loop from right to left:
  for (int thisPin = 4; thisPin < 13; thisPin++)
  { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);   
    delay(timer);                  
    // turn the pin off:
    digitalWrite(thisPin, LOW);    
  }

  // loop from left to right:
  for (int thisPin = 12; thisPin >= 4; thisPin--)
  { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  } 

  // This is where it will start on each side, meet in middle, and go back
  digitalWrite(13, HIGH);   // set the LED on
  digitalWrite(4, HIGH);
  delay(indLED);              
  digitalWrite(13, LOW);
  digitalWrite(4,LOW);  // set the LED off
  delay(0);              
  digitalWrite(12, HIGH);   // set the LED on
  digitalWrite(5, HIGH);
  delay(indLED);              
  digitalWrite(12, LOW);
  digitalWrite(5,LOW);  // set the LED off
  delay(0);              
  digitalWrite(11, HIGH);   // set the LED on
  digitalWrite(6, HIGH);
  delay(indLED);              
  digitalWrite(11, LOW);
  digitalWrite(6,LOW);  // set the LED off
  delay(0);              
  digitalWrite(10, HIGH);   // set the LED on
  digitalWrite(7, HIGH);
  delay(indLED);             
  digitalWrite(10, LOW);
  digitalWrite(7,LOW);  // set the LED off
  delay(0);              
  digitalWrite(9, HIGH);   // set the LED on
  digitalWrite(8, HIGH);
  delay(indLED);              // wait for a second
  digitalWrite(9, LOW);
  digitalWrite(8,LOW);  // set the LED off
  delay(0);             
  digitalWrite(10, HIGH);   // set the LED on
  digitalWrite(7, HIGH);
  delay(indLED);              
  digitalWrite(10, LOW);
  digitalWrite(7,LOW);  // set the LED off
  delay(0);             
  digitalWrite(11, HIGH);   // set the LED on
  digitalWrite(6, HIGH);
  delay(indLED);              
  digitalWrite(11, LOW);
  digitalWrite(6,LOW);  // set the LED off
  delay(0);             
  digitalWrite(12, HIGH);   // set the LED on
  digitalWrite(5, HIGH);
  delay(indLED);             
  digitalWrite(12, LOW);
  digitalWrite(5,LOW);  // set the LED off
  delay(0);             
  digitalWrite(13, HIGH);   // set the LED on
  digitalWrite(4, HIGH);
  delay(indLED);             
  digitalWrite(13, LOW);
  digitalWrite(4,LOW);  // set the LED off
  delay(0);              

  // loop left to right
  for (int thisPin = 13; thisPin >= 4; thisPin--) 
  { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  } 
  // loop right to left:
  for (int thisPin = 3; thisPin < 13; thisPin++) 
  { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);   
    delay(timer);                  
    // turn the pin off:
    digitalWrite(thisPin, LOW);    
  }
 
  // meet in middle again and then go back
  digitalWrite(13, HIGH);   // set the LED on
  digitalWrite(4, HIGH);
  delay(indLED);
  
  digitalWrite(13, LOW);
  digitalWrite(4,LOW);  // set the LED off
  delay(0);
  
  digitalWrite(12, HIGH);   // set the LED on
  digitalWrite(5, HIGH);
  delay(indLED);
  
  digitalWrite(12, LOW);
  digitalWrite(5,LOW);  // set the LED off
  delay(0);
  
  digitalWrite(11, HIGH);   // set the LED on
  digitalWrite(6, HIGH);
  delay(indLED);
  
  digitalWrite(11, LOW);
  digitalWrite(6,LOW);  // set the LED off
  delay(0);
  
  digitalWrite(10, HIGH);   // set the LED on
  digitalWrite(7, HIGH);
  delay(indLED);              // wait for a second
  
  digitalWrite(10, LOW);
  digitalWrite(7,LOW);  // set the LED off
  delay(0);
  
  digitalWrite(9, HIGH);   // set the LED on
  digitalWrite(8, HIGH);
  delay(indLED);
  
  digitalWrite(9, LOW);
  digitalWrite(8,LOW);  // set the LED off
  delay(0);
          
  digitalWrite(10, HIGH);   // set the LED on
  digitalWrite(7, HIGH);
  delay(indLED);
                
  digitalWrite(10, LOW);
  digitalWrite(7,LOW);  // set the LED off
  delay(0);
           
  digitalWrite(11, HIGH);   // set the LED on
  digitalWrite(6, HIGH);
  delay(indLED);
               
  digitalWrite(11, LOW);
  digitalWrite(6,LOW);  // set the LED off
  delay(0);
           
  digitalWrite(12, HIGH);   // set the LED on
  digitalWrite(5, HIGH);
  delay(indLED);              // wait for a second
  
  digitalWrite(12, LOW);
  digitalWrite(5,LOW);  // set the LED off
  delay(0);
  
  digitalWrite(13, HIGH);   // set the LED on
  digitalWrite(4, HIGH);
  delay(indLED);
  
  digitalWrite(13, LOW);
  digitalWrite(4,LOW);  // set the LED off
  delay(0);              
 } 

