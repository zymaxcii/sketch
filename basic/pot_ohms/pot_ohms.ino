// pot_ohms.ino
// https://mytectutor.com/how-to-use-a-potentiometer-with-arduino/
// compute pot's resistance in ohms

float RT = 10000;    // rated pot value 10k
float R;             // unknown resistance value R

int potPin = A0;     // pot is connected to analog 0 pin
int potValue;        // value coming from sensor
int percent;         // percentage value


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);       // convert reading to a percentage
  float voltage = potValue * (5.0 / 1023.0);      // convert to voltage 
  R = ( voltage * RT)/5.0;                        // get value of unknown resistance

  Serial.print("Analog Reading: ");
  Serial.print(potValue);
  Serial.print(", Voltage =");
  Serial.print(voltage);
  Serial.print("v, Resistance=");
  Serial.print(R);
  Serial.print(" ohms");
  Serial.print(", Percentage: ");
  Serial.print(percent);
  Serial.println("%");
  delay(1000);                    // wait a second
}
