#include <i2cmaster.h>
#include <util/delay.h>

#define HT16K33_ADDRESS 0xE0
#define HT16K33_OSCILLATOR_ON 0x21
#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BRIGHTNESS 0xE0

// Our display buffer
uint16_t displaybuffer[8];

// Oscillator ON
void initHt16k33(void) {
    i2c_start(HT16K33_ADDRESS);
    i2c_write(HT16K33_OSCILLATOR_ON);
    i2c_stop();
}
// Display ON and no blink
void initNoBlink(void) {
    i2c_start(HT16K33_ADDRESS);
    i2c_write(HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON); //0x81
    i2c_stop();
}
// Set the brightness (between 0 and 15)
void setBrightness(uint8_t b) {
    if (b>15) b = 15;
    i2c_start(HT16K33_ADDRESS);
    i2c_write(0xE0 | b);
    i2c_stop();
}
// Set to 0 all the display buffer
void clearBuffer(void) {
    for (int i = 0 ; i < 8 ; i++) {
        displaybuffer[i] = 0;
    }
}

// Switch led (x,y) ON in the buffer (need to call display to see the result)
void setPixel(int16_t x, int16_t y) {
    x += 7;
    x %= 8;
    displaybuffer[y] |= 1 << x;
}
// Switch led (x,y) OFF in the buffer (need to call display to see the result)
void unsetPixel(int16_t x, int16_t y) {
    x += 7;
    x %= 8;
    displaybuffer[y] &= ~(1 << x);
}
// Trigger a display of the buffer
void display() {
    uint8_t i;
    i2c_start(HT16K33_ADDRESS);
    i2c_write(0x00);
    for (i=0; i<8; i++) {
        i2c_write(displaybuffer[i] & 0xFF);    
        i2c_write(displaybuffer[i] >> 8);
    }
    i2c_stop();
}

// Main loop where we display on and off LEDs every second
int main(void) {
    uint16_t x = 0;
    uint16_t y = 0;
    uint8_t mode = 0; // 0 means switch ON, 1 means switch off.
    
    i2c_init();

    // Let the HT16K33 initialise
    _delay_ms(10);

    // Switch oscillator ON, no blink and minimal brightness
    initHt16k33();
    initNoBlink();
    setBrightness(1);
    clearBuffer();
    display();

    // Switch on a LED every second
    for(;;) {

        // wait 60 sec
        for (int i=0 ; i < 60 ; i++) {
            _delay_ms(1000);
        }

        // according to the mode, switch on or off the leds
        if (mode == 0) {
            setPixel(x,y);
        } else {
            unsetPixel(x,y);
        }

        display();
        x++;
        // at the end of the row switch row
        if (x%8 == 0) {
            x = 0;
            y += 1;
        }
        // Change the mode when the matrix is full
        if (y >= 8) {
            x = 0;
            y = 0;
            if (mode == 0) {
                mode = 1;
            } else {
                mode = 0;
            }
        }
    }
    return 0;
}