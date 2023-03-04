/* 
 * Serial RGB LED TOO
 * ------------------
 * Serial commands control the brightness of R,G,B LEDs 
 *
 * Command structure is "#RRGGBB"
 *
 *
 * Created 18 October 2006
 * copyleft 2006 Tod E. Kurt <tod@todbot.com
 * http://todbot.com/
 */

#define slen 7        // 7 characters, e.g. '#ff6666'
char serInStr[slen];  // array to hold the incoming serial string bytes

int redPin   = 9;   // Red LED,   connected to digital pin 9
int greenPin = 10;  // Green LED, connected to digital pin 10
int bluePin  = 11;  // Blue LED,  connected to digital pin 11

void setup() {
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT);
  Serial.begin(9600);
  analogWrite(redPin,   127);   // set them all to mid brightness
  analogWrite(greenPin, 127);   // set them all to mid brightness
  analogWrite(bluePin,  127);   // set them all to mid brightness
  Serial.println("enter color command (e.g. '#ff3333') :");  
}

void loop () {
  //read the serial port and create a string out of what you read
  int spos = readSerialString();

  if(spos==slen && serInStr[0] == '#') {
    long colorVal = strtol(serInStr+1,NULL,16);
    Serial.print("setting color to r:");
    Serial.print((colorVal&0xff0000)>>16);
    Serial.print(" g:");
    Serial.print((colorVal&0x00ff00)>>8);
    Serial.print(" b:");
    Serial.println((colorVal&0x0000ff)>>0);
    memset(serInStr,0,slen);      // indicates we've used this string
    //spos = 0;
    analogWrite(redPin, (colorVal&0xff0000)>>16 );
    analogWrite(greenPin, (colorVal&0x00ff00)>>8 );
    analogWrite(bluePin, (colorVal&0x0000ff)>>0 );
  }

  delay(200);  // wait a bit, for serial data
}

//read a string from the serial and store it in an array
int readSerialString () {
  int i=0;
  if(!Serial.available()) {
    return -1;
  }
  while (Serial.available() && i < slen) {
    int c = Serial.read();
      serInStr[i++] = c;
  }
  Serial.println(serInStr);
  return i;
}
