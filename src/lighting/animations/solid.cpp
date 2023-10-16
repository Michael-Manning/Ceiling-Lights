#include <stdint.h>
#include <stddef.h>
#include <cmath>

#include "../../globals.h"
#include "../color.h"
#include "../animator.h"

using namespace animator;

namespace animations
{
    void solid(const float time){
        setAll(globals::solidColor * globals::brightness);        
    }
}