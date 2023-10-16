#ifndef LEDCOM_H
#define LEDCOM_H

#include <stdint.h>

#include "color.h"

namespace LEDCom
{

void stripInit();

void setColor(uint16_t led, uint8_t r, uint8_t g, uint8_t b);

void setColor(uint16_t led, colorF c);

colorF getColor(uint16_t led);

void setAll(colorF c);

void setAll(color c);

void updateLEDS();

}

#endif