# pwm-1.py
# Using pwm

import machine
import utime

pot = machine.ADC(26)
led = machine.PWM(machine.Pin(21))
led.freq(1000)

while True:
    led.duty_u16(pot.read_u16())
    
