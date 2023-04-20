#include "ConveyorBelt.h"

ConveyorBelt::ConveyorBelt(int pin) {
    servo = Servo();
    servo.attach(pin, 1000, 2000);
}

void ConveyorBelt::SetSpeed(float speed) {
    speed = min(max(-1.0f, speed), 1.0f);

    int microseconds = 1500 + (int)(speed * 500);
    servo.writeMicroseconds(microseconds);
}

void ConveyorBelt::MoveForPeriod(unsigned long milliseconds, float dir) {
    SetSpeed(dir);
    delay(milliseconds);
    SetSpeed(0);
}

void ConveyorBelt::MoveCm(float cm) {
    // evil (x/m)+b hack
    const float error = 0.5;
    float milliseconds = (cm + error) / 0.00573f + 25; // what the fuck

    if (milliseconds > 0) {
        MoveForPeriod((unsigned long)(milliseconds), 1.f);
    } else {
        MoveForPeriod((unsigned long)-(milliseconds), -1.f);
    }
}
