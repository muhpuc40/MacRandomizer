#include "MacRandomizer.h"

MacRandomizer::MacRandomizer() {
  Serial.println("Initializing MacRandomizer...");
  randomSeed(analogRead(0)); // Seed random number generator
  WiFi.mode(WIFI_STA);
  delay(500); // Stabilize WiFi stack
  #if defined(ESP32)
    esp_wifi_get_mac(WIFI_IF_STA, factoryMac);
  #elif defined(ESP8266)
    wifi_get_macaddr(STATION_IF, factoryMac);
  #endif
  Serial.print("Factory MAC: ");
  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", factoryMac[i]);
    if (i < 5) Serial.print(":");
  }
  Serial.println();
}

bool MacRandomizer::generateRandomMac(uint8_t* mac) {
  Serial.println("Generating random MAC...");
  for (int i = 0; i < 6; i++) {
    mac[i] = random(0, 256);
  }
  mac[0] |= 0x02; // Set locally administered bit
  mac[0] &= ~0x01; // Clear multicast bit
  Serial.print("Generated MAC: ");
  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", mac[i]);
    if (i < 5) Serial.print(":");
  }
  Serial.println();
  return true;
}

bool MacRandomizer::setMacAddress(uint8_t* mac) {
  Serial.println("Attempting to set MAC address...");
  WiFi.mode(WIFI_STA); // Ensure station mode
  delay(500); // Prevent crashes
  #if defined(ESP32)
    esp_err_t err = esp_wifi_set_mac(WIFI_IF_STA, mac);
    if (err != ESP_OK) {
      Serial.printf("Failed to set MAC address, error code: %d\n", err);
      return false;
    }
    Serial.println("MAC address set successfully on ESP32");
    return true;
  #elif defined(ESP8266)
    bool result = wifi_set_macaddr(STATION_IF, mac);
    if (!result) {
      Serial.println("Failed to set MAC address on ESP8266");
      return false;
    }
    Serial.println("MAC address set successfully on ESP8266");
    return true;
  #else
    Serial.println("Unsupported platform for MAC address setting");
    return false;
  #endif
}

void MacRandomizer::getCurrentMac(uint8_t* mac) {
  Serial.println("Getting current MAC...");
  WiFi.mode(WIFI_STA);
  delay(500);
  #if defined(ESP32)
    esp_wifi_get_mac(WIFI_IF_STA, mac);
  #elif defined(ESP8266)
    wifi_get_macaddr(STATION_IF, mac);
  #endif
}