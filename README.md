# Timer using a 8x8 LED matrix

## Description

This is a simple project to build a small timer using a 8x8 LED matrix driven by a microcontroller.
Each LED is a second. I'm still searching for an original way to display the time.

The code is inspired by the [Adafruit library available in this repo](https://github.com/adafruit/Adafruit_LED_Backpack).

The main functions are:

+ `setPixel(x, y)` to switch ON one LED at coordinates (x,y).
+ `unsetPixel(x, y)` to switch OFF one LED at coordinates (x,y).
+ `display()` to trigger a display.

There are also several functions to initialise the chip driving the LED, switch on the display and set the brightness.

The LED matrix I'm using is the [Adafruit 0.7''](https://learn.adafruit.com/adafruit-led-backpack/0-8-8x8-matrix).
You can buy it [here](https://shop.pimoroni.com/products/adafruit-mini-8x8-led-matrix-w-i2c-backpack) in UK.
The LED matrix is driven by a ht16k33 using I2C commands ([datasheet](https://cdn-shop.adafruit.com/datasheets/ht16K33v110.pdf)).

The makefile I use comes from the book [AVR Programming](http://shop.oreilly.com/product/0636920028161.do) from Elliot Williams.
I tailored the Makefile for my ATMega328 and my usbtiny programmer.

For the gory details of the I2C communications I use [this library from Peter Fleury](http://homepage.hispeed.ch/peterfleury/avr-software.html).

At the moment the LED matrix and the microcontroller (an ATMega328) are on a mini breadboard and powered by the programmer.

At some point I would like to switch for an ATTiny85, power everything with a small battery and 3D print a tiny case.

## Build the project

This project uses avrdude and avr-gcc.
The makefile is tailored for an ATMega328 running at 16 Mhz flashed by a usbtiny programmer.

+ Clone the repo: `git clone ` and go into the directory.

+ Connect the LED matrix to the microcontroller using the I2C clock and data pins.

+ Flash the microcontroller using: `make flash`
