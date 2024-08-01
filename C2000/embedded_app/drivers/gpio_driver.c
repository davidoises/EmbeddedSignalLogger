#include "gpio_driver.h"

#include "device.h"
#include "gpio.h"
#include "asysctl.h"

//*****************************************************************************
//
// Function to disable pin locks and enable pullups on GPIOs.
//
//*****************************************************************************
void gpio_driver_init(void)
{
    EALLOW;

    //
    // Disable DC DC in Analog block
    // This is here beacuse GPIO PIN LED1 is on GPIO23, and TRM mentions DC-DC should
    // be disabled for this GPIO to work
    //
    ASysCtl_disableDCDC();

    //
    // Disable pin locks.
    //
    GPIO_unlockPortConfig(GPIO_PORT_A, 0xFFFFFFFF); // GPIOs 0 - 31
    GPIO_unlockPortConfig(GPIO_PORT_B, 0xFFFFFFFF); // GPIOs 32 - 63
    // GPIO_unlockPortConfig(GPIO_PORT_H, 0xFFFFFFFF); // GPIOs 64 - 95

    //
    //Configure GPIO in Push Pull,Output Mode
    //
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);

    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);

    //
    // Configure GPIO 23 and 34 as digital pins
    //
    GPIO_setAnalogMode(DEVICE_GPIO_PIN_LED1, GPIO_ANALOG_DISABLED);
    GPIO_setAnalogMode(DEVICE_GPIO_PIN_LED2, GPIO_ANALOG_DISABLED);
    EDIS;
}

bool gpio_driver_read(uint16_t channel)
{
    uint16_t result = GPIO_readPin(channel);
    return result;
}

void gpio_driver_set(uint16_t channel, bool val)
{
    GPIO_writePin(channel, (uint16_t)val);
}

void gpio_driver_toggle(uint16_t channel)
{
    GPIO_togglePin(channel);
}
