#ifndef VEC2_H
#define VEC2_H

#include <stdint.h>

struct vec2{
    float x, y;

    vec2(float X, float Y){
        x = X;
        y = Y;
    }
    vec2(float XY){
        x = XY;
        y = XY;
    }
    vec2(){
        x = 0;
        y = 0;
    }
};

bool operator == (const vec2 &a, const vec2 &b);
bool operator != (const vec2 &a, const vec2 &b);

vec2 operator + (const vec2 &a, const vec2 &b);
vec2 operator - (const vec2 &a, const vec2 &b);
vec2 operator * (const vec2 &a, const vec2 &b);
vec2 operator / (const vec2 &a, const vec2 &b);
vec2 operator += (vec2 &a, const vec2 &b);
vec2 operator -= (vec2 &a, const vec2 &b);
vec2 operator *= (vec2 &a, const vec2 &b);
vec2 operator /= (vec2 &a, const vec2 &b);

vec2 operator + (const vec2 &a, const float &b);
vec2 operator - (const vec2 &a, const float &b);
vec2 operator * (const vec2 &a, const float &b);
vec2 operator / (const vec2 &a, const float &b);
vec2 operator += (vec2 &a, const float &b);
vec2 operator -= (vec2 &a, const float &b);
vec2 operator *= (vec2 &a, const float &b);
vec2 operator /= (vec2 &a, const float &b);


#endif

