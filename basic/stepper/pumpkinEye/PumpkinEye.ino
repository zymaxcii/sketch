#include <Servo.h>

Servo s;

int pos[] = {  90,  80,   65,  120, 105,  110,  98,  68,  84,  74};
int d[] =   {3000, 500, 1200, 1530, 700,  200, 800, 450, 300, 670};

void setup() {
  s.attach(6); // <---- Change 6 to the pin you're using
}

void loop() {
  for (int i = 0; i < 10; i++) {
    s.write(pos[i]);
    delay(d[i]);
  }
}

// This code is public domain. Use it however you'd like. Attribution
// to Scott Bezek and the build video (https://youtu.be/tyLo3LW5UCo)
// is always appreciated.
