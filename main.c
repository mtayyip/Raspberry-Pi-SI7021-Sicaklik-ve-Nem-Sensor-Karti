#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "i2c.h"
#include "humidityTemp.h"
#include <unistd.h>

int main(int argc,char **argv)
{
    int handle=-1;
    if(argc !=2)
    {
		printf("usage: %s i2cDevice\r\n",argv[0]);
		return -1;
    }

    if(i2cInit(argv[1],&handle) < 0 )
    {
        printf("i2cInit handle < 0 (:%d)\r\n",handle);
        return -1;
    }

    if(i2cSetSlave(&handle,I2C_ADDR) < 0 )
    {
        printf("i2cSetSlave < 0\r\n");
        return -1;
    }


    while(1)
    {
        if(handle != -1)
        {
            printf("TEMPERATURE : %.2fC <--> ",getTemperature(handle));
            printf("HUMIDITY : %%%.2f\r\n",getHumidity(handle));
        }
        else
        {
            printf("Handle ERROR\r\n");
            exit(0);
        }

        sleep(1);
    }


    return 0;
}

