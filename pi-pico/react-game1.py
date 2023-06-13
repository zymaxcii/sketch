# react-game1.py
# 1 player
# not working properly

import machine
import utime
import urandom

pressed = False

led = machine.Pin(13, machine.Pin.OUT)
button = machine.Pin(10, machine.Pin.IN, machine.Pin.PULL_DOWN)

def button_handler(pin):
  global pressed
  if not pressed:
    pressed=True
    print(pin)


while True:
  led.value(1)
  utime.sleep(urandom.uniform(5, 10))
  led.value(0)
  utime.sleep(urandom.uniform(1, 3))

  button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)

