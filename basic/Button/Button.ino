/*
 * Button
 * by DojoDave <http://www.0j0.org>
 *
 * Turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. 
 *
 * http://www.arduino.cc/en/Tutorial/Button
 */
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for a pushbutton)
int val = 0;                    // variable for reading the pin status

void setup()
{
  pinMode(ledPin, OUTPUT);             // declare LED as output
  pinMode(inputPin, INPUT_PULLUP);     // declare pushbutton as input
}


void loop()
{
  val = digitalRead(inputPin);  // read input value
  
  // check if the input is HIGH
  if (val == HIGH)
  {            
    digitalWrite(ledPin, LOW);  // turn LED OFF
  }
  else
  {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
