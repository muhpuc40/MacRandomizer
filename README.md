# MacRandomizer

**MacRandomizer** is an Arduino library that allows you to easily generate and apply a randomized MAC address to your ESP32 WiFi interface, following IEEE standards for locally administered and unicast MAC addresses.

## 🚀 Features

- ✅ Generates a valid random MAC address:
  - Locally administered (bit 2 of first byte is set)
  - Unicast (bit 1 of first byte is cleared)
- ✅ Applies the MAC address before connecting to WiFi
- ✅ Simple API to integrate with your Arduino/ESP32 project
- ✅ Prints the new randomized MAC and current MAC in use
- ✅ Lightweight and dependency-free (only depends on `WiFi.h` and `esp_wifi.h`)

## 🧠 Supported Platforms

| Platform | Supported | Notes                      |
|----------|-----------|----------------------------|
| ESP32    | ✅ Yes     | Fully supported and tested |
| ESP8266  | ❌ No      | Not yet implemented        |
| AVR (UNO, Mega) | ❌ No | Not WiFi-capable          |

> ⚠️ This library only works with **ESP32** and will not compile on generic Arduino boards.

## 📦 Installation

### Option 1: Manual

1. Download or clone this repository.
2. Copy the `MacRandomizer` folder into your Arduino `libraries/` directory:
   - e.g., `Documents/Arduino/libraries/MacRandomizer`
3. Restart the Arduino IDE.

### Option 2: ZIP File

1. Download the ZIP file of this library.
2. In Arduino IDE, go to:
   - `Sketch` > `Include Library` > `Add .ZIP Library...`
3. Select the downloaded ZIP file.

## 📘 Usage

### Include the Library

```cpp
#include <WiFi.h>
#include <MacRandomizer.h>

MacRandomizer macRandom;

const char* ssid = "YourSSID"; //WiFi Name
const char* password = "YourPassword"; //WiFi Password

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Step 1: Generate and set a random MAC address
  macRandom.begin();

  Serial.print("Randomized MAC: ");
  Serial.println(macRandom.getMACString());

  // Step 2: Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("MAC in use: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // Your code here
}
