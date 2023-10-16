#include <stdint.h>
#include <cmath>

#include "../../globals.h"
#include "../color.h"
#include "../animator.h"

using namespace animator;


namespace animations
{
    void img(const float time){
        uint8_t * data = globals::getImgData();
        for (size_t i = 0; i < constants::LEDCount; i++)
        {
            setColor(i, color{data[i * 3], data[i * 3 + 1], data[i * 3 + 2]} * globals::brightness);                
        }
        
    }
}