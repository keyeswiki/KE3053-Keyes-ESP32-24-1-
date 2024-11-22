from machine import ADC, Pin
import time
 
# Turn on and configure the ADC with the range of 0-3.3V 
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

led = Pin(5,Pin.OUT)

while True: 
    adcVal=adc.read()
    if adcVal > 400:
        led.value(1)
        print(adcVal, "led on")
        time.sleep(3)
    else:
        led.value(0)
        print(adcVal, "led off")
        time.sleep(0.1)
    