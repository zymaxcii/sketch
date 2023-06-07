# led-1.py
#

import machine
import utime

onboard_led = machine.Pin(25, machine.Pin.OUT)

while True:
    onboard_led.value(1)
    utime.sleep(5)
    onboard_led.value(0)
    utime.sleep(5)
    
