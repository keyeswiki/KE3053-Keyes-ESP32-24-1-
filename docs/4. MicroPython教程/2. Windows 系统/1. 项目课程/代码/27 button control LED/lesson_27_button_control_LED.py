from machine import Pin
import time

led = Pin(12, Pin.OUT) # create LED object from Pin 12,Set Pin 12 to output                   
button = Pin(13, Pin.IN, Pin.PULL_UP) #Create button object from Pin13,Set GP13 to input

#Customize a function and name it reverseGPIO(),which reverses the output level of the LED
def reverseGPIO():
    if led.value():
        led.value(0)     #Set led turn off
    else:
        led.value(1)     #Set led turn on

try:
    while True:
        if not button.value():
            time.sleep_ms(20)
            if not button.value():
                reverseGPIO()
                while not button.value():
                    time.sleep_ms(20)
except:
    pass
