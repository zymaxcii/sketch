// test_interrupt.ino

int pin = 2;   //define interrupt pin to 2

volatile int state = LOW;


void setup()
{
   pinMode(13, OUTPUT); //set pin 13 as output
   attachInterrupt(digitalPinToInterrupt(pin), blink, CHANGE);
   //interrupt at pin 2 blink ISR when pin to change the value
} 
void loop() { 
   digitalWrite(13, state); //pin 13 equal the state value
} 

void blink() { 
   //ISR function
   state = !state; //toggle the state when the interrupt occurs
}

