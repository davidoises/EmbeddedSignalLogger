#ifndef __TIMER_DRIVER_H__
#define __TIMER_DRIVER_H__

#include "common_types.h"

void timer_driver_init(void);
void timer_driver_interrupt_init();
void timer_driver_start();
void timer_driver_clear_ack();

extern __interrupt void timer0_isr(void);

#endif // __TIMER_DRIVER_H__
