#include <openag_am2315.h>

Am2315 am2315;

void setup() {
  Serial.begin(9600);
  am2315.begin();
}

std_msgs::Float32 air_temp;
std_msgs::Float32 air_humidity;

void loop() {
  if (am2315.get_air_temperature(air_temp)) {
    Serial.print("Air Temperature: ");
    Serial.println(air_temp.data);
  }
  if (am2315.get_air_humidity(air_humidity)) {
    Serial.print("Air Humidity: ");
    Serial.println(air_humidity.data);
  }
  if (am2315.has_error) {
    Serial.print("am2315:");
    Serial.println(am2315.error_msg);
    am2315.has_error = false;
  }
}
