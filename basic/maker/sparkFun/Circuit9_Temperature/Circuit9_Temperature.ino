/*
SparkFun Tinker Kit
Circuit 9: Temperature Sensor

Use the "serial monitor" window to read a temperature sensor.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/activity-guide-for-sparkfun-tinker-kit/
Download drawings and code at: https://github.com/sparkfun/SparkFun_Tinker_Kit_Code/

*/

//analog input pin constant
const int tempPin = 0;

//raw reading variable
int tempVal;

//voltage variable
float volts;

//final temperature variables
float tempC;
float tempF;

void setup()
{
  // start the serial port at 9600 baud
  Serial.begin(9600);
}


void loop()
{
 //read the temp sensor and store it in tempVal
 tempVal = analogRead(tempPin);

 //print out the 10 value from analogRead
 Serial.print("TempVal = ");
 Serial.print(tempVal);

 //print a spacer  
 Serial.print(" **** ");

 //converting that reading to voltage by multiplying the reading by 5V (voltage of       //the RedBoard)
 volts = tempVal * 5;
 volts /= 1023.0;

 //print out the raw voltage over the serial port
 Serial.print("volts: ");
 Serial.print(volts, 3);

 //print out divider
 Serial.print(" **** ");

 //calculate temperature celsius from voltage
 //equation found on the sensor spec.
 tempC = (volts - 0.5) * 100 ;

// print the celcius temperature over the serial port
Serial.print(" degrees C: ");
Serial.print(tempC);

//print spacer
 Serial.print(" **** ");

// Convert from celcius to fahrenheit
tempF = (tempC * 9.0 / 5.0) + 32.0;

//print the fahrenheit temperature over the serial port
Serial.print(" degrees F: ");
Serial.println(tempF);

//wait a bit before taking another reading
delay(1000);
}

