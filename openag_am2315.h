/** 
 *  \file openag_am2315.h
 *  \brief Air temperature and air humidity sensor.
 */
/*************************************************** 
  This is a library for the AM2315 Humidity Pressure & Temp Sensor

  Designed specifically to work with the AM2315 sensor from Adafruit
  ----> https://www.adafruit.com/products/1293

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#ifndef OPENAG_AM2315
#define OPENAG_AM2315

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#if defined(__AVR__)
  #include <util/delay.h>
#endif

#include <Wire.h>
#include <openag_peripheral.h>

#define I2C_ADDRESS          0x5C
#define READ_REGISTER        0x03
#define MIN_UPDATE_INTERVAL  2000 // milliseconds
#define AIR_TEMPERATURE_KEY  "air_temperature"
#define AIR_HUMIDITY_KEY     "air_humidity"

/**
 * \brief Air temperature and air humidity sensor.
 */
class Am2315 : public Peripheral {
 public:
  // Public variables
  float air_temperature;
  float air_humidity;

  // Public methods
  Am2315(String id); // constructor
  ~Am2315(); // desctructor
  void begin();
  String get(String key);
  String set (String key, String value);

 private:
  // Private variables
  uint32_t _time_of_last_reading;
  String _air_temperature_message;
  String _air_humidity_message;

  // Private functions
  void readData();
  String getAirTemperature();
  String getAirHumidity();
};

#endif