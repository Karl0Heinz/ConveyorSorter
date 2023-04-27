#ifndef DEMULTIPLEXER_CONFIGURATION_H
#define DEMULTIPLEXER_CONFIGURATION_H

#include "Ejector.h"
#include "EjectorMetadata.h"
#include "ConveyorBelt.h"

#pragma region STATIC_SETTINGS
static const char *const DEMUX_TOPIC = "demultiplexer";

static const char *const MQTT_SERVER_ADDRESS = "192.168.1.11";
static const int MQTT_PORT = 1883;

static const char *const WIFI_PASSCODE = "123456789";
static const char *const WIFI_SSID = "Projekt";
#pragma endregion

#pragma region DEVICES
ConveyorBelt conveyorBelt(5);
Ejector ejector1(14);
Ejector ejector2(16);
Ejector ejector3(12);
Ejector ejector4(13);
#pragma endregion

#pragma region DEVICE METADATA
EjectorInfo ejectorMetadata[] = {
        {"red",    &ejector1, 10.15},
        {"green",  &ejector2, 13.9},
        {"blue",     &ejector3, 20.2},
        {"yellow", &ejector4, 23},
};
#pragma endregion

#endif //DEMULTIPLEXER_CONFIGURATION_H