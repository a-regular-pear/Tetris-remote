# Tetris-remote

## Usage

This program lets you play Tetris with a remote

## Installation

### Install python

#### Ubuntu

>sudo apt-get install python3

#### Arch
>sudo pacman -S python3

#### Windows
https://www.python.org/

### Create a virtual environment
>python -m venv venv

### Enter virtual environment
#### Linux/MacOS
> source venv/bin/activate

#### Windows
> venv\Scripts\activate.bat


### Install dependencies
>pip install -r requirements.txt


### Configure the proper port

On tetris.py enter replace the ```/dev/ttyACM0``` on line 5 with the proper Arduino port:
> serial.Serial('/dev/ttyACM0', 9600, timeout=100) as ser

### Change the remote HEX values 

This program was created for the LG AKB75095308
If you would like to use your own remote at home you need to find the HEX values of the remote and replace them in the Tetris.ino file


### Run the bot
To run the bot type
>python3 discordbot.py


#### Made with the usage of:
https://pypi.org/project/pyserial/

https://pypi.org/project/PyAutoGUI/

https://www.arduino.cc/reference/en/libraries/irremote/


## License
[MIT](https://choosealicense.com/licenses/mit/)
