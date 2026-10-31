# ESP32 + DHT11 IoT Temperature and Humidity Monitor

A low-cost IoT project that measures temperature and humidity with a DHT11 sensor and an ESP32, uploads the readings to ThingSpeak over Wi-Fi, and shows them on a live web dashboard with threshold alerts.

## How it works
DHT11 sensor -> ESP32 -> Wi-Fi -> ThingSpeak channel -> web dashboard

- The ESP32 reads the sensor and uploads every 20 seconds (Field 1: temperature, Field 2: humidity).
- The dashboard reads the latest values from ThingSpeak and turns red when a value goes above its limit.

## Components
- ESP32 development board
- DHT11 sensor module
- Breadboard and jumper wires
- Micro-USB cable
- 2.4 GHz Wi-Fi network

## Wiring
| DHT11 pin | ESP32 pin |
|-----------|-----------|
| VCC       | 3V3       |
| GND       | GND       |
| DATA      | GPIO 4    |

## Libraries (Arduino IDE)
- DHT sensor library (Adafruit)
- Adafruit Unified Sensor
- ThingSpeak (MathWorks)

## How to run
1. Create a ThingSpeak channel with Field 1 = Temperature and Field 2 = Humidity.
2. In the sketch, replace the placeholders with your own Wi-Fi name, password, Channel ID and Write API Key.
3. Upload the sketch to the ESP32 and open the Serial Monitor at 115200 baud.
4. Open the dashboard HTML file, put your Channel ID in `CHANNEL_ID`, and make the channel Public.

## Note
Never share your Wi-Fi password or Write API Key.
