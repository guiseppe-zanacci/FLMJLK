#include <Arduino.h>
#include "TestFunctions.h"

int valveControlPin = 16;
int valveSensorPin = 5;
int maxSensorWaitDuration = 2000;

int LEDTOBLINK = valveControlPin;

void blinkBuiltinLED(){
    pinMode(LEDTOBLINK, OUTPUT);
    for (int i=0; i<5; i++){
        digitalWrite(LEDTOBLINK, HIGH);
        delay(1000);
        digitalWrite(LEDTOBLINK, LOW);
        delay(250);
    }
}

void handleValveSensor(int maxOnDuration, int waitState)
{
    // Turn on the valve
    digitalWrite(valveControlPin, HIGH);
    unsigned long startTime = millis();

    // Fix: Cast maxOnDuration to unsigned long to avoid signed/unsigned comparison warning
    while (millis() - startTime < (unsigned long)maxOnDuration)
    {
        // Read the sensor state directly without debouncing
        int sensorState = digitalRead(valveSensorPin);

        // Check if the sensor state matches the wait state
        if (sensorState == waitState)
        {
            break;
        }

        delay(10); // Small delay to prevent high CPU usage
    }

    // Turn off the motor
    digitalWrite(valveControlPin, LOW);
}

void closeValve()
{
    int startedState = digitalRead(valveSensorPin);
    // Turns valve to change state
    digitalWrite(valveControlPin, HIGH);
    while (digitalRead(valveSensorPin) == startedState){
        delay(1);
    }
    digitalWrite(valveControlPin, LOW);

    // If state was close, it is now open. Therefore close it
    if (startedState == 0)
    {
        handleValveSensor(maxSensorWaitDuration, LOW);
    }
}

void testSetup(){
    pinMode(valveControlPin, OUTPUT);
    pinMode(valveSensorPin, INPUT_PULLUP);
    closeValve();
    digitalWrite(valveControlPin, HIGH);
}

void testbuttonloop(){
    while (true){
        int sensorstate = digitalRead(valveSensorPin);
        while (sensorstate == digitalRead(valveSensorPin)){
            delay(1);
        }
    }
}

void testLoop(){
    int i = 1;
    while (true){
        delay(2000);
        if (i == 1){
            Serial.println("OPEN");
        } else {
            Serial.println("CLOSED");
        }
        handleValveSensor(maxSensorWaitDuration,i);
        i = -i;
    }
} 