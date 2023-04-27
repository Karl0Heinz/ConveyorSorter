#pragma once

#include <Servo.h>
#include "ServoDevice.h"

/**
 * Abstraktion zur Steuerung von Fließbändern
 */
class ConveyorBelt : public ServoDevice {
public:
    /**
     * Erstellt instanz der Klasse ConveyorBelt
     *
     * @param pin Der Pin, an dem das Fließband angeschlossen ist
     */
    explicit ConveyorBelt(int pin);

    /**
     * Bewegt ein Objekt auf dem Fließband um etwa <n> Zentimeter
     * @param cm Zentimeter, um die das Objekt auf dem Fließband bewegt werden soll
     */
    void MoveCm(float cm);

    /**
     * Hilfsmethode zum Kallibrieren des Fließandes
     * @param timeInBetween
     */
    void Callibrate(unsigned long timeInBetween);
};