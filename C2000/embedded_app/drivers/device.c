#include "device.h"
#include "driverlib.h"

void device_init(void)
{

    // Disable the watchdog
    SysCtl_disableWatchdog();
}
