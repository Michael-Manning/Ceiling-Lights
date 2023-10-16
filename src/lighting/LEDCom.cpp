#include <Arduino.h>
#include <NeoPixelBus.h>

#include "../globals.h"
#include "color.h"
#include "LEDCom.h"

using namespace constants;

namespace
{

    color colors[LEDCount];
    colorF colorsF[LEDCount];
    bool stripDirty = true;

    NeoPixelBus<NeoRbgFeature, NeoEsp32Rmt0800KbpsMethod> stripA(900, 12);
    NeoPixelBus<NeoRbgFeature, NeoEsp32Rmt1800KbpsMethod> stripB(900, 13);
} // namespace

namespace LEDCom
{

    void stripInit()
    {
        stripA.Begin();
        stripB.Begin();
        stripA.Show();
        stripB.Show();
    }

    void setColor(uint16_t led, uint8_t r, uint8_t g, uint8_t b)
    {
        colors[led] = {r, g, b};
        colorsF[led] = colorToColorF({r, g, b});
        stripDirty = true;
    }

    void setColor(uint16_t led, colorF c)
    {
        colors[led] = colorFToColor(c);
        colorsF[led] = c;
        stripDirty = true;
    }

    colorF getColor(uint16_t led)
    {
        return colorsF[led];
    }

    void setAll(colorF c)
    {
        for (size_t i = 0; i < LEDCount; i++)
        {
            colors[i] = colorFToColor(c);
            colorsF[i] = c;
        }
        stripDirty = true;
    }

    void setAll(color c)
    {
        for (size_t i = 0; i < LEDCount; i++)
        {
            colors[i] = c;
            colorsF[i] = colorToColorF(c);
        }
        stripDirty = true;
    }

    void updateLEDS()
    {
        if (!stripDirty)
            return;

        // Not dynamic with channel count
        for (size_t i = 0; i < constants::channelLength; i++)
        {
            stripA.SetPixelColor(constants::channelLength - i -1, RgbColor(colors[i].g,colors[i].b, colors[i].r ));
        }
        for (size_t i = constants::channelLength; i < constants::LEDCount; i++)
        {
            stripB.SetPixelColor(i - constants::channelLength, RgbColor(colors[i].g,colors[i].b, colors[i].r ));
        }

        stripA.Show();
        stripB.Show();

        stripDirty = false;
    }

} // namespace LEDCom