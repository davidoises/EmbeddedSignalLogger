#include <stdio.h>
#include "drivers/device.h"

int main()
{
    int a = device_init(5, 2);

    while(1)
    {
        printf("Hello World simpler %d\n", a);
    }

    return 0;
}
