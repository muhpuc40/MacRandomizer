#include <WiFi.h>
#include <MacRandomizer.h>

MacRandomizer macRandom;

const char* ssid = "YourSSID";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Set random MAC address BEFORE WiFi starts
  macRandom.begin();

  Serial.print("Randomized MAC set to: ");
  Serial.println(macRandom.getMACString());

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");

  Serial.print("Effective MAC Address: ");
  Serial.println(WiFi.macAddress());  // Should match randomized one
}

void loop() {
  // Optional: Do other stuff
}
