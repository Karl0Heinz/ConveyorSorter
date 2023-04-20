#pragma once

#include <Servo.h>

/**
 * Abstraktion zur Steuerung von Fließbändern
 */
class ConveyorBelt {
    Servo servo;

public:
    /**
     * Erstellt instanz der Klasse ConveyorBelt
     *
     * @param pin Der Pin, an dem das Fließband angeschlossen ist
     */
    explicit ConveyorBelt(int pin);

    /**
     * Setzt die Richtung und Geschwindigkeit des Fließbands
     * @param speed Wert zwischen 1.0 und -1.0, der richtung und geschwindigkeit angibt
     */
    void SetSpeed(float speed);

    /**
     * Setzt die Richtung und Geschwindigkeit des Fließbands für eine bestimmte Zeit
     * @param milliseconds wie lange sich das Fließband bewegt
     * @param dir Richtung und Geschwindigkeit [1.0, -1.0]
     */
    void MoveForPeriod(unsigned long milliseconds, float dir);

    /**
     * Bewegt ein Objekt auf dem Fließband um etwa <n> Zentimeter
     * @param cm Zentimeter, um die das Objekt auf dem Fließband bewegt werden soll
     */
    void MoveCm(float cm);
};