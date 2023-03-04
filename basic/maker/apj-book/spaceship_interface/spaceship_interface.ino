// spaceship_interface.ino
// arduino projects book
// chapter 2
// spaceship interface

int switchState = 0;

// 3 leds on pins 2,3,4 with current limiting resistors: green, red, red
// toggle switch on pin 6 with pullup resistor: the other end to ground


void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);         // led: HIGH on LOW off
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
  pinMode(6, INPUT_PULLUP);   // switch: active low

  // initialise
  digitalWrite(2, LOW);    // off
  digitalWrite(3, LOW);    // off
  digitalWrite(4, LOW);    // off
}


void loop()
{
  switchState = digitalRead(6);
  Serial.println(switchState);

  if (switchState == HIGH)
  {
    // button is not pressed
    digitalWrite(2, HIGH);    // on
    digitalWrite(3, LOW);     // off
    digitalWrite(4, LOW);     // off
  }
  else
  {
    // if the switchState is LOW (pressed):
    // turn the green LED on
    // turn the red LEDs off
    // if the switchState is HIGH:
    // turn the green LED off
    // turn the red LEDs on: blink the 2 red leds
    // the button is pressed
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(300);
    
    // toggle the LEDs
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    delay(300);               // wait for a quarter second
  }
}
