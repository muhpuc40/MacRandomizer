# MacRandomizer

**MacRandomizer** is an Arduino library that allows you to easily generate and apply a randomized MAC address to your WiFi-enabled microcontroller (ESP32, ESP8266, NodeMCU, etc.), following IEEE standards for locally administered and unicast addresses.

## 🚀 Features

- ✅ Generates a valid random MAC address:
  - **Locally administered** (bit 2 of first byte is set)
  - **Unicast** (bit 1 of first byte is cleared)
- ✅ Applies the MAC address before connecting to WiFi
- ✅ Compatible with ESP32, ESP8266, NodeMCU boards
- ✅ Prints both randomized and in-use MAC addresses via Serial
- ✅ Lightweight and dependency-free (only requires built-in WiFi libraries)

## 🧠 Supported Platforms

| Platform          | Supported | Notes                      |
|-------------------|-----------|----------------------------|
| ESP32             | ✅ Yes     | Fully supported and tested |
| ESP8266 / NodeMCU | ✅ Yes     | Supported and tested       |
| AVR (UNO, Mega)   | ❌ No      | Not WiFi-capable           |

> ⚠️ This library only works on **WiFi-integrated microcontrollers** and is not compatible with boards that lack WiFi hardware.

---

## 📦 Installation

### 🔧 Method 1: Add via ZIP (Recommended)

1. Download the library ZIP from:  
   [Download MacRandomizer ZIP](https://github.com/muhpuc40/MacRandomizer/archive/refs/heads/main.zip)
2. Open Arduino IDE
3. Go to **Sketch** → **Include Library** → **Add .ZIP Library...**
4. Select the downloaded ZIP file

### 📂 Method 2: Manual Installation

1. Clone or download this repository.
2. Extract and move the `MacRandomizer` folder into your Arduino `libraries/` directory:
   - For example: `Documents/Arduino/libraries/MacRandomizer`
3. Restart the Arduino IDE.

---

## 📘 Usage Example

### 🔌 Include the Library

```cpp
#include <WiFi.h>               // For ESP32
// #include <ESP8266WiFi.h>    // Uncomment for ESP8266
#include <MacRandomizer.h>

MacRandomizer macRandom;

const char* ssid = "YourSSID";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Step 1: Generate and set random MAC address
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
  // Your main code here
}
```

> ℹ️ For ESP8266/NodeMCU users, make sure to replace `#include <WiFi.h>` with `#include <ESP8266WiFi.h>`.

---

## 🛠 Contributing

Feel free to fork the repo, improve it, and submit pull requests. Feature suggestions and issues are welcome!
