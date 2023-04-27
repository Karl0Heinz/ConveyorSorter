#include "ConveyorBelt.h"

ConveyorBelt::ConveyorBelt(int pin) : ServoDevice(pin) {}

void ConveyorBelt::MoveCm(float cm) {
    // evil (x/m)+b hack
    float milliseconds = cm / 0.00576667f - 5.69999423f; // what the fuck

    if (milliseconds > 0) {
        MoveForPeriod((unsigned long) (milliseconds), 1.f);
    } else {
        MoveForPeriod((unsigned long) -(milliseconds), -1.f);
    }
}

void ConveyorBelt::Callibrate(unsigned long timeInBetween = 6000) {
    int periods[] = {250, 500, 750, 1000, 1250, 1500, 1750, 2000, 4000};

    for (int period: periods) {
        MoveForPeriod(period, 1);
        delay(timeInBetween);
    }
}
