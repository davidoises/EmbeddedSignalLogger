#include "timer_driver.h"

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "cputimer.h"
#include "interrupt.h"
#include "device.h"

#define TIMER_PERIOD_SEC 0.5
#define CPU_TIMER_COUNT_PERIOD ((uint32_t)(DEVICE_SYSCLK_FREQ*TIMER_PERIOD_SEC))

void timer_driver_init(void)
{
    CPUTimer_setEmulationMode(CPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(CPUTIMER0_BASE, 1U);
	CPUTimer_setPeriod(CPUTIMER0_BASE, CPU_TIMER_COUNT_PERIOD);// 50e6/100e6 = 0.5secs
	CPUTimer_enableInterrupt(CPUTIMER0_BASE);
	CPUTimer_stopTimer(CPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(CPUTIMER0_BASE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void timer_driver_interrupt_init()
{
    EALLOW;
	// Interrupt Settings for INT_myCPUTIMER0
	Interrupt_register(INT_TIMER0, &timer0_isr);
    EDIS;
	Interrupt_enable(INT_TIMER0);
}

void timer_driver_start()
{
    //
    // Start CPU Timer 0
    //
    CPUTimer_startTimer(CPUTIMER0_BASE);
}

void timer_driver_clear_ack()
{
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
