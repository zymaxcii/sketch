

int ledPin = 2;
int buttonApin = 10;

int state = 1;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
 
}

void loop() 
{
 delay(100);
  if (digitalRead(buttonApin) == LOW)
  
  {
    digitalWrite(ledPin, state);
    state = 1-state;//Recognition of different detection values
    delay(100); //Remove keystroke jitter delay
  }
  
}
