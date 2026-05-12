# CompSoc Arduino Workshop
This repo contains materials for the CompSoc Arduino workshop, ran on 12/05/2026.
See `Intro to Arduinos.pdf` for the session slides, containing useful info for getting started on the projects.

There are 4 mini-projects:
1. Logic gates (andGate)
2. FizzBuzz (fizzbuzz)
3. Timer (timer)
4. Reaction time game (reactionTimeGame)

See end of README for credits.

## Tasks
The code for each mini-project is mostly complete, with some of them having missing code which you have to fill in.
See the slides, as well as the README file in each project's folder, for more info.

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
- Simply include the `"TM1637Display.h"` header file in your code.
- Note, it may automatically include `<TM1637.h>`, but this doesn't work for me - use the include above instead.

## Arduino IDE on Linux
You may have the issue where you don't have read / write permissions on the Arduino whenever you plug it in.

You can fix this by making a `udev` rule:
- Create a rule file: `/etc/udev/rules.d/10-arduino.rules`
- Write into the file: `SUBSYSTEM=="tty", ATTRS{manufacturer}=="Arduino*", MODE="0666"`

## Credits
[@LaurenceRichardson](https://github.com/LaurenceRichardson)
- Slides
- Projects 1, 2 & 4

[@cottondell](https://github.com/cottondell)
- Project 3
- README files

[@Tyloxon](https://github.com/Tyloxon)
- Project 2
