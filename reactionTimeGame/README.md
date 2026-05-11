# Arduino Reaction time game
This project uses an Arduino to control a 4-digit display through a separate chip.

Interfacing with external chips can be quite hard to wrap your head around. While it is a good learning experience to do it yourself, there are often libraries that do the heavy lifting for you.

For this session, we will use this open source library:
- https://github.com/avishorp/TM1637/

Product codes:
- Display - 3542BS-7.3P
- Driver chip - TM1637

## Downloading the Library
To download:
1. Download the zip file from the latest release in the releases section on the GitHub page: https://github.com/avishorp/TM1637/releases/tag/v1.2.0
2. Import the library using the Arduino IDE:
	1. Go to `Sketch > Include Library > Add .ZIP Library`
	2. Select the `.zip` file you just downloaded
	3. It should show `Library installed` in the Output window

To use:
- Simply include the `TM1637Display.h` header file in your code.
