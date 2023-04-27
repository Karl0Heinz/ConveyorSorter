#include <Servo.h>
#include "Ejector.h"

Ejector::Ejector(int pin) : ServoDevice(pin) {}

void Ejector::Eject() {
    MoveForPeriod(400, 1);
    MoveForPeriod(400, -1);
}
