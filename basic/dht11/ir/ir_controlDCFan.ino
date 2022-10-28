// ir_controlDCFan.ino
// https://howtomechatronics.com/tutorials/arduino/control-any-electronics-with-a-tv-remote-arduino-ir-tutorial/


/*  
 *  Controlling a DC Fan Speed with a TV Remote
 *  
 *  Modified IRrecvDemo example from Ken Shirriff IRremote Library
 *  Ken Shirriff
 *  https://arcfn.com
 *  
 *  Modified by Dejan Nedelkovski,
 *  www.HowToMechatronics.com 
 *  
 */
 
#include <IRremote.h>

int RECV_PIN = 8; // IR Receiver - Arduino Pin Number 8
int pwmPin = 7; // Arduino Pin Number 7 to the Base of the Transistor
int pwmValue;

IRrecv irrecv(RECV_PIN);

decode_results results;

 
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode( pwmPin, OUTPUT);  
  pwmValue = 0; // Starts the program with turned off motor
}
 
void loop() {
  
  if (irrecv.decode(&results)) {   
    
    analogWrite(pwmPin, pwmValue);
  
    if (results.value == 0xAFAF8374) { // PLAY Button
        pwmValue = 255; // 100% Duty Cycle | Max Speed
        }
    if (results.value == 0x98519C65) { // STOP Button
        pwmValue = 0; // 0% Duty Cycke | Turned off
        }
    if (results.value == 0x93F1BA08) { // FORWARD Button
        if(pwmValue <= 245){  
        pwmValue = pwmValue + 10; // Increases the Duty Cycle of the PWM Signal
        delay(20);     
      }   
    }
    if (results.value == 0x71D086FF) { // BACKWARD Button
      if(pwmValue >= 20){
        pwmValue = pwmValue - 10; // Decreases the Duty Cycle of the PWM Signal
        delay(20);    
      }
    }   
  Serial.print(pwmValue);
  Serial.print(" ");
  Serial.println(results.value, HEX);
   
  irrecv.resume(); // Receive the next value
  }
  delay(100);
}
