#include <Arduino.h>
#include <WiFiClient.h>

#include "net.h"
#include "mqtt.h"
#include "configuration.h"
#include "lcdgfx.h"
#include "logo.h"

//#include "calibrate.h"

void msgProc(const char *topic, const uint8_t *payload, unsigned int length);

WiFiClient connection;
PubSubClient client(MQTT_SERVER_ADDRESS, MQTT_PORT, msgProc, connection);
DisplaySSD1306_128x64_I2C display(-1, {-1, 0, 14, 2, 0});

void TestEjectors();


[[gnu::used]]
void setup() {
    display.begin();
    display.fill(0x00);
    display.setFixedFont(ssd1306xled_font6x8);
    //display.drawBitmap1(0, 0, DEMUXTITLESCREEN.width, DEMUXTITLESCREEN.height, &DEMUXTITLESCREEN.pixel_data[0]);

    ConnectToNetworkBlocking(WIFI_SSID, WIFI_PASSCODE);
    ConnectToMqttBlocking(client);
    //TestEjectors();

    client.subscribe(DEMUX_TOPIC);

    display.write("Connected!");
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

            client.publish(DEMUX_TOPIC, "gg ez");
        }
    }
}

void TestEjectors() {
    for (EjectorInfo metadata: ejectorMetadata) {
        metadata.ejector->Eject();
        delay(100);
    }
}