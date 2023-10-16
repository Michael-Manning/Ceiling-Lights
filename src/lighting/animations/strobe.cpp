#include <stdint.h>
#include <cmath>

#include "../../globals.h"
#include "../color.h"
#include "../animator.h"

using namespace animator;

namespace{
    float timer = 0;

    float lastTime = 0;
}

namespace animations
{
    void strobe(const float time, const float delta){



       // float realDelta = time - lastTime;
        lastTime = time;
        timer += delta;

        // if(timer >= 0.1f)
        // {
        //     timer = 0;
        // }

        // if(timer < 0.1f * 0.3f){
        //     setAll(Colors::White);
        // }
        // else{
        //     setAll(Colors::Off);
        // }
        // return;



        const float period = 1.0f / globals::strobeFreq;


        if(timer >= period)
        {
            timer = 0;
        }
        
        if(timer < period * globals::strobeDuty){
            setAll(Colors::White);
        }
        else{
            setAll(Colors::Off);
        }
    }
}