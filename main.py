from machine import Pin
from time import sleep

LED_BUILTIN = Pin(2, Pin.OUT)

while(1):
    LED_BUILTIN.on(); 
    sleep(1);
    LED_BUILTIN.off();
    sleep(1);