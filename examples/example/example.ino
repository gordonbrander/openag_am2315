#include <openag_am2315.h>
String parameters[] = {};
Am2315 am2315_1("am2315_1", parameters);

void setup() {
  Serial.begin(9600);
  am2315_1.begin();
}

void loop() {
  Serial.println(am2315_1.get("air_temperature"));
  Serial.println(am2315_1.get("air_humidity"));
  Serial.println();
  delay(1000);
}
