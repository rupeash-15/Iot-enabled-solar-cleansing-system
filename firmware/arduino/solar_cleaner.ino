#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

const int ldrPin = A0;       // LDR connected to analog pin A0
const int pumpPin = 7;       // Pump/motor relay connected to digital pin 7

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);  // Keep pump off initially

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC!");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is not running, setting time...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // set time from PC compile time
  }
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  DateTime now = rtc.now();

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Condition 1: Dust detected (light blocked)
  if (ldrValue < 400) { 
    Serial.println("Dust detected → Cleaning started!");
    digitalWrite(pumpPin, HIGH); 
    delay(5000);   // run pump for 5 seconds
    digitalWrite(pumpPin, LOW);
  }

  // Condition 2: Scheduled cleaning (daily at 10:00 AM)
  if (now.hour() == 10 && now.minute() == 0) {
    Serial.println("Scheduled cleaning → Running pump!");
    digitalWrite(pumpPin, HIGH);
    delay(5000);
    digitalWrite(pumpPin, LOW);
  }

  delay(1000); // check every second
}
