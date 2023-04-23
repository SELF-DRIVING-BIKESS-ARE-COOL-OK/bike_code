import os
import sys
from subprocess import Popen, PIPE, STDOUT
import serial.tools.list_ports
import time

ports = serial.tools.list_ports.comports()
for port in ports:
    print(str(port))

ser = serial.Serial('/dev/ttyUSB0')
ser.baudrate = 9600

script_path = os.path.join(os.getcwd(), 'detect.py')
cmd = "python3 " + script_path + " --source 0"

p = Popen(cmd, stdout=PIPE, stderr=STDOUT, bufsize=1, shell=True)
try:
    for line in iter(p.stdout.readline, b''):
        print (line)
        if("person" in str(line)):
            print("PERSON!!")
            ser.write(bytes('1', 'utf-8'))
except Exception as e:
    ser.close()
    p.stdout.close()
    raise ValueError
ser.close()
p.stdout.close()
p.wait()