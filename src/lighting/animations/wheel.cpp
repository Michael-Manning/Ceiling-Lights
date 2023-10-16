#include <stdint.h>
#include <stddef.h>
#include <cmath>

#include "../../globals.h"
#include "../color.h"
#include "../vec2.h"
#include "../math.h"
#include "../animator.h"

using namespace animator;

namespace{

    #define TP 1.0471975512 // one third PI

    color mainImage(vec2 uv, const float time, float ct, float st)
    {
        uv -= 0.5f;

        float angle = atan2f(- st*uv.x + ct*uv.y, ct*uv.x + st*uv.y);
        angle = (angle + PI) /2.0f;

        float dist = sqrtf(uv.x * uv.x + uv.y * uv.y);
        float feather = atanf(0.02f / dist);

        color col = Colors::Blue;

        if (angle > PI - feather)
        {
            // mix blue and green
            float l = PI + feather;
            float s = PI - feather;
            float r = (angle - s) * (1.0f / (l - s));
            col = colorFToColor(mix(colorF{0.0f, 1.0f, 0.0f}, colorF{0.0f, 0.0f, 1.0f}, r));
        }
        else if (angle > 2.0f * TP + feather)
        {
            // solid green
            col = Colors::Green;
        }
        else if (angle > 2.0f * TP - feather)
        {
            // feather green and red
            float l =  2.0f *TP + feather;
            float s =  2.0f *TP - feather;
            float r = (angle - s) * (1.0f / (l - s));
            col = colorFToColor(mix(colorF{1.0f, 0.0f, 0.0f}, colorF{0.0f, 1.0f, 0.0f}, r));
        }
        else if (angle > TP + feather)
        {
            // solid red
            col = Colors::Red;
        }
        else if (angle > TP - feather)
        {
            // feather red and blue
            float l = TP + feather;
            float s = TP - feather;
            float r = (angle - s) * (1.0f / (l - s));
            col = colorFToColor(mix(colorF{0.0f, 0.0f, 1.0f}, colorF{1.0f, 0.0f, 0.0f}, r));
        }
        else if (angle < feather)
        {
            float l = -feather;
            float s = +feather;
            float r = (angle - s) * (1.0f / (l - s));
            col = colorFToColor(mix(colorF{0.0f, 0.0f, 1.0f}, colorF{0.0f, 1.0f, 0.0f}, r));
        }
        return col;
    }
} // namespace

namespace animations
{
    void wheel(const float time)
    {
        float ct = cosf(time);
        float st = sinf(time);
        for (size_t i = 0; i < 10; i++)
        {
            float uvx = i / 9.0f;
            bool flip = i % 2;
            for (size_t j = 0; j < 180; j++)
            {
                int y = flip ? 179 - j : j;
                color c = mainImage(vec2(uvx, j / 179.0f), time, ct, st);
                setColor(180 * i + y, c * globals::brightness);
            }
        }
    }
} // namespace animations