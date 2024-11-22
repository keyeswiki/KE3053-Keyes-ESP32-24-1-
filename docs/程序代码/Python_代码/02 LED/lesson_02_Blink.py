from machine import Pin
import time

led = Pin(5, Pin.OUT)# Build an LED object, connect the external LED light to pin 5, and set pin 5 to output mode
while True:
    led.value(1)# turn on led
    time.sleep(1)# delay 1s
    led.value(0)# turn off led
    time.sleep(1)# delay 1s