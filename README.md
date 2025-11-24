#IoT Environmental Monitoring System

This project is a simple, low-cost IoT system that monitors temperature and humidity using an ESP32-C3 microcontroller and publishes data to the HiveMQ public MQTT broker, with visualization on a Node-RED dashboard

ESP32-C3 + DHT11 + NeoPixel + MQTT + Node-RED

#Features

Real-time sensor data (every 10 seconds)

MQTT publish/subscribe communication

Node-RED dashboard with gauges & charts

NeoPixel LED color alerts

JSON-formatted MQTT messages

Auto reconnection for Wi-Fi & MQTT

#Hardware

ESP32-C3

DHT11 temperature & humidity sensor

WS2812 / NeoPixel LED

Breadboard & jumper wires

#MQTT Setup

Broker:
```
broker.hivemq.com
Port: 1883
```

Publish topic:
```
H00519258/evt/status/fmt/json
```

Subscribe topic:
```
H00519258/cmd/display/fmt/json
```

Example JSON:
```
{ "d": { "temp": 26.5, "humidity": 62.1 } }
```

#LED Temperature Indication
Temperature	LED Color
```
< 0°C	Blue
0–10°C	Light Blue
10–25°C	Green
25–30°C	Orange
> 30°C	Red
```
#Node-RED Dashboard

Includes:

Temperature gauge

Humidity gauge

Trend charts
