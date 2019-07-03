/*
 * This file is a part of Troyka modules library.
 *
 * Defines: Troyka color sensor module library. Uses Adafruit_TCS34725 library.
 * © Amperka LLC (https://amperka.com, dev@amperka.com)
 * 
 * Author: Yury Botov <by@amperka.ru>
 * License: GPLv3, all text here must be included in any redistribution.
 */

#ifndef __TROYKACOLORSENSOR_H__
#define __TROYKACOLORSENSOR_H__

#include "Adafruit_TCS34725.h"

struct RGB {
public:
    byte red;
    byte green;
    byte blue;
};

class TroykaColorSensor : public Adafruit_TCS34725 {
public:
    TroykaColorSensor(tcs34725IntegrationTime_t it = TCS34725_INTEGRATIONTIME_2_4MS,
        tcs34725Gain_t g = TCS34725_GAIN_1X)
        : Adafruit_TCS34725(it, g) {}

    void colorRead(uint8_t* r, uint8_t* g, uint8_t* b);
    RGB colorRead(void);
};

#endif // __TROYKAPROXIMITY_H__
