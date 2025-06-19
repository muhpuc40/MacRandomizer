#include "MacRandomizer.h"
#include <WiFi.h>
#include <esp_wifi.h>

MacRandomizer::MacRandomizer() {}

void MacRandomizer::begin() {
    generateRandomMAC();

    WiFi.mode(WIFI_STA);
    delay(100);
    esp_wifi_set_mac(WIFI_IF_STA, newMAC);
    delay(100);
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
    newMAC[0] = 0x02;  // Locally administered, unicast
    for (int i = 1; i < 6; ++i) {
        newMAC[i] = random(0, 256);
    }
}
