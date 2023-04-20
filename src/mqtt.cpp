#include "mqtt.h"

void ConnectToMqttBlocking(PubSubClient &client) {
    char clientNameBuffer[16];

    while (!client.connected()) {
        // generate new name
        sprintf(clientNameBuffer, "%s-%lx", DEVICE_NAME, random(0xff));

        client.connect(clientNameBuffer);

        delay(10);
    }
}
