#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <NewPing.h>

// Enter your WiFi credentials here
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Sensor pins
#define TRIGGER_PIN 26
#define ECHO_PIN    25
#define MAX_DISTANCE 400 

// MAKE SURE TO ADJUST THIS VALUE ACCORDING TO YOUR TANK
const int TANK_HEIGHT_CM = 34; // Total height from the sensor to the bottom of the tank (cm)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// This function reads sensor data and sends it to Blynk
void sendSensorData() {
  int distance_cm = sonar.ping_cm();

  Serial.print("Measured Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm == 0) {
    distance_cm = TANK_HEIGHT_CM;
  }

 
  int water_height_cm = TANK_HEIGHT_CM - distance_cm;
  water_height_cm = constrain(water_height_cm, 0, TANK_HEIGHT_CM);

  // Calculate water level percentage
  int level_percent = map(distance_cm, TANK_HEIGHT_CM, 0, 0, 100);
  level_percent = constrain(level_percent, 0, 100);

  // Print values to serial monitor
  Serial.print("Water Height: ");
  Serial.print(water_height_cm);
  Serial.println(" cm");
  Serial.print("Fill Level: %");
  Serial.println(level_percent);
  Serial.println("--------------------");

  // Send data to Blynk virtual pins
  Blynk.virtualWrite(V1, level_percent);      // Send percentage to V1
  Blynk.virtualWrite(V2, water_height_cm);    // Send height in cm to V2
}

// This function is triggered when the button linked to V0 in Blynk is pressed
BLYNK_WRITE(V0)
{
  Serial.println("Refresh request received from Blynk.");
  sendSensorData();
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
