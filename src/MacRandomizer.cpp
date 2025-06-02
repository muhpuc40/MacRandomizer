#include "MacRandomizer.h"
#include <WiFi.h> // Include WiFi.h for WiFi functions
#if defined(ESP32)
  #include <Preferences.h>
#elif defined(ESP8266)
  #include <EEPROM.h>
#endif

MacRandomizer::MacRandomizer() {
  // Initialize factory MAC
  #if defined(ESP32)
    WiFi.mode(WIFI_STA); // Set WiFi to station mode
    esp_wifi_get_mac(WIFI_IF_STA, factoryMac); // Use WIFI_IF_STA for ESP32
  #elif defined(ESP8266)
    WiFi.mode(WIFI_STA); // Set WiFi to station mode
    wifi_get_macaddr(STATION_IF, factoryMac);
  #endif
}

bool MacRandomizer::generateRandomMac(uint8_t* mac) {
  // Generate random bytes
  for (int i = 0; i < 6; i++) {
    mac[i] = random(0, 256);
  }
  // Set locally administered bit (bit 1 of first byte = 1)
  mac[0] |= 0x02;
  // Clear multicast bit (bit 0 of first byte = 0)
  mac[0] &= ~0x01;
  return true;
}

bool MacRandomizer::setMacAddress(uint8_t* mac) {
  #if defined(ESP32)
    esp_err_t err = esp_wifi_set_mac(WIFI_IF_STA, mac);
    return (err == ESP_OK);
  #elif defined(ESP8266)
    return wifi_set_macaddr(STATION_IF, mac);
  #else
    return false; // Unsupported platform
  #endif
}

bool MacRandomizer::saveMacAddress(uint8_t* mac) {
  #if defined(ESP32)
    Preferences preferences;
    preferences.begin("mac", false);
    bool success = preferences.putBytes("mac_addr", mac, 6) == 6;
    preferences.end();
    return success;
  #elif defined(ESP8266)
    EEPROM.begin(512);
    for (int i = 0; i < 6; i++) {
      EEPROM.write(i, mac[i]);
    }
    bool success = EEPROM.commit();
    EEPROM.end();
    return success;
  #else
    return false; // Unsupported platform
  #endif
}

bool MacRandomizer::loadMacAddress(uint8_t* mac) {
  #if defined(ESP32)
    Preferences preferences;
    preferences.begin("mac", true);
    bool success = preferences.getBytes("mac_addr", mac, 6) == 6;
    preferences.end();
    return success;
  #elif defined(ESP8266)
    EEPROM.begin(512);
    for (int i = 0; i < 6; i++) {
      mac[i] = EEPROM.read(i);
    }
    EEPROM.end();
    return true;
  #else
    return false; // Unsupported platform
  #endif
}

bool MacRandomizer::restoreFactoryMac() {
  return setMacAddress(factoryMac);
}

void MacRandomizer::getCurrentMac(uint8_t* mac) {
  #if defined(ESP32)
    esp_wifi_get_mac(WIFI_IF_STA, mac);
  #elif defined(ESP8266)
    wifi_get_macaddr(STATION_IF, mac);
  #endif
}