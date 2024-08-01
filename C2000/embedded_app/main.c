#include <stdio.h>

#include "device.h"
#include "gpio_driver.h"
#include "interrupt.h"


void main(void)
{
    device_init();

    device_init_GPIO();

    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initModule();
    // Initialize the PIE vector table
    Interrupt_initVectorTable();
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)

    // Board init would go here


    EINT;
    ERTM;

    while(1)
    {
        printf("Hello World with blink %d\n", 10);

        // Turn on LED
        gpio_driver_set(DEVICE_GPIO_PIN_LED1, false);
        gpio_driver_toggle(DEVICE_GPIO_PIN_LED2);

        // Delay for a bit.
        DEVICE_DELAY_US(500000);

        // Turn off LED
        gpio_driver_set(DEVICE_GPIO_PIN_LED1, true);

        // Delay for a bit.
        DEVICE_DELAY_US(500000);
    }
}
