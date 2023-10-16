#include <Arduino.h>




#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>


#include<lighting/color.h>
//#include<lighting/LEDCom.h>
#include<lighting/lighting.h>

#include "network.h"

const char* ssid = "wifi delux";
const char* password = "kony2012";

void setup()
{
    Serial.begin(115200);
    Serial.println("Booting");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Connection Failed! Rebooting...");
        delay(5000);
        ESP.restart();
    }

    ArduinoOTA
        .onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
            else // U_SPIFFS
                type = "filesystem";

            // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
            Serial.println("Start updating " + type);
        })
        .onEnd([]() {
            Serial.println("\nEnd");
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        })
        .onError([](ota_error_t error) {
            Serial.printf("Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR)
                Serial.println("Auth Failed");
            else if (error == OTA_BEGIN_ERROR)
                Serial.println("Begin Failed");
            else if (error == OTA_CONNECT_ERROR)
                Serial.println("Connect Failed");
            else if (error == OTA_RECEIVE_ERROR)
                Serial.println("Receive Failed");
            else if (error == OTA_END_ERROR)
                Serial.println("End Failed");
        });

    ArduinoOTA.begin();

    network::startServer();

      Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    lights::init();
    
//   LEDCom::stripInit();
//   //LEDCom::setAll(color({255, 255, 255}));
//   LEDCom::updateLEDS();
}

int timer = 0;
int lastTime = 0;
int loopI = 0;

void loop()
{
    ArduinoOTA.handle();
    network::pollEvents();

    lights::updateAnimation();

    // timer += millis() - lastTime;
    // lastTime = millis();

    // if(timer > 50){
    //     loopI ++;
    //     timer = 0;
    //     if(loopI == 1800)
    //     {
    //         loopI = 0;
    //     }
    // }

    // LEDCom::setAll(color{0, 0, 0});
    // LEDCom::setColor((uint16_t)loopI, 255, 255, 255);
    // LEDCom::updateLEDS();

    // return;
    // timer += millis() - lastTime;
    // lastTime = millis();

    // if (loopI == 0)
    // {
    //     LEDCom::setAll(color({255, 0, 0}));
    // }
    // else if (loopI == 1)
    // {
    //     LEDCom::setAll(color({0, 255, 0}));
    // }
    // else if (loopI == 2)
    // {
    //     LEDCom::setAll(color({0, 0, 255}));
    // }
    // else if (loopI == 3)
    // {
    //     LEDCom::setAll(color({255, 255, 255}));
    // }

    // if(timer >= 5000){
    //     LEDCom::updateLEDS();
    //     timer = 0;
    //     loopI ++;
    //     if(loopI == 4){
    //         loopI = 0;
    //     }
    // }

    // const float time = (float)micros() / 1000000.0f;

    // //pixels.clear(); // Set all pixel colors to 'off'

    // for (unsigned int i = 0; i < NUMPIXELS; i++)
    // {
    //     float index = i * HSLRange_Over_KeyCount + time * 1000;
    //     while (index > 1530)
    //     {
    //         index -= 1530;
    //     }
    //     color col = sweepHSL((unsigned int)(index));

    //     setPixel(i, col);
    // }

    // showPixels();
}