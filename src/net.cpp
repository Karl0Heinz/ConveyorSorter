#include "net.h"

#include <ESP8266WiFi.h>

void ConnectToNetworkBlocking(const char *ssid, const char *passphrase) {
    WiFi.begin(ssid, passphrase);

    // Block until we are connected
    while (WiFi.status() != WL_CONNECTED) {
        delay(10);
    }
}