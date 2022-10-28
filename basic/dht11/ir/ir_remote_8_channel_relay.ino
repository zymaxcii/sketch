// https://srituhobby.com/how-to-use-ir-receiver-and-ir-remote-ir-receiver-module/
// control an 8-channel relay module using an IR receiver and an IR remote
// with IRremote 2.2.3

#include <IRremote.h>
#define PIN 2
#define Relay1 3
#define Relay2 4
#define Relay3 5
#define Relay4 6
#define Relay5 7
#define Relay6 8
#define Relay7 9
#define Relay8 10
IRrecv irrecv(PIN);
decode_results results;

#define remotevalue1 ""
#define remotevalue2 ""
#define remotevalue3 ""
#define remotevalue4 ""
#define remotevalue5 ""
#define remotevalue6 ""
#define remotevalue7 ""
#define remotevalue8 ""

byte relay1 = 0;
byte relay2 = 0;
byte relay3 = 0;
byte relay4 = 0;
byte relay5 = 0;
byte relay6 = 0;
byte relay7 = 0;
byte relay8 = 0;
long value;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);

  for (int a = 3; a <= 10; a++ ) {
    digitalWrite(a, HIGH);
  }

}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    value = (results.value);
    irrecv.resume();
  }
  delay(400);

  if (value == remotevalue1  && relay1 == 0 ) {
    digitalWrite(Relay1, LOW);
    relay1 = 1;
    value = 0;
  } else if (value == remotevalue1 && relay1 == 1 ) {
    digitalWrite(Relay1, HIGH);
    relay1 = 0;
    value = 0;
  }

  if (value == remotevalue2 && relay2 == 0 ) {
    digitalWrite(Relay2, LOW);
    relay2 = 1;
    value = 0;
  } else if (value == remotevalue2 && relay2 == 1 ) {
    digitalWrite(Relay2, HIGH);
    relay2 = 0;
    value = 0;

  }


  if (value == remotevalue3 && relay3 == 0 ) {
    digitalWrite(Relay3, LOW);
    relay3 = 1;
    value = 0;
  } else if (value == remotevalue3 && relay3 == 1 ) {
    digitalWrite(Relay3, HIGH);
    relay3 = 0;
    value = 0;
  }


  if (value == remotevalue4 && relay4 == 0 ) {
    digitalWrite(Relay4, LOW);
    relay4 = 1;
    value = 0;
  } else if (value == remotevalue4 && relay4 == 1 ) {
    digitalWrite(Relay4, HIGH);
    relay4 = 0;
    value = 0;
  }


  if (value == remotevalue5 && relay5 == 0 ) {
    digitalWrite(Relay5, LOW);
    relay5 = 1;
    value = 0;
  } else if (value == remotevalue5 && relay5 == 1 ) {
    digitalWrite(Relay5, HIGH);
    relay5 = 0;
    value = 0;
  }



  if (value == remotevalue6 && relay6 == 0 ) {
    digitalWrite(Relay6, LOW);
    relay6 = 1;
    value = 0;
  } else if (value == remotevalue6 && relay6 == 1 ) {
    digitalWrite(Relay6, HIGH);
    relay6 = 0;
    value = 0;
  }

  if (value == remotevalue7 && relay7 == 0 ) {
    digitalWrite(Relay7, LOW);
    relay7 = 1;
    value = 0;
  } else if (value == remotevalue7 && relay7 == 1 ) {
    digitalWrite(Relay7, HIGH);
    relay7 = 0;
    value = 0;
  }


  if (value == remotevalue8 && relay8 == 0 ) {
    digitalWrite(Relay8, LOW);
    relay8 = 1;
    value = 0;
  } else if (value == remotevalue8 && relay8 == 1 ) {
    digitalWrite(Relay8, HIGH);
    relay8 = 0;
    value = 0;
  }
}
