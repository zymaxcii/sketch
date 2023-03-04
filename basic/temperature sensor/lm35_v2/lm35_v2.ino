// lm35_v2.ino
// Reading temperature version 2

/*
 * Tutorial 1: Reading Temperature
 * 
 * Read the temperature in celcius over serial
 *
 *
 * To see this sketch in action open up the serial
 * monitor. Clamp your fingers over the LM35
 * sensor. The temperature will rise and then fall
 * as you remove your fingers
 *
 * The circuit:
 * - LM35 to 5v, GND, and Vo to analog 0
 *
 */

// My standard hardware setup
// lm35
// ====
// Bottom facing flat side, right to left
// 1 GND
// 2 OUT A0
// 3 VCC +5V


// the output pin of the LM35 temperature sensor
int lm35Pin = A0;


void setup()
{
    // set up serial at 9600 baud   
    Serial.begin(9600);
}


void loop()
{ 
    int analogValue;
    float temperature;

    // read our temperature sensor
    analogValue = analogRead(lm35Pin);

    // convert the 10bit analog value to celcius
    temperature = float(analogValue) / 1024;            // 1023 or 1024?
    temperature = temperature * 500;

    // print the temperature over serial
    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.println("C");
    
    // wait 1s before reading the temperature again
    delay(1000);
}
