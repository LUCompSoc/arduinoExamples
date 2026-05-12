# CompSoc Arduino Workshop
This repo contains materials for the CompSoc Arduino workshop, ran on 12/05/2026.
See `Intro to Arduinos.pdf` for the slides, containing useful info for getting started on the projects.

It contains 4 mini-projects:
1. Logic gates (andGate)
2. FizzBuzz (fizzbuzzSmaple)
3. Timer (timer)
4. Reaction time game (reactionTimeGame)

Projects 1, 2 & 3 were made by @LaurenceRichardson, and project 4 was made by @cottondell.

## TM1637 Library
Projects 3 & 4 use a 4-digit display, controlled by the TM1637 micro-controller.

Interfacing with external chips can be quite hard to wrap your head around. While it is a good learning experience to do it yourself, there are often libraries available that do the heavy lifting for you.

For this session, we will use this open source library:
- https://github.com/avishorp/TM1637/

Installing the libary:
1. Download the zip file from the latest release in the `Releases` section on the GitHub page: https://github.com/avishorp/TM1637/releases/tag/v1.2.0
2. Import the library using the Arduino IDE:
	1. Go to `Sketch > Include Library > Add .ZIP Library`
	2. Select the `.zip` file you just downloaded
	3. It should show `Library installed` in the Output window

Using the library:
- Simply include the `TM1637Display.h` header file in your code.

## Tasks
The code for each mini-project is mostly complete.
Some of the mini-projects have missing code which you have to fill in.

If you need any help, feel free to call us over!

## Arduino IDE on Linux
You may have the issue where you don't have read / write permissions on the Arduino every time you plug it in.

You can fix this by making a `udev` rule:
- Create a rule file: `/etc/udev/rules.d/10-arduino.rules`
- Write into the file: `SUBSYSTEM=="tty", ATTRS{manufacturer}=="Arduino*", MODE="0666"`
