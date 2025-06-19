#include <WiFi.h>
#include <MacRandomizer.h>

MacRandomizer macRandom;

const char* ssid = "YourSSID";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  delay(1000);

  macRandom.begin();  // Set random MAC

  Serial.print("Randomized MAC: ");
  Serial.println(macRandom.getMACString());

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

void loop() {}
