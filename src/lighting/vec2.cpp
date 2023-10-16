#include "vec2.h"

bool operator==(vec2 &a, vec2 &b)
{
    return a.x == b.x && a.y == b.y;
}
bool operator!=(vec2 &a, vec2 &b)
{
    return !(a == b);
}
bool operator==(const vec2 &a, const vec2 &b)
{
    return a.x == b.x && a.y == b.y;
}
bool operator!=(const vec2 &a, const vec2 &b)
{
    return !(a == b);
}

// vec2 with vec2
vec2 operator+(const vec2 &a, const vec2 &b)
{
    vec2 c = {a.x + b.x, a.y + b.y};
    return c;
}
vec2 operator-(const vec2 &a, const vec2 &b)
{
    vec2 c = {a.x - b.x, a.y - b.y};
    return c;
}
vec2 operator*(const vec2 &a, const vec2 &b)
{
    vec2 c = {a.x * b.x, a.y * b.y};
    return c;
}
vec2 operator/(const vec2 &a, const vec2 &b)
{
    return {a.x / b.x, a.y / b.y};
}
vec2 operator+=(vec2 &a, const vec2 &b)
{
    a = a + b;
    return a;
}
vec2 operator-=(vec2 &a, const vec2 &b)
{
    a = a - b;
    return a;
}
vec2 operator*=(vec2 &a, const vec2 &b)
{
    a = a * b;
    return a;
}
vec2 operator/=(vec2 &a, const vec2 &b)
{
    a = a / b;
    return a;
}

// vec2 with float
vec2 operator+(const vec2 &a, const float &b)
{
    vec2 c = {a.x + b, a.y + b};
    return c;
}
vec2 operator-(const vec2 &a, const float &b)
{
    vec2 c = {a.x - b, a.y - b};
    return c;
}
vec2 operator*(const vec2 &a, const float &b)
{
    vec2 c = {a.x * b, a.y * b};
    return c;
}
vec2 operator/(const vec2 &a, const float &b)
{
    return {a.x / b, a.y / b};
}
vec2 operator+=(vec2 &a, const float &b)
{
    a = a + b;
    return a;
}
vec2 operator-=(vec2 &a, const float &b)
{
    a = a - b;
    return a;
}
vec2 operator*=(vec2 &a, const float &b)
{
    a = a * b;
    return a;
}
vec2 operator/=(vec2 &a, const float &b)
{
    a = a / b;
    return a;
}
