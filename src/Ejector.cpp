#include <Servo.h>
#include "Ejector.h"

Ejector::Ejector(int pin) : _servo() {
    _servo.attach(pin, 1000, 2000);
    _servo.write(180);
}

void Ejector::Eject() {
    _servo.write(0);
    delay(500);
    _servo.write(180);
}
