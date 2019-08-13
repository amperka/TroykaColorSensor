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

    *r = (uint8_t)(256L * red / baseLevel);
    // float constants is inversely proportional to the sensitivity of
    // color component sensors (reduced to red). You can get it from 
    // datasheet (figure 2, page 6): https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf
    *g = (uint8_t)(1.354 * 256L * green / baseLevel);
    *b = (uint8_t)(1.571 * 256L * blue / baseLevel);
}

RGB TroykaColorSensor::colorRead(void) {
    RGB color;
    colorRead(&color.red, &color.green, &color.blue);
    return color;
}
