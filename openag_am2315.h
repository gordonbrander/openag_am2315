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

/**
 * \brief Air temperature and air humidity sensor.
 */
class Am2315 : public Peripheral {
 public:
  // Public variables
  float air_temperature;
  float air_humidity;

  // Public methods
  Am2315(String id, String* parameters); // constructor
  ~Am2315(); // desctructor
  void begin();
  String get(String key);
  String set (String key, String value);

 private:
  // Private variables
  uint32_t _time_of_last_reading;
  String _air_temperature_message;
  String _air_humidity_message;
  const static uint32_t _min_update_interval = 2000;
  String _air_temperature_key;
  String _air_humidity_key;
  const static int _i2c_address = 0x5c;
  const static int _read_register = 0x03;

  // Private functions
  void readData();
  String getAirTemperature();
  String getAirHumidity();
};

#endif
