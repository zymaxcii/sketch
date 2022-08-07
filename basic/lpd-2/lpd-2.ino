// ldp-2.ino
// light dependent photoresistor

// https://www.jakelectronics.com/blog/photoresistor-basics-and-arduino-tutorial

#define AD5 A5             // Define analog port A5
#define LED 13             // Define digital port 13

int Intensity = 0;         // Illuminance value


void setup()
{
   pinMode(LED, OUTPUT);   // Set LED to output mode
   Serial.begin(9600);     // Set baud rate 9600
}


void loop()
{
   Intensity = analogRead(AD5);     // Read the value of analog port AD5 and save it in the Intensity variable
   Serial.print("Intensity = ");    // Serial output "Intensity = "
   Serial.println(Intensity);       // The serial port outputs the value of the Intensity variable and wraps
   delay(500); //Delay 500ms
}
