#include "ServoDevice.h"

ServoDevice::ServoDevice(int pin) : ServoDevice() {
    m_Servo.attach(pin);
}

ServoDevice::ServoDevice(int pin, uint16_t min, uint16_t max) : ServoDevice() {
    m_Servo.attach(pin, min, max);
}

void ServoDevice::SetSpeed(float speed) {
    speed = min(max(-1.0f, speed), 1.0f);

    int microseconds = 1500 + (int)(speed * 500);
    m_Servo.writeMicroseconds(microseconds);
}

void ServoDevice::MoveForPeriod(unsigned long milliseconds, float dir) {
    SetSpeed(dir);
    delay(milliseconds);
    SetSpeed(0);
}