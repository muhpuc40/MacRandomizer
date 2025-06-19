#ifndef MAC_RANDOMIZER_H
#define MAC_RANDOMIZER_H

#include <Arduino.h>
#include <WiFi.h>

#if defined(ESP32)
  #include <esp_wifi.h>
#elif defined(ESP8266)
  #include <user_interface.h>
#endif

class MacRandomizer {
public:
  MacRandomizer();
  bool generateRandomMac(uint8_t* mac); // Generate a random MAC address
  bool setMacAddress(uint8_t* mac);    // Set a new MAC address
  void getCurrentMac(uint8_t* mac);    // Get the current MAC address

private:
  uint8_t factoryMac[6]; // Store factory MAC address
};

#endif