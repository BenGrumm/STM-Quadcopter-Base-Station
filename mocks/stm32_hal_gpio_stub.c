#include "stm32_hal_gpio_stub.h"

void HAL_GPIO_Stub_Setup(GPIO_TypeDef* GPIOx){
    GPIOx->ledState = 0;
}

void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    GPIOx->ledState = ~GPIOx->ledState;
}