#ifndef MATH_H
#define MATH_H

#include <stdint.h>
#include "vec2.h"
#include "color.h"

const float PI = 3.14159265359;

float clamp(float x, float minVal, float maxVal);
vec2 clamp(vec2 x, vec2 minVal, vec2 maxVal);
colorF clamp(colorF x, colorF minVal, colorF maxVal);
colorF clamp(colorF x, float minVal, float maxVal);

float abs(float x);
vec2 abs(vec2 x);
colorF abs(colorF x);

vec2 mod(vec2 x, float y);
colorF mod(colorF x, float y);

#endif