#ifndef BLINK_H
#define BLINK_H

#include <stdint.h>

#ifndef USE_STUBS

#include <cmsis_os.h>
#include <stm32f4xx.h>

#else

#include "cmsis_osStub.h"
#include "stm32_hal_gpio_stub.h"

#endif

void blinkAndWait(GPIO_TypeDef* GPIOx ,uint16_t pin, uint32_t timeMilli);

#endif