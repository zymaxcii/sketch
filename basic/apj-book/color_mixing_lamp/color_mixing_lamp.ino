// color_mixing_lamp.ino
// arduino project book
// chapter 4
// color mixing lamp

// rgb led connected to pins 9, 10, 11: cathode to ground
// good to have Pin in variable names?

// should use #define
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

// 3 photoresistors connected to A1, A2, A3
// the other end to +5v?
const int redSensorPin = A1;
const int greenSensorPin = A2;
const int blueSensorPin = A3;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int   redSensorValue = 0;
int greenSensorValue = 0;
int  blueSensorValue = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin,   OUTPUT);
  pinMode(blueLEDPin,  OUTPUT);
}


void loop()
{
  // get the 3 sensor values
  redSensorValue   = analogRead(redSensorPin);   delay(5);
  greenSensorValue = analogRead(greenSensorPin); delay(5);
  blueSensorValue  = analogRead(blueSensorPin); 
  
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  // convert 0-1023 to 0-255
  redValue   = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue  = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  // write the sensor values to rgb led
  analogWrite(redLEDPin,   redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin,  blueValue);

  delay(500);
}
