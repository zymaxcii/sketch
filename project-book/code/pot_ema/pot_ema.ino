// pot_ema.ino
// ema_pot2.ino
// Read potentiometer value and compute exponential moving averages (EMA)
// print to serial monitor
// note: max and min value of this pot is 0 - 923 with EMA_a = 0.01
// note: max and min value of this pot is 0 - 1021 with EMA_a = 0.6


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
int sensorPin   = A0;      // pin number to use the ADC
int sensorValue = 0;      // initialization of sensor variable, equivalent to EMA Y

// alpha between 0 and 1
// low alpha-slow response
float EMA_a = 0.6;      // initialization of EMA alpha, 0.6 original
int EMA_S = 0;           // initialization of EMA S

 
void setup()
{
  Serial.begin(9600);
  EMA_S = analogRead(sensorPin);  // set EMA S for t=1
}

 
void loop()
{
  sensorValue = analogRead(sensorPin);                // read the sensor value using ADC
  EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);    // run the EMA
  Serial.println(EMA_S);                              // print digital value to serial
  delay(50);                                          // 50ms delay
}
