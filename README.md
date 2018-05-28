# Timer using a 8x8 LED matrix

## Description

This is a simple project to build a small timer using a 8x8 LED matrix driven by a ATTiny85 microcontroller.
Each LED is a minute but I'm still searching for an original way to display the time.

![An image of the project on a mini breadboard](https://github.com/Kylir/timer-ht16k33-8x8-led-matrix/blob/master/IMG_20180527_131523.jpg)

The code to switch on and off LEDs is inspired by the [Adafruit library available in this repo](https://github.com/adafruit/Adafruit_LED_Backpack).

The main functions are:

+ `setPixel(x, y)` to switch ON one LED at coordinates (x,y).
+ `unsetPixel(x, y)` to switch OFF one LED at coordinates (x,y).
+ `display()` to trigger a display.

There are also several functions to initialise the chip driving the LED, switch on the display and set the brightness.

The LED matrix I'm using is the [Adafruit 0.7''](https://learn.adafruit.com/adafruit-led-backpack/0-8-8x8-matrix).
You can buy it [here](https://shop.pimoroni.com/products/adafruit-mini-8x8-led-matrix-w-i2c-backpack) in UK.
The LED matrix is driven by a ht16k33 using I2C commands ([datasheet](https://cdn-shop.adafruit.com/datasheets/ht16K33v110.pdf)).

For the gory details of the I2C communications I use a software implementation from [this library from Peter Fleury](http://homepage.hispeed.ch/peterfleury/avr-software.html).
I'm also using the makefile provided the library.

At the moment the LED matrix and the microcontroller are on a mini breadboard and powered by a fairly big battery.
But at some point I want to change for a smaller battery and 3D print a tiny case.


## Build the project

This project uses avrdude and avr-gcc.
The makefile is tailored for an ATTiny running at 1 Mhz flashed by a usbtiny programmer.

+ Clone the repo: `git clone ` and go into the directory.

+ Connect the LED matrix to the microcontroller using the I2C clock and data pins. I used [this really nice pin-out diagram](https://github.com/SpenceKonde/ATTinyCore/blob/master/avr/extras/ATtiny_x5.md).

+ Flash the microcontroller using: `make program`
