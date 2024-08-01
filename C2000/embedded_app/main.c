#include <stdio.h>

#include "device.h"
#include "pinmux_driver.h"
#include "gpio_driver.h"
#include "interrupt.h"
#include "timer_driver.h"

__interrupt void timer0_isr(void);

//
// Globals
//
uint16_t cpuTimer0IntCount = 0; //number of times TIMER 0 ISR is triggered
uint16_t delayCount = 1;        //number (0-9) to scale the LED frequency

void main(void)
{
    device_init();

    pinmux_driver_init();

    gpio_driver_init();

    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initModule();
    // Initialize the PIE vector table
    Interrupt_initVectorTable();
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)

    // {
    // THIS IS THE BOARD INIT BLOCK
    // 1. Add timer configuration calls here: configure hw timer and connect to PIE
    timer_driver_init();
    // 2. Then sciinit would be here for now dont
    // 3. Last should be to initialize the interrupts: register func and enable the actual interrupt

    timer_driver_interrupt_init();
    // }

    EINT;
    ERTM;

    timer_driver_start();

    // gpio_driver_set(DEVICE_GPIO_PIN_LED1, false);

    while(1)
    {
        printf("Hello World with blink %d\n", 10);

        // // Turn on LED
        gpio_driver_set(DEVICE_GPIO_PIN_LED1, false);
        // gpio_driver_toggle(DEVICE_GPIO_PIN_LED2);

        // Delay for a bit.
        DEVICE_DELAY_US(500000);

        // Turn off LED
        gpio_driver_set(DEVICE_GPIO_PIN_LED1, true);

        // // Delay for a bit.
        // DEVICE_DELAY_US(500000);
    }
}

__interrupt void timer0_isr(void)
{
    cpuTimer0IntCount++;
    if (cpuTimer0IntCount >= delayCount){
        cpuTimer0IntCount = 0;
        gpio_driver_toggle(DEVICE_GPIO_PIN_LED2);
    }

    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    timer_driver_clear_ack();
}
