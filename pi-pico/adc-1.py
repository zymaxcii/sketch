# adc-1.py
#

import machine
import utime

pot = machine.ADC(26)

while True:
    print(pot.read_u16())
    utime.sleep(1)
    
