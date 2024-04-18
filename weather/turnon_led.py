import serial
import time

#Connection to serial port
conn = serial.Serial('COM1', 9600)

#Turn on led
conn.write(b'1')
time.sleep(2)

#Turn off led
conn.write(b'0')
time.sleep(1)

#Close connetion
conn.close()
