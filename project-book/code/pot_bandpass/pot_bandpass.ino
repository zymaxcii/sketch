// pot_bandpass.ino
// ema_bandpass.ino
// Don't understand what it does!
//
// https://www.norwegiancreations.com/2016/03/arduino-tutorial-simple-high-pass-band-pass-and-band-stop-filtering/

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
int sensorPin = 0;        // pin number to use the ADC
int sensorValue = 0;      // initialization of sensor variable, equivalent to EMA Y
 
float EMA_a_low = 0.3;    // initialization of EMA alpha
float EMA_a_high = 0.5;
 
int EMA_S_low = 0;        // initialization of EMA S
int EMA_S_high = 0;
 
int highpass = 0;
int bandpass = 0;
 
void setup()
{
  
  Serial.begin(9600);
   
  EMA_S_low = analogRead(sensorPin);      //set EMA S for t=1
  EMA_S_high = analogRead(sensorPin);
}


void loop()
{
  sensorValue = analogRead(sensorPin);    // read the sensor value using ADC
   
  EMA_S_low = (EMA_a_low*sensorValue) + ((1-EMA_a_low)*EMA_S_low);  // run the EMA
  EMA_S_high = (EMA_a_high*sensorValue) + ((1-EMA_a_high)*EMA_S_high);
   
  highpass = sensorValue - EMA_S_low;     // find the high-pass as before (for comparison)
  bandpass = EMA_S_high - EMA_S_low;      // find the band-pass
 
  Serial.print(highpass);
  Serial.print(" ");
  Serial.println(bandpass);
   
  delay(500);                              // 20ms delay
}
