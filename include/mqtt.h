#ifndef DEMULTIPLEXER_MQTT_H
#define DEMULTIPLEXER_MQTT_H

#include "PubSubClient.h"

static const char *const DEVICE_NAME = "demultiplexer";

/**
 * Connects to MQTT server while blocking
 * @param client client to connect
 */
void ConnectToMqttBlocking(class PubSubClient& client);

#endif //DEMULTIPLEXER_MQTT_H
