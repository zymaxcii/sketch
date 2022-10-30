// 8led_pendulum.ino

// https://www.instructables.com/Arduino-led-pendulum/

// with normal leds on breadboard
// int led1 = 13;
// int led2 = 12;
// int led3 = 11;
// int led4 = 10;
// int led5 = 9;
// int led6 = 8;

// with the 8 led module and mega
int led1 = 53;
int led2 = 51;
int led3 = 49;
int led4 = 47;
int led5 = 45;
int led6 = 43;


// the setup routine runs once when you press reset:
void setup()
{               
  // initialize the digital pins as outputs.
  pinMode(led1, OUTPUT);    
  pinMode(led2, OUTPUT);    
  pinMode(led3, OUTPUT);    
  pinMode(led4, OUTPUT);    
  pinMode(led5, OUTPUT);    
  pinMode(led6, OUTPUT);    
}


void loop()
{
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                 // wait for a second
  digitalWrite(led6, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                 // wait for a second
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                 // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                 // wait for a second
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                 // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                 // wait for a second
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                 // wait for a second
  digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                 // wait for a second
  digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                 // wait for a second
  digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                 // wait for a second
  digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                 // wait for a second
  digitalWrite(led5, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                 // wait for a second
  digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);  

  digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);  
  digitalWrite(led6, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);  
  digitalWrite(led5, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);  
  digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);  
  digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
}

