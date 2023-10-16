#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

struct color;
struct colorF;

// a 32 bit, floating point color
struct colorF
{
    float r, g, b;

    // colorF(float x, float y, float z){
    //     r = x;
    //     g = y;
    //     b = z;
    // }


    // struct vec3{
    //     	union {
	// 	float values[2];

	// 	//for bezier 3
	// 	struct {
	// 		float x, y
	// 		int type;
	// 	};

	// 	//for lines and arcs
	// 	struct {
	// 		vec2 start, end, center;
	// 		int type;
	// 	};
	// };
    // }


};

// an 8 bit color
struct color
{
    uint8_t r, g, b;

    constexpr operator colorF() const
    {
        return colorF{(float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f};
    };
};

// Converts an 8 bit color to a 32 bit color (this is also implicit)
constexpr colorF colorToColorF(color c)
{
    return colorF{(float)c.r / 255.0f, (float)c.g / 255.0f, (float)c.b / 255.0f};
};

// Converts a 32 bit color to an 8 bit color
constexpr color colorFToColor(colorF c)
{
    return color{static_cast<uint8_t>(c.r * 255), static_cast<uint8_t>(c.g * 255), static_cast<uint8_t>(c.b * 255)};
};

// Interpolates between two colors with a t value from 0.0 - 1.0.
// Similar to GLSL mix()
constexpr colorF mix(const colorF &A, const colorF &B, float t)
{
    return {
        (1.0f - t) * A.r + t * B.r,
        (1.0f - t) * A.g + t * B.g,
        (1.0f - t) * A.b + t * B.b};
};

colorF colorMin(const colorF &a, const colorF &b); 
colorF colorMin(const colorF &a, float b); 
colorF colorMax(const colorF &a, const colorF &b); 
colorF colorMax(const colorF &a, float b); 

// Quick colors
namespace Colors{
    constexpr color Off = {0, 0, 0};
    constexpr color Warm = {255, 200, 50};
    constexpr color Red = {255, 0, 0};
    constexpr color Blue = {0, 0, 255};
    constexpr color Green = {0, 255, 0};
    constexpr color Purple = {255, 0, 255};
    constexpr color White = {255, 255, 255};
    constexpr color Yellow = {255, 255, 0};
}

bool operator == (color &a, color &b);
bool operator != (color &a, color &b);

bool operator == (const colorF &a, const colorF &b);
bool operator != (const colorF &a, const colorF &b);

colorF operator + (const colorF &a, const colorF &b);
colorF operator - (const colorF &a, const colorF &b);
colorF operator * (const colorF &a, const colorF &b);
colorF operator / (const colorF &a, const colorF &b);
colorF operator += (colorF &a, const colorF &b);
colorF operator -= (colorF &a, const colorF &b);
colorF operator *= (colorF &a, const colorF &b);
colorF operator /= (colorF &a, const colorF &b);

colorF operator + (const colorF &a, float b);
colorF operator - (const colorF &a, float b);
colorF operator * (const colorF &a, float b);
colorF operator / (const colorF &a, float b);
colorF operator + (const float &a, colorF b);
colorF operator - (const float &a, colorF b);
colorF operator * (const float &a, colorF b);
colorF operator / (const float &a, colorF b);
colorF operator += (colorF &a, float b);
colorF operator -= (colorF &a, float b);
colorF operator *= (colorF &a, float b);
colorF operator /= (colorF &a, float b);

#endif