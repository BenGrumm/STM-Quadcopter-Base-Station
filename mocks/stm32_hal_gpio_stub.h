#ifndef STM32_HAL_GPIO_STUB_H
#define STM32_HAL_GPIO_STUB_H

#include <stdint.h>

#define GPIO_OFF 0
#define GPIO_ON 1

typedef struct {
    uint8_t ledState;
} GPIO_TypeDef;

void HAL_GPIO_Stub_Setup(GPIO_TypeDef* GPIOx);
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif