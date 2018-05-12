# Timer using a 8x8 LED matrix

## Description

This is a simple project to build a small timer using a 8x8 LED matrix driven by a microcontroller.
Each LED is a second. I'm still searching for an original way to display the time.

The code is inspired by the [Adafruit library available in this repo](https://github.com/adafruit/Adafruit_LED_Backpack).

The LED matrix I'm using is the [Adafruit 0.7''](https://learn.adafruit.com/adafruit-led-backpack/0-8-8x8-matrix).
You can buy it [here](https://shop.pimoroni.com/products/adafruit-mini-8x8-led-matrix-w-i2c-backpack) in UK.
The LED matrix is driven by a ht16k33 using I2C commands.

The makefile I use comes from the book [AVR Programming](http://shop.oreilly.com/product/0636920028161.do) from Elliot Williams.

For the gory details of the I2C communications I use [this library from Peter Fleury](http://homepage.hispeed.ch/peterfleury/avr-software.html).

At the moment the LED matrix and the microcontroller are on a mini breadboard and powered by the programmer.
But the goal is to power everything with a battery and 3D print a tiny case. 

## Build the project

+ Clone the repo: `git clone ` and go into the directory.

+ Connect the LED matrix to the microcontroller using the I2C clock and data pins.

+ Flash the microcontroller using: `make flash`