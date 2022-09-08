// test_pot.ino

float RT = 10000;  // the rated potentiometer value 10k
float R;           // the unknown resistance value R

int potPin = A0; // potentiometer is connected to analog 0 pin
int potValue;    // variable used to store the value coming from the sensor
int percent;     // variable used to store the percentage value

void setup()
{
  Serial.begin(9600); // initialize the serial communication
}


void loop()
{
  // get a reading from the potentiometer, assign the name potValue
  potValue = analogRead(potPin); 
  percent = map(potValue, 0, 1023, 0, 100); // convert reading to a percentage
  float voltage = potValue * (5.0 / 1023.0);  // convert to voltage 
  R = ( voltage * RT)/5.0;   // get value of unknown resistance

  Serial.print("Analog Reading: "); // print out the analog value from A0
  Serial.print(potValue);
  Serial.print(", Voltage =");// prints the text "Voltage ="
  Serial.print(voltage);
  Serial.print("v, Resistance="); //prints the text "Resistance ="
  Serial.print(R);
  Serial.print(" ohms");
  Serial.print(", Percentage: "); // print out the percentage
  Serial.print(percent);
  Serial.println("%");
  delay(1000);           // wait a second
}
