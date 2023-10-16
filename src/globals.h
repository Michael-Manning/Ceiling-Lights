#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>
#include "lighting/color.h"

namespace constants
{
    constexpr uint16_t stripCount = 10;
    constexpr uint16_t stripLength = 180;
    constexpr uint16_t LEDCount = stripCount * stripLength;
    constexpr uint16_t stripChannelCount = 2;
    constexpr uint16_t channelLength = LEDCount / stripChannelCount;
} // namespace constants

namespace globals
{
    extern float brightness;
    extern color solidColor;
    extern bool powerState;
    extern float strobeFreq;
    extern float strobeDuty;
    extern bool freezeTime;

    uint8_t * getImgData();
    void setImgData(char * data);

} // namespace globals

#define _SSID "Dennis"
#define _NETWORKKEY "7804663459"

#endif 