#include "globals.h"

namespace
{
    uint8_t imgData[5400];
}

namespace globals
{
    float brightness = 1.0f;
    color solidColor;
    bool powerState = true;
    float strobeFreq = 6;
    float strobeDuty = 0.04;
    bool freezeTime = false;

    uint8_t *getImgData()
    {
        return imgData;
    }
    void setImgData(char *data)
    {
        for (int i = 0; i < 5400; i++)
        {
            imgData[i] =  (unsigned char)data[i];
        }
    }
}   