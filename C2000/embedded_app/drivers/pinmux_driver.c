#include "pinmux_driver.h"
#include "gpio.h"
#include "pin_map.h"

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void pinmux_driver_init()
{
    // GPIO23 -> GPIO Pinmux
	GPIO_setPinConfig(GPIO_23_GPIO23);

    // GPIO34 -> GPIO Pinmux
	GPIO_setPinConfig(GPIO_34_GPIO34);
}
