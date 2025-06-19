#include <MacRandomizer.h>

MacRandomizer macRandom;

void setup() {
  Serial.begin(115200);
  delay(1000);

  macRandom.begin();  // Randomize and apply MAC address
  Serial.print("New MAC: ");
  Serial.println(macRandom.getMACString());

  WiFi.begin("YourSSID", "YourPassword");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
}

void loop() {
  // Your code
}
