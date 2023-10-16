#include <stdint.h>
#include <stddef.h>
#include <cmath>

#include "../../globals.h"
#include "../color.h"
#include "../animator.h"

using namespace animator;

namespace animations
{
    template<typename t>
    inline t abs(t n){
        return n > 0 ? n : -n;
    }

    void wave(const float time){
        for (size_t i = 0; i < 10; i++)
        {
            float s = sinf(i * 0.6 - time) * 33 + 90;

            for (size_t j = 0; j < 180; j++)
            {
                int y = j;
                if(i % 2){
                    y = 179 - y;
                }

                float b = abs(j - s) / 180.0f;
                //b =  -b * 12.0f + 2.4f;
                if(b < 0.127){
                    b = (0.0046 / (b - 0.1356)) + 1.06;
                }
                else{
                    b = (0.004 / (b - 0.12)) - 0.046;
                }
                
                if(b < 0){
                    b = 0;
                }
                if(b > 1){
                    b = 1;
                }

                setColor(180 * i + y, mix(color{5, 0, 0}, color{100, 0, 255}, b) * globals::brightness);                
            }
            
        }
        
    }
}