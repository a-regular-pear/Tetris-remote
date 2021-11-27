import serial
import pyautogui


with serial.Serial('/dev/ttyACM0', 9600, timeout=100) as ser:
    while True:
        # Decodes the string to utf-8
        line = ser.readline().decode('utf-8').rstrip()

        if line:
            pyautogui.press(line)
