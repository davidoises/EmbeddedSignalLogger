#include "device.h"
// #include "driverlib.h"

#include "../third_party/driverlib/sysctl.h"

void device_init(void)
{
    // Disable the watchdog
    SysCtl_disableWatchdog();


}
