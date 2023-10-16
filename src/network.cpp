#include <Arduino.h>
#include <ArduinoOTA.h>
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

#include "globals.h"
#include "network.h"
#include "web/index.h"
#include "lighting/lighting.h"
#include "lighting/LEDCom.h"

namespace
{
    WebServer webServer(80);
    WiFiClient client; // persistant accross poll calls.`

    float floatArg(const char *name)
    {
        return webServer.arg(name).toFloat();
    }
    int intArg(const char *name)
    {
        return webServer.arg(name).toInt();
    }
} // namespace

namespace network
{
    void setPower();
    void getPower();

    void setBrightness();
    void getBrightness();

    void setSolidColor();
    void getSolidColor();

    void setStrobeSettings();
    void getStrobeSettings();

    void setMode();
    void getMode();

    void uploadImg();

    void handleRoot();

    void toggleTimeFreeze();

    void startServer()
    {
        webServer.on("/", handleRoot);
        webServer.on("/setPower", setPower);
        webServer.on("/getPower", getPower);
        webServer.on("/setBrightness", setBrightness);
        webServer.on("/getBrightness", getBrightness);
        webServer.on("/setSolidColor", setSolidColor);
        webServer.on("/getSolidColor", getSolidColor);
        webServer.on("/setStrobeSettings", setStrobeSettings);
        webServer.on("/getStrobeSettings", getStrobeSettings);
        webServer.on("/setMode", setMode);
        webServer.on("/getMode", getMode);
        webServer.on("/uploadImg", HTTP_POST, uploadImg);
        webServer.on("/toggleTimeFreeze", toggleTimeFreeze);
        webServer.begin();
    }

    void pollEvents()
    {
        webServer.handleClient();
    }

    void handleRoot()
    {
        webServer.send(200, "text/html", String(MAIN_page));
    }

    void setPower(){
        globals::powerState = intArg("state");
        webServer.send(200, "text/plane", "OK");
    }
    void getPower(){
        webServer.send(200, "text/plane", globals::powerState ? "1" : "0");
    }

    void setBrightness()
    {
        float brightness = floatArg("brightness");
        if (brightness < 0.0f || brightness > 1.0f)
        {
            webServer.send(400, "text/plane", "Out of range value");
            return;
        }
        globals::brightness = brightness;
        webServer.send(200, "text/plane", "OK");
    }

    void getBrightness(){
        webServer.send(200, "text/plane", String(globals::brightness));
    }

    void setSolidColor()
    {
        int R = intArg("r");
        int G = intArg("g");
        int B = intArg("b");

        globals::solidColor = color{R, G, B};
        webServer.send(200, "text/plane", "OK");
    }

    void getSolidColor()
    {
        color rgb = globals::solidColor;
        webServer.send(200, "text/plane", String(((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff)));
    }

    void setStrobeSettings(){
        globals::strobeFreq = floatArg("frequency");
        globals::strobeDuty = floatArg("duty");
        webServer.send(200, "text/plane", "OK");
    }

    void getStrobeSettings(){
        webServer.send(200, "text/plane", "OK");
    }

    void setMode()
    {
        int mode = intArg("mode");

        switch (mode)
        {
        case 0:
            lights::setAnimationMode(lights::AnimationMode::none);
            break;

        case 1:
            lights::setAnimationMode(lights::AnimationMode::couch);
            break;
        case 2:
            lights::setAnimationMode(lights::AnimationMode::strobe);
            break;
        case 3:
            lights::setAnimationMode(lights::AnimationMode::wave);
            break;
        case 4:
            lights::setAnimationMode(lights::AnimationMode::wheel);
            break;
        case 5:
            lights::setAnimationMode(lights::AnimationMode::solid);
            break;
        case 6:
            lights::setAnimationMode(lights::AnimationMode::img);
            break;
        default:
            break;
        }

        webServer.send(200, "text/plane", "OK");
    }

    void getMode(){
        webServer.send(200, "text/plane", String((int)lights::getAnimationMode()));
    }

    void uploadImg(){
        String data = webServer.arg("plain");

        webServer.send(200, "text/plain", "Upload ok ");

        char dataBuffer[5400];

        data.toCharArray(dataBuffer, 5400);
    
        //globals::setImgData(dataBuffer);
        for (unsigned short i = 0; i < 1080; i++)
        {
             LEDCom::setColor(i, color{(unsigned char)dataBuffer[i * 3], (unsigned char)dataBuffer[i * 3 + 1], (unsigned char)dataBuffer[i * 3 + 2]} * globals::brightness);  
        }
        
        lights::setAnimationMode(lights::AnimationMode::img);


    }

    void toggleTimeFreeze(){
        globals::freezeTime = !globals::freezeTime;
        webServer.send(200, "text/plane", "OK");
    }
} // namespace network