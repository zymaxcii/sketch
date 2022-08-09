// don't know what it does

// https://www.jameco.com/Jameco/workshop/JamecoBuilds/arduino-pulse-sensor.html
// https://github.com/make-magazine/IR-Pulse-Sensor/

/*
this goes on your Arduino
for use with Processing example IRPulseSensor
*/

// holds temp vals


void setup()
{
  Serial.begin(9600);  
}


void loop()
{  
  Serial.println(analogRead(0));
}
