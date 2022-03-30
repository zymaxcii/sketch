// pot_rawInput.ino
// ema_pot.ino
// Read raw potentiometer value and print to serial monitor
// note: max and min value of this pot is 0 - 1008
//
//
// https://www.norwegiancreations.com/2015/10/tutorial-potentiometers-with-arduino-and-filtering/
// no ema

// Boards to run the sketch:
// my poteniometer board

// 10 kOhms
// Connect potentiometer output to analog input A0
//
// pin # Name to Uno Pin
// =====================
// 1  VCC  VCC
// 2  OUT  A0
// 3  GND GND


// Global Variables
int sensorPin   = 0;      // pin number to use the ADC
int sensorValue = 0;    // initialization of sensor variable
 
void setup()
{
    Serial.begin(9600);
}


void loop()
{
    sensorValue = analogRead(sensorPin);    // read sensor value using ADC
    Serial.println(sensorValue);            // print digital value to serial monitor
    delay(100);                             // 50ms delay
}
