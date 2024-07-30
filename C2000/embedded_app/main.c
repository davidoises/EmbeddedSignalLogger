#include "drivers/device.h"
#include <stdio.h>
// #include "drivers/device.h"


int main()
{
    device_init();

    while(1)
    {
        printf("Hello World simpler %d\n", 10);
    }

    return 0;
}
