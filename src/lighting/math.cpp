#include "math.h"

namespace
{
    float floor(float f)
    {
        int xi = (int)f;
        return f < xi ? xi - 1 : xi;
    }
    vec2 floor(vec2 v){
        return vec2{floor(v.x), floor(v.y)};
    }
    colorF floor(colorF v){
        return colorF{floor(v.r), floor(v.g), floor(v.b)};
    }
}

float clamp(float x, float minVal, float maxVal)
{
    return x > maxVal ? maxVal : x < minVal ? minVal : x;
}
vec2 clamp(vec2 x, vec2 minVal, vec2 maxVal)
{
    return vec2{
        x.x > maxVal.x ? maxVal.x : x.x < minVal.x ? minVal.x : x.x,
        x.y > maxVal.y ? maxVal.y : x.y < minVal.y ? minVal.y : x.y};
}
colorF clamp(colorF x, colorF minVal, colorF maxVal)
{
    return colorF{
        x.r > maxVal.r ? maxVal.r : x.r < minVal.r ? minVal.r : x.r,
        x.g > maxVal.g ? maxVal.g : x.g < minVal.g ? minVal.g : x.g,
        x.b > maxVal.b ? maxVal.b : x.b < minVal.b ? minVal.b : x.b};
}
colorF clamp(colorF x, float minVal, float maxVal){
        return colorF{
        x.r > maxVal ? maxVal : x.r < minVal ? minVal : x.r,
        x.g > maxVal ? maxVal : x.g < minVal ? minVal : x.g,
        x.b > maxVal ? maxVal : x.b < minVal ? minVal : x.b};
}

float abs(float x)
{
    return x > 0 ? x : -x;
}
vec2 abs(vec2 x)
{
    return vec2{abs(x.x), abs(x.y)};
}
colorF abs(colorF x)
{
    return colorF{abs(x.r), abs(x.g), abs(x.b)};
}

vec2 mod(vec2 x, float y){
   return x - y * floor(x/y);
}
colorF mod(colorF x, float y){
    return x - floor(x/y) * y;
}