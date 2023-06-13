# react-game3.py
# 2-player game
# Press the button when LED goes off

import machine
import utime
import urandom

pressed = False
led = machine.Pin(13, machine.Pin.OUT)

left_button  = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_DOWN)
right_button = machine.Pin(10, machine.Pin.IN, machine.Pin.PULL_DOWN)


def button_handler(pin):
  global pressed
  if not pressed:
    pressed = True
    timer_reaction = utime.ticks_diff(utime.ticks_ms(), timer_start)
    print("Your reaction time was " + str(timer_reaction) +
    " milliseconds!")
    
led.value(1)
utime.sleep(urandom.uniform(5, 10))
led.value(0)

timer_start = utime.ticks_ms()

right_button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)
left_button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)
