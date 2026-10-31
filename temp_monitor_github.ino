#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
void setup() {
Serial.begin(115200);
dht.begin();
WiFi.begin(ssid, password);
Serial.print("Connecting to Wi-Fi");
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("\\nWi-Fi connected!");
ThingSpeak.begin(client);
}
void loop() {
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
if (WiFi.status() == WL_CONNECTED &&
!isnan(temperature) && !isnan(humidity)) {
ThingSpeak.setField(1, temperature);
ThingSpeak.setField(2, humidity);
int result = ThingSpeak.writeFields(
channelID, writeAPIKey
);
if (result == 200) {
Serial.println("Data uploaded successfully!");
} else {
Serial.printf("Upload failed: %d\\n", result);
}
Serial.printf("Temperature: %.1f C\\n", temperature);
Serial.printf("Humidity: %.1f %%\\n", humidity);
} else {
Serial.println("Wi-Fi disconnected or sensor error");
}
delay(20000); // Upload every 20 seconds
}