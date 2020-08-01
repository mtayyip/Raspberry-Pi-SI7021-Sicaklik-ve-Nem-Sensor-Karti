/*  https://wiki.dfrobot.com/SI7021_Temperature_and_humidity_sensor_SKU_TOY0054
    16 bit
    Measure Temperature, Hold Master Mode 0xE3
    Measure Relative Humidity, Hold Master Mode 0xE5

    The Si7021 communicates with the host controller over a digital I2C interface. The 7-bit base slave address is0x40.
*/

#ifndef HUMIDITY_TEMPERATURE_H_
#define HUMIDITY_TEMPERATURE_H_

#define I2C_ADDR  0x40 

double getHumidity(int handle);
double getTemperature(int handle);

#endif 