# led-1.py
#

import machine
import utime

onboard_led = machine.Pin(15, machine.Pin.OUT)

while True:
    onboard_led.value(1)
    utime.sleep(0.25)
    onboard_led.value(0)
    utime.sleep(0.25)
    
