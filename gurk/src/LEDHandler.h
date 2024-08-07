// LEDHandler.h

#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#include <Arduino.h>
#include "HTTPHandler.h"
#include "WiFiManager.h"
#include "Config.h"
#include "../lib/ArduinoJson-v6.21.5.h"
#include "Utils.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void handleLED(int time_until_watering, int maxOnDuration, const char *noButtonSignalUrl, const char *ssid, const char *password, int waitState);

void processResponse(const String &payload);
void resetLED();

#endif // LED_HANDLER_H
