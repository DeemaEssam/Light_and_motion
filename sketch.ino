#include <WiFi.h>
#include <HTTPClient.h>

const int ledPin = 25;
const int lightSensorPin = 34; // Analog pin for light sensor
const int pirSensorPin = 27;   // Digital pin for PIR sensor

// Replace with your network credentials
const char *ssid = "Smart_Methods1";
const char *password = "123456789";

// Replace with your server's URL
const char *serverName = "http://update_sensor_data.php";

// Define the threshold for light level
const int LIGHT_THRESHOLD = 1000;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(pirSensorPin, INPUT);
  pinMode(lightSensorPin, INPUT);
  Serial.begin(115200);
  connectToWiFi();
}

void loop()
{
  int lightLevel = analogRead(lightSensorPin);
  bool motionDetected = digitalRead(pirSensorPin);

  // Print sensor values for debugging
  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print(" | Motion Detected: ");
  Serial.println(motionDetected);

  // Determine LED state based on light and motion sensor readings
  if (lightLevel > LIGHT_THRESHOLD && motionDetected == HIGH)
  {
    // No light and motion detected
    digitalWrite(ledPin, HIGH); // Turn LED on
  }
  else
  {
    digitalWrite(ledPin, LOW); // Turn LED off
  }

  // Send data to the server
  sendToServer(lightLevel, motionDetected);

  delay(10000); // Delay between readings
}

void connectToWiFi()
{
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
}

void sendToServer(int lightLevel, bool motionDetected)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    String url = String(serverName) + "?light=" + String(lightLevel) + "&motion=" + (motionDetected ? "1" : "0");

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
      String payload = http.getString();
      Serial.println("Server Response: " + payload);
    }
    else
    {
      Serial.println("Error on HTTP request: " + String(httpCode));
    }

    http.end();
  }
  else
  {
    Serial.println("Error: Not connected to WiFi");
  }
}