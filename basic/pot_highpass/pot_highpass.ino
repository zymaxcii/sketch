// pot_highpass.ino
// ema_highpass.ino
//
// Highpass filter
// Don't understand what it does!

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
int sensorPin = 0;    // pin number to use the ADC
int sensorValue = 0;  // initialization of sensor variable, equivalent to EMA Y
float EMA_a = 0.3;    // initialization of EMA alpha
int EMA_S = 0;        // initialization of EMA S
int highpass = 0;
 
void setup()
{
  Serial.begin(9600);
  EMA_S = analogRead(sensorPin);     // set EMA S for t=1
}


void loop()
{
  sensorValue = analogRead(sensorPin);              // read the sensor value using ADC
  EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);  // run the EMA
  highpass = sensorValue - EMA_S;                   // calculate the high-pass signal
 
  Serial.println(highpass);
  delay(20);                                        // 20ms delay
}
