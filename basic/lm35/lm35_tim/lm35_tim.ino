// lm35_tim.ino
// lm35 connected to A0
// Display temperature readings in serial monitor

// https://www.timdejong.nl/blog/get-accurate-temperature-lm35-arduino-correctly


// My standard hardware setup
// lm35
// ====
// Bottom facing flat side, right to left
// 1 GND
// 2 OUT A0
// 3 VCC +5V


float tempC;
float tempF;

int reading;
float referenceVoltage;

int tempPin = 0;           // Analog pin connected to LM35


void setup()
{
  Serial.begin(9600);

  // Set Analog reference to 1.1V
  // this gives more accuracy since the sensor will output 0-1 V
  // This only available on ATmega168 or ATmega328
  // http://arduino.cc/en/Reference/AnalogReference
  analogReference(INTERNAL);
  
  // Set to 5, 3.3, 2.56 or 1.1 depending on analogReference Setting
  referenceVoltage = 1.1;
}


void loop()
{
  reading = 0;
  
  for (int i = 0; i < 10; i++)
  {
    // Average 10 readings for accurate reading
    reading += analogRead(tempPin); 
    delay(20);
  }

  // A lot of examples divide the sensor reading by 1024
  // This is incorrect and should be 1023
  // There are 1024 values including 0 so this should be 1023
  tempC =  (referenceVoltage * reading * 10) / 1023; 
  
  // Convert to Fahrenheit
  tempF = (tempC * 9 / 5) + 32;
  
  Serial.print(tempC, 1);     // Print one decimal, not accurate enough for two
  Serial.println(" C");
  
  Serial.print(tempF, 1);     // Print one decimal, not accurate enough for two
  Serial.println(" F");
  
  Serial.println(" ");
  delay(1500);
}
