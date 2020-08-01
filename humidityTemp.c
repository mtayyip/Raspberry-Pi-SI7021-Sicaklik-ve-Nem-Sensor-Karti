#include <stdint.h>
#include <stdio.h>
#include "i2c.h"
#include "humidityTemp.h"
#include <math.h>
#include <stdint.h>
#include <unistd.h>

double getTemperature(int handle)
{
    unsigned char temp1Data, temp2Data;
    int16_t rawData;
    if(i2cRead(handle,0xE3,&temp1Data,1) < 0)
    {
        printf("ERROR : getTemperature\r\n");
        return -1;
    }
    if(i2cRead(handle,0xE4,&temp2Data,1) < 0)
    {
        printf("ERROR : getTemperature\r\n");
        return -1;
    }

    rawData = ((temp1Data<<8)|temp2Data);
    return ((rawData* 175.72) / 65536) - 46.85;
}

double getHumidity(int handle)
{
    unsigned char hum1Data, hum2Data;
    double retVal=0;
    if(i2cRead(handle,0xE5,&hum1Data,1) < 0)
    {
        printf("ERROR : getHumidity\r\n");
        return -1;
    }
    if(i2cRead(handle,0xE6,&hum2Data,1) < 0)
    {
        printf("ERROR : getHumidity\r\n");
        return -1;
    }

    retVal = ((hum1Data<<8)|hum2Data);
    retVal = ((retVal*125) / 65536.0) - 6 ; 
    return retVal;
}