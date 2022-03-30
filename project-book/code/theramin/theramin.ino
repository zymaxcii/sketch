// theramin.ino
// chapyter 6
// theramin

// connect led to pin 13 or use internal led
// connect potentiometer to A0
// connect buzzer to pin 8: the other end to +5v?


int sensorValue;

int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 3;  // original 13


void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);  // turn on to indicate setup mode

  // 5 secs for calibrating the range: adjust the min and max
  while (millis() < 5000)
  {
    sensorValue = analogRead(A1);    // photoresistor

    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  
  digitalWrite(ledPin, LOW);  // turn off led: setup mode off
}


void loop() 
{
  sensorValue = analogRead(A1);
  Serial.println(sensorValue);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  
  tone(8, pitch, 50);   // original 20
  
  delay(100);
}
