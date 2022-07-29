// attiny85_calib.ino
// https://www.nu42.com/2021/02/attiny85-chirper-red-keys-liyafy-hc35.html
// what is this?

#include <SoftwareSerial.h>

SoftwareSerial comm(-1, 0);

static const int anchor = 128;

void print_osccal(int v)
{
  comm.println(F("********************************"));
  comm.print(F("OSCCAL = "));
  comm.println(v);
  comm.println(F("********************************"));
}


void setup()
{
  delay(5000);
  comm.begin(300);
  OSCCAL = anchor;
  print_osccal(anchor);
  delay(5000);
}


void loop()
{
  int x;
  
  for (int i = 1; i < 128; ++i)
  {
    x = anchor + i;
    OSCCAL = x;
    print_osccal(x);
    delay(1000);
    
    x = anchor - i;
    OSCCAL = x;
    print_osccal(x);
    delay(1000);
  }
}
