/*
 * This file is a part of Troyka modules library.
 *
 * Implement: Troyka color sensor module library. Uses Adafruit_TCS34725 library.
 * © Amperka LLC (https://amperka.com, dev@amperka.com)
 * 
 * Author: Yury Botov <by@amperka.ru>
 * License: GPLv3, all text here must be included in any redistribution.
 */

#include "TroykaColorSensor.h"

void TroykaColorSensor::colorRead(uint8_t* r, uint8_t* g, uint8_t* b) {
    uint16_t red, green, blue, baseLevel;
    getRawData(&red, &green, &blue, &baseLevel);

    float redFixed = (float)red;
    // float constants is inversely proportional to the sensitivity of
    // color component sensors (reduced to red). You can get it from
    // datasheet (figure 2, page 6): https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf
    float greenFixed = (float)green * 1.354;
    float blueFixed = (float)blue * 1.571;

    float maxFixed = max(redFixed,max(greenFixed, blueFixed));
    *r = (uint8_t)(255 * redFixed / maxFixed);
    *g = (uint8_t)(255 * greenFixed / maxFixed);
    *b = (uint8_t)(255 * blueFixed / maxFixed);
}

RGB TroykaColorSensor::colorRead(void) {
    RGB color;
    colorRead(&color.red, &color.green, &color.blue);
    return color;
}
