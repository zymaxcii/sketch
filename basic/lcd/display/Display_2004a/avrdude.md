avrdude -C /usr/share/arduino/hardware/tools/avrdude.conf -p m2560 -c wiring -P /dev/ttyACM0 -b 115200 -U flash:r:flash-backup-file.hex:i

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude: Device signature = 0x1e9801 (probably m2560)
avrdude: reading flash memory:

Reading | ################################################## | 100% 33.40s

avrdude: writing output file "flash-backup-file.hex"

avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)

avrdude done.  Thank you.

(base) mty@rock:~/Downloads/sketchbook/Display_2004a

For writing needs -D
-D -U flash:r:flash-backup-file.hex:i




$ avrdude -C /usr/share/arduino/hardware/tools/avrdude.conf -p m2560 -c wiring -P /dev/ttyACM0 -b 115200 -U eeprom:r:eeprom-backup-file.hex:i

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude: Device signature = 0x1e9801 (probably m2560)
avrdude: reading eeprom memory:

Reading | ################################################## | 100% 4.19s

avrdude: writing output file "eeprom-backup-file.hex"

avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)

avrdude done.  Thank you.

(base) mty@rock:~/Downloads/sketchbook/Display_2004a
$ 

