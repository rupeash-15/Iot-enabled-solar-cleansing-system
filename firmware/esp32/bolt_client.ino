#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your WiFi and Bolt Cloud details
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

String boltAPIKey = "YOUR_BOLT_API_KEY";    // from Bolt Cloud
String boltDeviceID = "YOUR_BOLT_DEVICE_ID"; // from Bolt Cloud

const int pumpPin = 5;   // Relay for pump connected to GPIO5

void setup() {
  Serial.begin(115200);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Request command from Bolt Cloud (ON/OFF)
    String url = "https://cloud.boltiot.com/remote/" + boltAPIKey +
                 "/digitalRead?pin=0&deviceName=" + boltDeviceID;

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Response: " + payload);

      if (payload.indexOf("HIGH") >= 0) {
        Serial.println("Remote command: CLEAN → Turning pump ON");
        digitalWrite(pumpPin, HIGH);
        delay(5000);
        digitalWrite(pumpPin, LOW);
      }
    } else {
      Serial.println("Error connecting to Bolt Cloud!");
    }

    http.end();
  }

  delay(5000); // check every 5 sec
}
