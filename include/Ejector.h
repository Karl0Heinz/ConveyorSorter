#pragma once

#include "Servo.h"

/*
 * Ein Ejector stellt ein Gerät dar, das ein Objekt vom Fließband "schubst"
 */
class Ejector {
    /**
     * Servo, der die Hauptkomponente des Ejectors darstellt
     */
    Servo _servo;

public:
    /**
     * Konstruiert eine neue Ejector instanz
     * @param pin der Pin an dem der Ejector angeschlossen wurde
     */
    explicit Ejector(int pin);

    /**
     * Versucht ein Objekt vom Fließband zu "schubsen"
     */
    void Eject();
};
