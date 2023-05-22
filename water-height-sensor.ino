#include <ArduinoJson.h> // Benoit Blanchon
#include "credentials.h" // Replace with your values
#include <ESP8266HTTPClient.h> // Arduino
#include <ESP8266WiFi.h> // Arduino
#include <HCSR04.h> // Martin Sosic

UltraSonicDistanceSensor distanceSensor(D1, D2);

void setup() {
  // Setup serial port
  Serial.begin(115200);

  // Wifi setup
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  WiFi.setAutoConnect(true);

  // Wait for serial to initialize.
  while(!Serial) {
    Serial.println("Waiting for Serial");
    delay(5000);
  }
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Waiting for Wifi");
    delay(5000);
  }
}

void loop() {
  Serial.println("In the loop");
  int new_distance;
  new_distance = get_distance();
  send_to_ifttt(new_distance);

  ESP.deepSleep(300e6);
}

void send_to_ifttt(int distance) {
    WiFiClient client;
    HTTPClient http;

    String url = "http://maker.ifttt.com/trigger/" + String(IFTTT_EVENT_NAME) + "/with/key/" + String(IFTTT_API_KEY);
    http.begin(client, url);

    // Prepare JSON payload
    DynamicJsonDocument jsonDoc(1024);
    jsonDoc["value1"] = distance;
    jsonDoc["value2"] = WiFi.RSSI();

    String payload;
    serializeJson(jsonDoc, payload);

    // Set the content type as application/json
    http.addHeader("Content-Type", "application/json");

    // Send POST request and check the response
    int httpCode = http.POST(payload);
    http.end();
    Serial.println("Sent value to IFTTT");

}

int get_distance() {
  int distance1, distance2, distance3, distance4, distance5;

   while (true) {
    // Read the distance three times with a 60ms interval
    distance1 = distanceSensor.measureDistanceCm();
    delay(100);
    distance2 = distanceSensor.measureDistanceCm();
    delay(100);
    distance3 = distanceSensor.measureDistanceCm();
    delay(100);
    distance4  = distanceSensor.measureDistanceCm();
    delay(100);
    distance5  = distanceSensor.measureDistanceCm();

    // The sensor isn't accurate, so we need 5 almost identical reading to ensure of its accuracy at one point difference
    // The sensor is only accurate from 20cm to 600cm, it randomly returns 0
    if ((distance1 != 0) && abs(distance1 - distance2) <= 1 && abs(distance1 - distance3) <= 1 && abs(distance1 - distance4) <= 1 && abs(distance1 - distance5) <= 1 && abs(distance2 - distance3) <= 1 && abs(distance2 - distance4) <= 1 && abs(distance2 - distance5) <= 1 && abs(distance3 - distance4) <= 1 && abs(distance3 - distance5) <= 1 && abs(distance4 - distance5) <= 1) {
        return distance1;
        break; // Exit the while loop
        Serial.println("Measurements don't match");
    }
  }
}
