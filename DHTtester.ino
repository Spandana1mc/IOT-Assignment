#include <WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

// --------------------------------------------------------------------------------------------
//        UPDATE THESE SETTINGS
// --------------------------------------------------------------------------------------------
#define MQTT_HOST "broker.hivemq.com"  // Example public broker
#define MQTT_PORT 1883
#define MQTT_DEVICEID "H00519258"
#define MQTT_USER ""
#define MQTT_TOKEN ""
#define MQTT_TOPIC "H00519258/evt/status/fmt/json"
#define MQTT_TOPIC_DISPLAY "H00519258/cmd/display/fmt/json"

#define RGB_PIN 2   // NeoPixel data pin
#define DHT_PIN 3 // DHT11 data pin
#define DHTTYPE DHT11
#define NEOPIXEL_TYPE NEO_RGB + NEO_KHZ800

// Temperature thresholds
#define ALARM_COLD 0.0
#define ALARM_HOT 30.0
#define WARN_COLD 10.0
#define WARN_HOT 25.0

// WiFi credentials
char ssid[] = "Spandana";
char pass[] = "123456789";

// --------------------------------------------------------------------------------------------
//        GLOBAL OBJECTS AND VARIABLES
// --------------------------------------------------------------------------------------------
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, RGB_PIN, NEOPIXEL_TYPE);
DHT dht(DHT_PIN, DHTTYPE);
WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

StaticJsonDocument<200> jsonDoc;
float t = 0.0;
float h = 0.0;

// --------------------------------------------------------------------------------------------
//        MQTT CALLBACK FUNCTION
// --------------------------------------------------------------------------------------------
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  payload[length] = 0; // null-terminate
  Serial.println((char *)payload);
}

// --------------------------------------------------------------------------------------------
//        CONNECT TO WIFI
// --------------------------------------------------------------------------------------------
void connectWiFi() {
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
}

// --------------------------------------------------------------------------------------------
//        CONNECT TO MQTT BROKER
// --------------------------------------------------------------------------------------------
void connectMQTT() {
  while (!mqtt.connected()) {
    Serial.print("Connecting to MQTT...");
    if (mqtt.connect(MQTT_DEVICEID, MQTT_USER, MQTT_TOKEN)) {
      Serial.println("connected!");
      mqtt.subscribe(MQTT_TOPIC_DISPLAY);
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqtt.state());
      Serial.println(" — retrying in 5s");
      delay(5000);
    }
  }
}

// --------------------------------------------------------------------------------------------
//        SET LED COLOR BASED ON TEMPERATURE
// --------------------------------------------------------------------------------------------
void setLedByTemp(float temp) {
  uint8_t r = 0, g = 0, b = 0;

  if (temp < ALARM_COLD) {          // Very cold
    b = 255;
  } else if (temp < WARN_COLD) {    // Cool
    b = 150;
  } else if (temp <= WARN_HOT) {    // Normal/Comfortable
    g = 255;
  } else if (temp < ALARM_HOT) {    // Warm
    r = 150;
  } else {                          // Hot
    r = 255;
  }

  pixel.setPixelColor(0, pixel.Color(r, g, b));
  pixel.show();
}

// --------------------------------------------------------------------------------------------
//        SETUP
// --------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nESP32 DHT11 + NeoPixel + MQTT Demo");

  pixel.begin();
  dht.begin();

  connectWiFi();

  mqtt.setServer(MQTT_HOST, MQTT_PORT);
  mqtt.setCallback(callback);
  connectMQTT();
}

// --------------------------------------------------------------------------------------------
//        MAIN LOOP
// --------------------------------------------------------------------------------------------
void loop() {
  if (!mqtt.connected()) {
    connectMQTT();
  }
  mqtt.loop();

  h = dht.readHumidity();
  t = dht.readTemperature(); // Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  setLedByTemp(t);

  // Prepare JSON
  jsonDoc.clear();
  JsonObject data = jsonDoc.createNestedObject("d");
  data["temp"] = t;
  data["humidity"] = h;

  char msg[100];
  serializeJson(jsonDoc, msg);

  Serial.print("Publishing: ");
  Serial.println(msg);

  if (!mqtt.publish(MQTT_TOPIC, msg)) {
    Serial.println("Publish failed!");
  }

  delay(5000); // wait 5 seconds
}
