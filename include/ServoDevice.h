#pragma once

#include <Servo.h>

class ServoDevice {
    explicit ServoDevice() : m_Servo() {}
protected:
    /**
     * Servo, der die Hauptkomponente des Servogerätes darstellt
     */
    Servo m_Servo;

    explicit ServoDevice(int pin);
    explicit ServoDevice(int pin, uint16_t min, uint16_t max);

public:
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
};
