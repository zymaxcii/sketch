// max7219_clock1.ino
// using DS3231 RTC and max7219
// cannot figure out how many max7219 used
// Not using any MAX7219 library?

//////////////// Code by Digital Electronics Circuits Lab //////////////////////////////

/*This code required adafruit RTC library to work with DS3231
 * Please subscribe to my Youtube channel "Digital Electronics Circuits Lab"
 * This is version 0.1 of the projects and has many scope for improvement.
 * Using this code for any commercial purpose or advertisement is strictly prohibited and may led to copyright claims.
 * The project is just a demonstration and can be used only for development purpose.
 * Visit my website www.digitaleclab.com for more projects and tutorials.
*/


#include <RTClib.h>

RTC_DS3231 rtc;

#define MAX7219_DIN 12
#define MAX7219_CS  11
#define MAX7219_SCK 10

#define DISPLAY_MODE 0x0F
#define SDN_MODE     0x0C
#define DECODE_MODE  0x09
#define INTENSITY    0x0A
#define SCAN_LIMIT   0x0B

int tempC;
int my_str [16];
int digit_code = 0;


void setup()
{
  initialise();
  rtc.begin();
  
  if (rtc.lostPower())
  {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));   // to set current date and time from PC
    // rtc.adjust(DateTime(YYYY, MM, DD, hh, mm, ss)) // use this line to set time and date manually
  }
}


void initialise()
{
  digitalWrite(MAX7219_CS, HIGH);
  pinMode(MAX7219_DIN, OUTPUT);
  pinMode(MAX7219_CS, OUTPUT);
  pinMode(MAX7219_SCK, OUTPUT);
  out(DISPLAY_MODE, 0x00, DISPLAY_MODE, 0x00);
  out(SDN_MODE, 0x01, SDN_MODE, 0x01);
  out(DECODE_MODE, 0xff, DECODE_MODE, 0xff);
  out(INTENSITY, 0x0f, INTENSITY, 0x0f);              // change the hex values to adjust brightness. 0x00 is minimum and 0x0f is maximum.
  out(SCAN_LIMIT, 0x07, SCAN_LIMIT, 0x07);
}


void out(byte address1, byte data1, byte address2, byte data2)
{
  digitalWrite(MAX7219_CS, LOW);
  shiftOut(MAX7219_DIN, MAX7219_SCK, MSBFIRST, address1); // send address
  shiftOut(MAX7219_DIN, MAX7219_SCK, MSBFIRST, data1);    // send data
  shiftOut(MAX7219_DIN, MAX7219_SCK, MSBFIRST, address2); // send address
  shiftOut(MAX7219_DIN, MAX7219_SCK, MSBFIRST, data2);    // send data
  digitalWrite(MAX7219_CS, HIGH);
}


void loop()
{
  DateTime now = rtc.now();
  
  if (now.hour() < 10)
  {
    my_str[0] = 0;
    my_str[1] = now.hour();
  }
  else
  {
    my_str[0] = now.hour() / 10;
    my_str[1] = now.hour() % 10;
  }
  
  if (now.minute() < 10) {
    my_str[2] = 0;
    my_str[3] = now.minute();
  } else {
    my_str[2] = now.minute() / 10;
    my_str[3] = now.minute() % 10;
  }

  if (now.second() < 10) {
    my_str[4] = 0;
    my_str[5] = now.second();
  } else {
    my_str[4] = now.second() / 10;
    my_str[5] = now.second() % 10;
  }

  if (now.day() < 10) {
    my_str[6] = 0;
    my_str[7] = now.day();
  } else {
    my_str[6] = now.day() / 10;
    my_str[7] = now.day() % 10;
  }
  
  if (now.month() < 10) {
    my_str[8] = 0;
    my_str[9] = now.month();
  } else {
    my_str[8] = now.month() / 10;
    my_str[9] = now.month() % 10;
  }
  
  my_str [10] = now.year() / 1000;
  my_str [11] = (now.year() / 100) % 10;
  my_str [12] = (now.year() / 10) % 10;
  my_str [13] = now.year() % 10;

  tempC = rtc.getTemperature();
  my_str [14] = tempC / 10;
  my_str [15] = tempC % 10;
  
  out(0x01, digits(my_str[8]),  0x01, digits(my_str[0]));
  out(0x02, digits(my_str[9]),  0x02, digits(my_str[1]));
  out(0x03, digits(my_str[10]), 0x03, digits(my_str[2]));
  out(0x04, digits(my_str[11]), 0x04, digits(my_str[3]));
  out(0x05, digits(my_str[12]), 0x05, digits(my_str[4]));
  out(0x06, digits(my_str[13]), 0x06, digits(my_str[5]));
  out(0x07, digits(my_str[14]), 0x07, digits(my_str[6]));
  out(0x08, digits(my_str[15]), 0x08, digits(my_str[7]));
}


int digits(int x)
{
  switch (x)
  {
    case 0:
      digit_code = 0x00;
      break;
    case 1:
      digit_code = 0x01;
      break;
    case 2:
      digit_code = 0x02;
      break;
    case 3:
      digit_code = 0x03;
      break;
    case 4:
      digit_code = 0x04;
      break;
    case 5:
      digit_code = 0x05;
      break;
    case 6:
      digit_code = 0x06;
      break;
    case 7:
      digit_code = 0x07;
      break;
    case 8:
      digit_code = 0x08;
      break;
    case 9:
      digit_code = 0x09;
      break;
  }
  return digit_code;
}
