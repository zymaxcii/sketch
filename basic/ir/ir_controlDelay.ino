// ir_controlDelay.ino
// https://howtomechatronics.com/tutorials/arduino/control-any-electronics-with-a-tv-remote-arduino-ir-tutorial/


/*  
 *  Controlling High Voltage Home Appliances with a TV Remote
 *  
 *  Modified IRrecvDemo example from Ken Shirriff IRremote Library
 *  Ken Shirriff
 *  https://arcfn.com
 *  
 *  Modified by Dejan,
 *  www.HowToMechatronics.com 
 *  
 */
 
#include <IRremote.h>

int RECV_PIN = 8;
int relayOut = 7;
int buttonState ;

IRrecv irrecv(RECV_PIN);

decode_results results;

 
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode( relayOut, OUTPUT); 
  buttonState = HIGH; // Starts the program with turned off Relay. The relay input works inversly so HIGH state means deactivated relay

}
 
void loop() {
  
  buttonState = digitalRead(relayOut);
        
  if (irrecv.decode(&results)) {   
    
    if (results.value == 0xAFAF8374) { // PLAY Button
        digitalWrite(relayOut, LOW); // Activates the relay
        }
    if (results.value == 0x98519C65) { // STOP Button
        digitalWrite(relayOut, HIGH); // Deactivates the relay
        }   
  
  irrecv.resume(); // Receive the next value
  }
  
  Serial.print(" ");
  Serial.println(results.value, HEX);
   
  
  delay(100);
}
