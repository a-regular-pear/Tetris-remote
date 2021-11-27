import serial
import pyautogui



with serial.Serial('/dev/ttyACM0', 9600, timeout=100) as ser:
    while True:
        line = ser.readline().decode('utf-8').rstrip()

        if line:
            print(line)
            pyautogui.press(line)