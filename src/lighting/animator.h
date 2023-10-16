#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <stdint.h>

#include "../globals.h"
#include "color.h"

namespace animator
{

constexpr float HSLRange_Over_KeyCount = 1530.0f / (float)constants::LEDCount;

extern float keyTimers[constants::LEDCount]; // general use per-key timers for animations
extern colorF keyFadeTargets[constants::LEDCount]; // general use colorLayer
extern bool pressedThisFrame[constants::LEDCount]; // keeps track of notes that have been pressed this frame (not just held down from the last frame)

void setColor(uint16_t led, colorF col);

void setAll(colorF c);

color sweepHSL(unsigned int index);

void resetAnimation();

void setAnimationComplete();
bool getAnimationComplete();

}

namespace animations
{
    void strobe(const float time, const float deltaTime);
    void wave(const float time);
    void couch(const float time);
    void wheel(const float time);
    void solid(const float time);
    void img(const float time);
}

#endif