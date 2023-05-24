#include "blink.h"

void blinkAndWait(GPIO_TypeDef* GPIOx ,uint16_t pin, uint32_t timeMilli){
    HAL_GPIO_TogglePin(GPIOx, pin);
    osDelay(timeMilli);
}