// tft_showBMP.ino
// status: compile , upload 
// compilation error, to delete

// https://github.com/thisissihab/display-image-in-tft-display-arduino-mega-mcufriend
// https://www.youtube.com/watch?v=gN1B9ZesZ1Q


/*
# display-image-in-tft-display-arduino-mega-mcufriend
this program for displaying pictures in TFT lcd display is presented. Arduino mega is used for this purpose. TFT shield is easy to use with arduino uno but we can also use it with arduino mega with very small changes. MCUFRIEND library is used for the tft lcd display control purpose. This is one of the easiest tft lcd library to work with. The process for display picture in TFT display using arduino mega is as follows:
1. Resize the image and convert it to BMP format
2. Upload the image to the sd card
3. Insert the sd card to the 2.4 inch TFT lcd display shield 
4. Install the necessary libraries and make the instructed changes
5. Upload the given code to the arduino mega 
It's done....enjoy!
Watch the video to learn more: https://youtu.be/gN1B9ZesZ1Q
*/


// MCUFRIEND UNO shields have microSD on pins 10, 11, 12, 13
// The official <SD.h> library only works on the hardware SPI pins
// e.g. 11, 12, 13 on a Uno
// e.g. 50, 51, 52 on a Mega2560
// e.g. 74, 75, 76 on a Due
//
// if you are not using a UNO,  you must use Software SPI:
//
// install v1.0.1 of the <SdFat.h> library with the Arduino Library Manager.
// edit the src/SdFatConfig.h file to #define ENABLE_SOFTWARE_SPI_CLASS 1
//
// copy all your BMP files to the root directory on the microSD with your PC
// (or another directory)


#include <SPI.h>             // f.k. for Arduino-1.5.2
#define USE_SDFAT
#include <SdFat.h>           // Use the SdFat library

SdFatSoftSpi<12, 11, 13> SD; // Bit-Bang on the Shield pins

#include <Adafruit_GFX.h>    // Hardware-specific library
#include <MCUFRIEND_kbv.h>


MCUFRIEND_kbv tft;

#define SD_CS     10
#define NAMEMATCH ""         // "" matches any name
//#define NAMEMATCH "tiger"  // *tiger*.bmp
#define PALETTEDEPTH   8     // support 256-colour Palette

char namebuf[32] = "/";      // BMP files in root directory
//char namebuf[32] = "/bitmaps/";  //BMP directory e.g. files in /bitmaps/*.bmp


File root;
int pathlen;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


void setup()
{
    uint16_t ID;
    Serial.begin(9600);
    Serial.print("Show BMP files on TFT with ID:0x");

    ID = tft.readID();
    Serial.println(ID, HEX);

    if (ID == 0x0D3D3) ID = 0x9481;
    tft.begin(ID);
    tft.fillScreen(WHITE);
    tft.setTextColor(0xFFFF, 0x0000);
    bool good = SD.begin(SD_CS);

    if (!good)
    {
        Serial.print(F("cannot start SD"));
        while (1);
    }
    root = SD.open(namebuf);
    pathlen = strlen(namebuf);
    
//    char *nm = namebuf + pathlen;
//    File f = root.openNextFile();
//    uint8_t ret;
//    uint32_t start;
//    if (f != NULL) {
//    #ifdef USE_SDFAT
//            f.getName(nm, 32 - pathlen);
//    #else
//            strcpy(nm, (char *)f.name());
//    #endif
//        f.close();
//        strlwr(nm);
//        if (strstr(nm, ".bmp") != NULL && strstr(nm, NAMEMATCH) != NULL) {
//            Serial.print(namebuf);
//            Serial.print(F(" - "));
//            tft.fillScreen(0);
//            start = millis();
//            ret = showBMP(namebuf, 5, 5);
//            
//        }
//    }
}


void loop()
{
    showBMP("apple logo.bmp", 38, 60);
    tft.drawRoundRect(45, 240, 150, 20, 5, BLACK);
    tft.setCursor(52, 210);
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.println("iOS Loading");
    delay(1000);
    
    for (int i=0; i<150; i+=10)
    {
      tft.fillRoundRect(45, 240, 10+i, 20, 5,  BLACK);
      delay(100);
    }
    
    delay(5000);
    tft.fillScreen(WHITE);
}


#define BMPIMAGEOFFSET 54
#define BUFFPIXEL      20

uint16_t read16(File& f)
{
    uint16_t result;         // read little-endian
    f.read(&result, sizeof(result));
    return result;
}


uint32_t read32(File& f)
{
    uint32_t result;
    f.read(&result, sizeof(result));
    return result;
}


uint8_t showBMP(char *nm, int x, int y)
{
    File bmpFile;
    int bmpWidth, bmpHeight;    // W+H in pixels
    uint8_t bmpDepth;           // Bit depth (currently must be 24,16,8,4,1)
    uint32_t bmpImageoffset;    // Start of image data in file
    uint32_t rowSize;           // Not always = bmpWidth; may have padding
    uint8_t sdbuffer[3 * BUFFPIXEL];    // pixel in buffer (R+G+B per pixel)
    uint16_t lcdbuffer[(1 << PALETTEDEPTH) + BUFFPIXEL], *palette = NULL;
    uint8_t bitmask, bitshift;
    boolean flip = true;        // BMP is stored bottom-to-top
    int w, h, row, col, lcdbufsiz = (1 << PALETTEDEPTH) + BUFFPIXEL, buffidx;
    uint32_t pos;               // seek position
    boolean is565 = false;      //

    uint16_t bmpID;
    uint16_t n;                 // blocks read
    uint8_t ret;

    if ((x >= tft.width()) || (y >= tft.height()))
        return 1;               // off screen

    bmpFile = SD.open(nm);      // Parse BMP header
    bmpID = read16(bmpFile);    // BMP signature
    (void) read32(bmpFile);     // Read & ignore file size
    (void) read32(bmpFile);     // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile);       // Start of image data
    (void) read32(bmpFile);     // Read & ignore DIB header size
    bmpWidth = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    n = read16(bmpFile);        // # planes -- must be '1'
    bmpDepth = read16(bmpFile); // bits per pixel
    pos = read32(bmpFile);      // format
    if (bmpID != 0x4D42) ret = 2; // bad ID
    else if (n != 1) ret = 3;   // too many planes
    else if (pos != 0 && pos != 3) ret = 4; // format: 0=uncompressed, 3=565
    else if (bmpDepth < 16 && bmpDepth > PALETTEDEPTH) ret = 5; // palette 
    else {
        bool first = true;
        is565 = (pos == 3);               // ?already in 16-bit format
        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * bmpDepth / 8 + 3) & ~3;
        if (bmpHeight < 0) {              // If negative, image is in top-down order.
            bmpHeight = -bmpHeight;
            flip = false;
        }

        w = bmpWidth;
        h = bmpHeight;
        if ((x + w) >= tft.width())       // Crop area to be loaded
            w = tft.width() - x;
        if ((y + h) >= tft.height())      //
            h = tft.height() - y;

        if (bmpDepth <= PALETTEDEPTH) {   // these modes have separate palette
            //bmpFile.seek(BMPIMAGEOFFSET); //palette is always @ 54
            bmpFile.seek(bmpImageoffset - (4<<bmpDepth)); //54 for regular, diff for colorsimportant
            bitmask = 0xFF;
            if (bmpDepth < 8)
                bitmask >>= bmpDepth;
            bitshift = 8 - bmpDepth;
            n = 1 << bmpDepth;
            lcdbufsiz -= n;
            palette = lcdbuffer + lcdbufsiz;
            for (col = 0; col < n; col++) {
                pos = read32(bmpFile);    //map palette to 5-6-5
                palette[col] = ((pos & 0x0000F8) >> 3) | ((pos & 0x00FC00) >> 5) | ((pos & 0xF80000) >> 8);
            }
        }

        // Set TFT address window to clipped image bounds
        tft.setAddrWindow(x, y, x + w - 1, y + h - 1);
        for (row = 0; row < h; row++) { // For each scanline...
            // Seek to start of scan line.  It might seem labor-
            // intensive to be doing this on every line, but this
            // method covers a lot of gritty details like cropping
            // and scanline padding.  Also, the seek only takes
            // place if the file position actually needs to change
            // (avoids a lot of cluster math in SD library).
            uint8_t r, g, b, *sdptr;
            int lcdidx, lcdleft;
            if (flip)   // Bitmap is stored bottom-to-top order (normal BMP)
                pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
            else        // Bitmap is stored top-to-bottom
                pos = bmpImageoffset + row * rowSize;
            if (bmpFile.position() != pos) { // Need seek?
                bmpFile.seek(pos);
                buffidx = sizeof(sdbuffer); // Force buffer reload
            }

            for (col = 0; col < w; ) {  //pixels in row
                lcdleft = w - col;
                if (lcdleft > lcdbufsiz) lcdleft = lcdbufsiz;
                for (lcdidx = 0; lcdidx < lcdleft; lcdidx++) { // buffer at a time
                    uint16_t color;
                    // Time to read more pixel data?
                    if (buffidx >= sizeof(sdbuffer)) { // Indeed
                        bmpFile.read(sdbuffer, sizeof(sdbuffer));
                        buffidx = 0; // Set index to beginning
                        r = 0;
                    }
                    switch (bmpDepth) {          // Convert pixel from BMP to TFT format
                        case 24:
                            b = sdbuffer[buffidx++];
                            g = sdbuffer[buffidx++];
                            r = sdbuffer[buffidx++];
                            color = tft.color565(r, g, b);
                            break;
                        case 16:
                            b = sdbuffer[buffidx++];
                            r = sdbuffer[buffidx++];
                            if (is565)
                                color = (r << 8) | (b);
                            else
                                color = (r << 9) | ((b & 0xE0) << 1) | (b & 0x1F);
                            break;
                        case 1:
                        case 4:
                        case 8:
                            if (r == 0)
                                b = sdbuffer[buffidx++], r = 8;
                            color = palette[(b >> bitshift) & bitmask];
                            r -= bmpDepth;
                            b <<= bmpDepth;
                            break;
                    }
                    lcdbuffer[lcdidx] = color;

                }
                tft.pushColors(lcdbuffer, lcdidx, first);
                first = false;
                col += lcdidx;
            }           // end cols
        }               // end rows
        tft.setAddrWindow(0, 0, tft.width() - 1, tft.height() - 1); //restore full screen
        ret = 0;        // good render
    }
    bmpFile.close();
    return (ret);
}