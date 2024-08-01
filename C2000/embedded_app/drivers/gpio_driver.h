#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include "common_types.h"

void gpio_driver_init(void);

bool gpio_driver_read(uint16_t channel);

void gpio_driver_set(uint16_t channel, bool val);

void gpio_driver_toggle(uint16_t channel);

#endif // __GPIO_DRIVER_H__
