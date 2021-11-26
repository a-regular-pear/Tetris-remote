import serial


with serial.Serial('/dev/ttyACM1', 9600, timeout=100) as ser:
    while True:
        line = ser.readline().decode('utf-8').rstrip()

        if line:
            print(line)