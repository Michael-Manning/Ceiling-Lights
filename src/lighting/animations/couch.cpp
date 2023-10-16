#include <stdint.h>
#include <stddef.h>
#include <cmath>

#include "../../globals.h"
#include "../color.h"
#include "../animator.h"

using namespace animator;

namespace animations
{
    void couch(const float time){
        setAll(Colors::Off);
        for (size_t i = 3; i < 6; i++)
        {
            for (size_t j = 120; j < 180; j++)          {
                int y = j;
                if(i % 2){
                    y = 179 - y;
                }

                setColor(180 * i + y, Colors::Warm * globals::brightness);
            }
            
        }
        
    }
}