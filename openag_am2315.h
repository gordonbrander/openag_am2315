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

  Modified for OpenAg
 ****************************************************/
#ifndef OPENAG_AM2315
#define OPENAG_AM2315

#if defined(ARDUINO) && (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#if defined(__AVR__)
  #include <util/delay.h>
#endif

#include <Wire.h>
#include <std_msgs/Float32.h>

/**
 * \brief Air temperature and air humidity sensor.
 */
class Am2315 {
  public:
    // Public variables
    bool has_error;
    char* error_msg;

    // Public methods
    void begin();
    void update();
    bool get_air_temperature(std_msgs::Float32 &msg);
    bool get_air_humidity(std_msgs::Float32 &msg);

  private:
    // Private variables
    float _air_temperature;
    float _air_humidity;
    bool _send_air_temperature;
    bool _send_air_humidity;
    uint32_t _time_of_last_reading;
    const static uint32_t _min_update_interval = 2000;
    const static int _i2c_address = 0x5c;
    const static int _read_register = 0x03;

    // Private methods
    void readData();
};

#endif
