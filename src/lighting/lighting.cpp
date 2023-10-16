#include "../globals.h"
#include "animator.h"
#include "color.h"
#include "LEDCom.h"
#include "lighting.h"
#include "esp_timer.h"
#include <stdint.h>

namespace
{

float animationStartTime = 0;
bool animationFirstFrame = false;

lights::AnimationMode animationMode = lights::AnimationMode::wheel;

} // namespace

namespace lights
{
// initialise the LED strip
void init()
{
    LEDCom::stripInit();
}

// Sets the animation mode and starts running it
void setAnimationMode(AnimationMode mode)
{
    animationMode = mode;
    animationFirstFrame = true;
    animationStartTime = esp_timer_get_time() / 1000000.0f;
    animator::resetAnimation();
}

AnimationMode getAnimationMode()
{
    return animationMode;
}

float lastTime = 0;
void updateAnimation()
{
    float time;
    if (!globals::freezeTime)
    {
        time = (float)esp_timer_get_time() / 1000000.0f; // - animationStartTime;
    }
    else{
        time = lastTime;
    }
    const float deltaTime = time - lastTime;
    lastTime = time;

    if (!globals::powerState)
    {
        LEDCom::setAll(Colors::Off);
    }
    else
    {
        switch (animationMode)
        {
        case AnimationMode::none:
            LEDCom::setAll(Colors::Off);
            break;
        case AnimationMode::couch:
            animations::couch(time);
            break;
        case AnimationMode::strobe:
            animations::strobe(time, deltaTime);
            break;
        case AnimationMode::wave:
            animations::wave(time);
            break;
        case AnimationMode::wheel:
            animations::wheel(time);
            break;
        case AnimationMode::solid:
            animations::solid(time);
            break;
        case AnimationMode::img:
            //animations::img(time);
            break;
        default:
            break;
        }
    }
    //animations::strobe(time, deltaTime);
    // animations::couch(time);
    //animations::wave(time);

    // switch (animationMode)
    // {
    // case AnimationMode::None : 
    //     LEDCom::setAll(Colors::Off);
    //     break;
    // case AnimationMode::Ambiant : 
    //     for (size_t i = 0; i < _KEYCOUNT; i++)
    //     {
    //         //if!blackkey
    //         LEDCom::setAll(settings::getColorSetting(settings::Colors::Ambiant));
    //     }
        
    //     break;
    // case AnimationMode::Startup:
    //     animations::startUp(time);
    //     break;
    // case AnimationMode::PulseError:
    //     animations::pulseError(time);
    //     break;
    // case AnimationMode::BlinkSuccess:
    //     animations::blinkSuccess(time);
    //     break;
    // case AnimationMode::ColorfulIdle:
    //     animations::colorfulIdle(time);
    //     break;
    // case AnimationMode::ProgressBar:
    //     animations::progressBar(progressBarValue);
    //     break;
    // case AnimationMode::KeyIndicate:
    //     animations::keyIndicate();
    //     break;
    // case AnimationMode::KeyIndicateFade:
    //     animations::rainbowFade(deltaTime, time); //animations::keyIndicateFade(deltaTime);
    //     break;
    // case AnimationMode::Waiting:
    //     animations::waiting(deltaTime, time, animationFirstFrame, fullRefresh, memorizationMode);
    //     break;
    // case AnimationMode::Wave :
    //     animations::wave(deltaTime, animationFirstFrame);
    //     break;
    // default:
    //     fatalError(ErrorCode::IMPOSSIBLE_INTERNAL);
    //     break;
    // }
    animationFirstFrame = false;
    LEDCom::updateLEDS();
}
} // namespace lights
