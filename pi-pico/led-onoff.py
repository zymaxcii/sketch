# led-onoff.py
#

import machine
import utime

onboard_led = machine.Pin(25, machine.Pin.OUT)

while True:
    led_onboard.toggle()
    utime.sleep(5)
