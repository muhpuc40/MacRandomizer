#include "MacRandomizer.h"
#include <WiFi.h>       // Required for WiFi functions
#include <esp_wifi.h>   // Required for esp_wifi_set_mac()

MacRandomizer::MacRandomizer() {}

void MacRandomizer::begin() {
    generateRandomMAC();
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true);  // Reset WiFi before setting MAC
    esp_wifi_set_mac(WIFI_IF_STA, newMAC);
}

void MacRandomizer::randomizeMAC() {
    generateRandomMAC();
    esp_wifi_set_mac(WIFI_IF_STA, newMAC);
}

String MacRandomizer::getMACString() const {
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
             newMAC[0], newMAC[1], newMAC[2], newMAC[3], newMAC[4], newMAC[5]);
    return String(macStr);
}

void MacRandomizer::generateRandomMAC() {
    newMAC[0] = 0x02;  // Locally administered & unicast
    for (int i = 1; i < 6; ++i) {
        newMAC[i] = random(0, 256);
    }
}
