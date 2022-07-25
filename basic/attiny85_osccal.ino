// attiny85_osscal.ino
// https://www.nu42.com/2021/02/attiny85-chirper-red-keys-liyafy-hc35.html


#include <EEPROM.h>
#include <SoftwareSerial.h>

#define TX_BAUD 300
#define TX_PIN 0

#define BUTTON_PIN 2
#define LED_PIN 4

#define LONG_WAIT 1000
#define SHORT_WAIT 250

static int initial_osccal;

static void blink_on_button_press();
static void blink_on_done();
static void blink_on_print_osccal();
static void blink_on_startup();
static void do_blink(int, int);
static void print_osccal(int);
static int restore();
static void save(int);
static int search_osccal();
static bool should_save();
static int try_osccal(int);

SoftwareSerial* comm;

static void
print_osccal(int v) {
  comm->println("\r\n*-- OSCCAL -------------------------------");
  comm->print("* At startup = ");
  comm->println(initial_osccal);
  comm->print("* Current = ");
  comm->println(v);
  comm->println("*--- Press button to save in EEPROM ------\r\n");
}

static void
save(int v)
{
  EEPROM.update(0, 'O');
  EEPROM.update(1, 'S');
  EEPROM.update(2, 'C');
  EEPROM.update(3, (byte)(v & 0xff));
}

static int
restore()
{
  // Check signature to avoid bogus values
  if (
    (EEPROM.read(0) == 'O') &&
    (EEPROM.read(1) == 'S') &&
    (EEPROM.read(2) == 'C')
    )
  {
    return EEPROM.read(3);
  }
  return -1;
}

static bool
should_save()
{
  // Figure out what this should do
  return false;
}

static int
try_osccal(int v)
{
  if ((v < 0) || (v > 255)) return -1;

  OSCCAL = v;
  print_osccal(v);
  blink_on_print_osccal();
  delay(SHORT_WAIT);
  
  if (should_save()) return v;

  return -1;
}

static int
search_osccal()
{
  // Maybe the initial value is good.
  if (try_osccal(initial_osccal) >= 0) return initial_osccal;

  int anchor = initial_osccal;
  int limit = max(initial_osccal, 255 - initial_osccal);
  int x;

  // Search up and down
  for (int i = 1; i < limit; ++i) {
    if ((x = try_osccal(anchor + i)) >= 0) return x;
    if ((x = try_osccal(anchor - i)) >= 0) return x;
  }
  return -1;
}

static void
do_blink(int times, int delta)
{
  for (int i = 0; i < times; ++i)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(delta);
    digitalWrite(LED_PIN, LOW);
    delay(delta);
  }
}

static void
blink_on_button_press()
{
  do_blink(25, 20);
}

static void
blink_on_done()
{
  do_blink(50, LONG_WAIT/50);
}

static void
blink_on_print_osccal()
{
  do_blink(8, LONG_WAIT/8);
}

static void
blink_on_startup()
{
  do_blink(75, LONG_WAIT/75);
}

void
setup() {
  blink_on_startup();

  initial_osccal = restore();
  if (initial_osccal < 0)
  {
    initial_osccal = OSCCAL;
  }

  OSCCAL = initial_osccal;

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  comm = new SoftwareSerial(-1, TX_PIN);
  comm->begin(TX_BAUD);

  delay(5000);
  blink_on_startup();
}

void
loop() {
  int good_osccal;

  while ((good_osccal = search_osccal()) < 0)
  {
    // Spin until desired value is determined
  }

  save(good_osccal);
  OSCCAL = good_osccal;
  blink_on_done();
  comm->print("OSCCAL value = ");
  comm->print(good_osccal);
  comm->println("should be saved now.");
}
