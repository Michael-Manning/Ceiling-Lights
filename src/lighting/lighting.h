#ifndef LIGHTING_H
#define LIGHTING_H

#include <stdint.h>
#include "../globals.h"
#include "color.h"


namespace lights
{

enum class AnimationMode{
    none,
    couch,
    strobe,
    wave,
    wheel,
    solid,
    img
};

void init();
void setAnimationMode(AnimationMode mode);
AnimationMode getAnimationMode();
void updateAnimation();
};

#endif