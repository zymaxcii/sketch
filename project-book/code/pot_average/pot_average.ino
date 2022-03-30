// pot_average.ino
//
// https://arduino.stackexchange.com/questions/69473/ignoring-potentiometer-value-variations
// will not compile



unsigned int AvgPot = analogRead(A0);        // initialize pot average

// Exponential averaging functions
int16_t xpavg(int16_t newdat, int16_t avg)
{
  // (3 * avg + 1 * newdat) / 4
  return( (((avg<<2) - avg + newdat) + 2) >> 2 );
}


void setup()
{
   ;    // initializations go here
}


void loop()
{
   int hue = analogRead(A0);
   hue = xpavg(A0, PotAvg);
   int mappedHue = map(hue, 0, 1023, 0, 65535);

   neoPixelStrip.fill(neoPixelStrip.gamma32(neoPixelStrip.ColorHSV(mappedHue, 255, 255)));
   neoPixelStrip.show();
}
