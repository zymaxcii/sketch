// ino2pde.ino
// work hand in hand with pde2ino.pde in pde folder
// https://howtomechatronics.com/tutorials/arduino/processing/


// my standard pin assignments
// nano: switch on pins D2,D3,D4,D5; D2 for interrupt
// 8 leds: D6,D7,D8,D9 and D10,D11,D12,D13
// pot: A0 
int led = 6;
int button = 2;


void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop()
{
  if (Serial.available() > 0) 
  {
    char ledState = Serial.read();
    if (ledState == '1')
    {
      digitalWrite(led, HIGH);
    }

    if (ledState == '0')
    {
      digitalWrite(led, LOW);
    }
  }

  int buttonState = digitalRead(button);
  if ( buttonState == LOW)
  {
    Serial.println("Button is pressed");
    delay(500);
  }
}
