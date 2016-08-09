#include <openag_am2315.h>

uint32_t last_status_read = 0;
bool should_read_statuses() {
  uint32_t curr_time = millis();
  bool res = (curr_time - last_status_read) > 5000;
  if (res) {
    last_status_read = curr_time;
  }
  return res;
}
Am2315 module;
std_msgs::Float32 module_air_humidity_msg;
std_msgs::Float32 module_air_temperature_msg;

void setup() {
  // Setup all plugins
  Serial.begin(9600);
  // Setup all modules
  module.begin();
}

void loop() {
  // Update all plugins
  if (Serial.available()) {
    String in_str = Serial.readString();
  }
  // Update all modules
  module.update();
  if (module.get_air_humidity(module_air_humidity_msg)) {
    Serial.print("data,module,air_humidity,");
    Serial.println(module_air_humidity_msg.data);
  }
  if (module.get_air_temperature(module_air_temperature_msg)) {
    Serial.print("data,module,air_temperature,");
    Serial.println(module_air_temperature_msg.data);
  }
  // Read statuses of all modules
  if (should_read_statuses()) {
    Serial.print("status,module,");
    Serial.print(module.status_level);
    Serial.print(",");
    Serial.println(module.status_msg);
  }
}
