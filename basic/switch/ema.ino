// ema.ino
// https://www.norwegiancreations.com/2015/10/tutorial-potentiometers-with-arduino-and-filtering/

//Global Variables
int sensorPin = 0;      // pin number to use the ADC
int sensorValue = 0;    // initialization of sensor variable
 
void setup()
{
    Serial.begin(9600);   // setup of Serial module, 115200 bits/second
}


void loop()
{
    sensorValue = analogRead(sensorPin);    // read the sensor value using ADC
    Serial.println(sensorValue);            // print digital value to serial monitor
    delay(50);                              // 50ms delay
}

