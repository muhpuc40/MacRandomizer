#include <MacRandomizer.h>
#include <WiFi.h>

MacRandomizer macRandomizer;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Initialize WiFi
  WiFi.mode(WIFI_STA);

  // Generate and set a random MAC address
  uint8_t newMac[6];
  if (macRandomizer.generateRandomMac(newMac)) {
    if (macRandomizer.setMacAddress(newMac)) {
      Serial.print("New MAC address set: ");
      for (int i = 0; i < 6; i++) {
        Serial.printf("%02X", newMac[i]);
        if (i < 5) Serial.print(":");
      }
      Serial.println();
      // Save the MAC address
      macRandomizer.saveMacAddress(newMac);
    } else {
      Serial.println("Failed to set MAC address");
    }
  }

  // Connect to WiFi
  WiFi.begin("your-SSID", "your-password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  // Example: Restore factory MAC after 1 minute
  delay(60000);
  if (macRandomizer.restoreFactoryMac()) {
    Serial.println("Restored factory MAC address");
  }
}