#include <stdio.h>

#include "drivers/device.h"
#include "third_party/driverlib/gpio.h"
#include "third_party/driverlib/interrupt.h"


void main(void)
{
    device_init();

    device_init_GPIO();
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);

    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initModule();
    // Initialize the PIE vector table
    Interrupt_initVectorTable();
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    EINT;
    ERTM;

    while(1)
    {
        printf("Hello World simpler %d\n", 10);

        // Turn on LED
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 0);
        // Delay for a bit.
        DEVICE_DELAY_US(500000);
        // Turn off LED
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 1);
        // Delay for a bit.
        DEVICE_DELAY_US(500000);
    }
}
