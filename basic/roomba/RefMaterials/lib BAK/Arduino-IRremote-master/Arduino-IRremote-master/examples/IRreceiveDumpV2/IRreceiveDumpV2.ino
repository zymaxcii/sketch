/*
 * IRreceiveDumpV2.cpp
 */

//------------------------------------------------------------------------------
// Include the IRremote library header
//
#include <IRremote.h>

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
#if defined(ESP32)
int IR_RECEIVE_PIN = 15;
#else
int IR_RECEIVE_PIN = 11;
#endif
IRrecv IrReceiver(IR_RECEIVE_PIN);

//+=============================================================================
// Configure the Arduino
//
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);   // Status message will be sent to PC at 9600 baud
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)
    delay(2000); // To be able to connect Serial monitor after reset and before first printout
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__));

    IrReceiver.enableIRIn();  // Start the receiver
    IrReceiver.blink13(true); // Enable feedback LED

    Serial.print(F("Ready to receive IR signals at pin "));
    Serial.println(IR_RECEIVE_PIN);
}

//+=============================================================================
// The repeating section of the code
//
void loop() {
    if (IrReceiver.decode()) {  // Grab an IR code
        // Check if the buffer overflowed
        if (IrReceiver.results.overflow) {
            Serial.println("IR code too long. Edit IRremoteInt.h and increase RAW_BUFFER_LENGTH");
            return;
        }
        Serial.println();                               // 2 blank lines between entries
        Serial.println();
        IrReceiver.printResultShort(&Serial);

        Serial.println(F("Result in internal ticks (50 us) - always without trailing gap"));
        IrReceiver.printIRResultRawFormatted(&Serial, false); // Output the results in RAW format
        Serial.println(F("Result in microseconds - without trailing gap for IRremote versions >= 3.*"));
        IrReceiver.printIRResultRawFormatted(&Serial, true);  // Output the results in RAW format
        Serial.println();                               // blank line between entries
        Serial.println(F("Result as internal ticks (50 us) array - always without trailing gap"));
        IrReceiver.printIRResultAsCArray(&Serial, false);   // Output the results as uint8_t source code array of ticks
        Serial.println(F("Result as microseconds array - with trailing gap for IRremote versions 2.*"));
        IrReceiver.printIRResultAsCArray(&Serial, true);    // Output the results as uint16_t source code array of micros
        IrReceiver.printIRResultAsCVariables(&Serial);  // Output address and data as source code variables

        IrReceiver.printIRResultAsPronto(&Serial);

        /*
         * Creating this String requires 2210 bytes program memory and 10 bytes RAM for the String class.
         * The String object itself requires additional 440 Bytes RAM from the heap.
         * This values are for an Arduino UNO.
         */
//        Serial.println();                                     // blank line between entries
//        String ProntoHEX = F("Pronto HEX contains: ");        // Assign string to ProtoHex string object
//        if (int size = IrReceiver.dumpPronto(&ProntoHEX)) {   // Dump the content of the IReceiver Pronto HEX to the String object
//            // Append dumpPronto() size information to the String object (requires 50 bytes heap)
//            ProntoHEX += F("\r\nProntoHEX is ");              // Add codes size information to the String object
//            ProntoHEX += size;
//            ProntoHEX += F(" characters long and contains "); // Add codes count information to the String object
//            ProntoHEX += size / 5;
//            ProntoHEX += F(" codes");
//            Serial.println(ProntoHEX.c_str());                // Print to the serial console the whole String object
//            Serial.println();                                 // blank line between entries
//        }

        IrReceiver.resume();                            // Prepare for the next value
    }
}
