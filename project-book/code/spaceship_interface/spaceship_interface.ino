// arduino projects book
// chapter 2
// spaceship interface

int switchState = 0;

// 3 leds on pins 3,4,5 with current limiting resistors: green, red, red
// toggle switch on pin 2 with pullup resistor: the other end to ground

void setup()
{
  Serial.begin(9600);
  pinMode(3,OUTPUT);  // led: HIGH on LOW off
  pinMode(4,OUTPUT);  
  pinMode(5,OUTPUT);  
  pinMode(2,INPUT_PULLUP);   // active low

  // initialise
  digitalWrite(3, LOW);    // off
  digitalWrite(4, LOW);    // off
  digitalWrite(5, LOW);    // off
}


void loop()
{
  switchState = digitalRead(2);
  Serial.println(switchState);

  if (switchState == HIGH)
  {
    // button is not pressed
    digitalWrite(3, HIGH);    // on
    digitalWrite(4, LOW);     // off
    digitalWrite(5, LOW);     // off
  }
  else
  {
    // if the switchState is LOW:
    // turn the green LED on
    // turn the red LEDs off
    // if the switchState is HIGH:
    // turn the green LED off
    // turn the red LEDs on: blink the 2 red leds
    // the button is pressed
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(100);
    
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(100);               // wait for a quarter second
  }
}
