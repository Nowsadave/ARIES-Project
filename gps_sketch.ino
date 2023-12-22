#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(5, 4);  // RX, TX pins for GPS module

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void loop() {
  if (gpsSerial.available() > 0) {
    if (gpsSerial.find("$GPGGA")) {
      String data = gpsSerial.readStringUntil('\n');
      // Parse the NMEA sentence to extract latitude and longitude
      float latitude = parseNMEA(data, 2);
      float longitude = parseNMEA(data, 4);

      // Print the results to the Serial Monitor
      Serial.print("Latitude: ");
      Serial.print(latitude, 6);
      Serial.print(", Longitude: ");
      Serial.println(longitude, 6);
    }
  }
}

float parseNMEA(String data, int index) {
  // Function to parse NMEA sentence and extract data at specified index
  int commaCount = 0;
  int startIndex = 0;
  int endIndex = -1;

  for (int i = 0; i < data.length(); i++) {
    if (data[i] == ',') {
      commaCount++;

      if (commaCount == index) {
        startIndex = i + 1;
      } else if (commaCount == index + 1) {
        endIndex = i;
        break;
      }
    }
  }

  if (endIndex > startIndex) {
    String value = data.substring(startIndex, endIndex);
    return value.toFloat();
  }

  return 0.0;
}

