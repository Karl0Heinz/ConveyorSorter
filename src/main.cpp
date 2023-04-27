#include <Arduino.h>
#include <WiFiClient.h>

#include "net.h"
#include "mqtt.h"
#include "configuration.h"

//#include "calibrate.h"

void msgProc(const char *topic, const uint8_t *payload, unsigned int length);

WiFiClient connection;
PubSubClient client(MQTT_SERVER_ADDRESS, MQTT_PORT, msgProc, connection);

void TestEjectors();

[[gnu::used]]
void setup() {
    TestEjectors();
    ConnectToNetworkBlocking(WIFI_SSID, WIFI_PASSCODE);
    ConnectToMqttBlocking(client);

    client.subscribe(DEMUX_TOPIC);
}

void loop() {
    if (!client.connected()) {
        ConnectToMqttBlocking(client);
    }

    client.loop();
}

void msgProc(const char *topic, const uint8_t *payload, unsigned int length) {
    if (strcmp(topic, DEMUX_TOPIC) == 0) {
        std::optional<EjectorInfo> maybeMetadata = getEjectorMetadata(payload, length);

        if (maybeMetadata.has_value()) {
            EjectorInfo metadata = maybeMetadata.value();

            conveyorBelt.MoveCm(metadata.distanceInCm);
            metadata.ejector->Eject();
        }
    }
}

void TestEjectors() {
    for (EjectorInfo metadata: ejectorMetadata) {
        metadata.ejector->Eject();
    }
}