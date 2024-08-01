#include <stdio.h>

#include "device.h"
#include "pinmux_driver.h"
#include "gpio_driver.h"
#include "interrupt.h"
#include "timer_driver.h"

#define TASK_PRESCALE_100HZ 10
#define TASK_PRESCALE_10HZ  100

__interrupt void timer0_isr(void);

void task_10hz(void);
void task_100hz(void);
void task_1khz(void);

//
// Globals
//
uint32_t cpu_timer0_tick_count = 0; //number of times TIMER 0 ISR is triggered

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

    gpio_driver_set(DEVICE_GPIO_PIN_LED1, false);

    while(1)
    {}
}

__interrupt void timer0_isr(void)
{
    cpu_timer0_tick_count++;

    task_1khz();

    if ((cpu_timer0_tick_count % TASK_PRESCALE_100HZ) == 0)
    {
        task_100hz();
    }

    if ((cpu_timer0_tick_count % TASK_PRESCALE_10HZ) == 0)
    {
        task_10hz();
    }

    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    timer_driver_clear_ack();
}

void task_10hz(void)
{
    printf("Hello World with blink %d\n", 10);

    // gpio_driver_toggle(DEVICE_GPIO_PIN_LED1);
}

void task_100hz(void)
{
    gpio_driver_toggle(DEVICE_GPIO_PIN_LED2);
}

void task_1khz(void)
{
    NOP;
}
