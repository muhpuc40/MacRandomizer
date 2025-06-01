# MacRandomizer Library

A library for Arduino to randomize MAC addresses on IoT devices like ESP32 and ESP8266, enhancing security by preventing tracking.

## Features
- Generate random, locally administered MAC addresses.
- Set MAC addresses on supported devices.
- Save/load MAC addresses to/from non-volatile storage.
- Restore factory MAC address.

## Supported Platforms
- ESP32
- ESP8266
- NodeMCU (using ESP32 or ESP8266)

## Installation
1. Download the library as a ZIP file from the GitHub repository.
2. In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library` and select the ZIP file.
3. The library will appear under `Sketch > Include Library > MacRandomizer`.

## Usage
See the `examples/RandomizeMac` folder for a sample sketch.

```cpp
#include <MacRandomizer.h>
MacRandomizer macRandomizer;

void setup() {
  Serial.begin(115200);
  uint8_t newMac[6];
  macRandomizer.generateRandomMac(newMac);
  macRandomizer.setMacAddress(newMac);
}