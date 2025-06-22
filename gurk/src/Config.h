#ifndef CONFIG_H
#define CONFIG_H

const char *ssid = "Eagle_389AD0";
const char *password = "CiKbPq6b";

const int pinMotor =                    16; // Controls the valve
const int pinInput =                    2;  // Reads valve position sensor
const unsigned long maxOnDuration =     10000; // Milliseconds
const int errorTimeout =                20000; // Milliseconds

#endif
