// ema_filter.ino
// https://www.norwegiancreations.com/2016/01/tutorial-multiple-values-in-the-arduino-ide-serial-plotter/

#include <Servo.h>
 
Servo myservo;          // create servo object
 
//Global Variables
int sensorPin   = 0;    // pin number to use the ADC
int sensorValue = 0;    // initialization of sensor variable, equivalent to EMA Y
float EMA_a = 0.06;     // initialization of EMA alpha
int EMA_S = 0;          // initialization of EMA S
int EMA_S_map = 0;      // initialization of variable for servo control
 
void setup()
{
    Serial.begin(9600);                 // setup of Serial module, 115200 bits/second
    EMA_S = analogRead(sensorPin);      // set EMA S for t=1
    myservo.attach(3);                  // servo initialization
}


void loop()
{
    sensorValue = analogRead(sensorPin);                // read the sensor value using ADC
    EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);    // run the EMA
 
    Serial.print(sensorValue);                          // the first variable for plotting
    Serial.print(",");                                  // seperator
    Serial.println(EMA_S);                              // the second variable for plotting including line break
   
    EMA_S_map = map(EMA_S, 0, 1023, 0, 180);            // map ADC values to servo values (0-180)
    myservo.write(EMA_S_map);                           // send the latest value to the servo
   
    delay(20);                                          // 20ms delay
}

