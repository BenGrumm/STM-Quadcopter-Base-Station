#include "unity.h"
#include "unity_fixture.h"

#include "blink.h"
#include "stm32_hal_gpio_stub.h"
#include "cmsis_osStub.h"

TEST_GROUP(BlinkCode);

TEST_SETUP(BlinkCode)
{
}

TEST_TEAR_DOWN(BlinkCode)
{
}

TEST(BlinkCode, LED_On)
{
  GPIO_TypeDef temp;
  HAL_GPIO_Stub_Setup(&temp);

  blinkAndWait(&temp, 0, 500);

  TEST_ASSERT_EQUAL(temp.ledState, GPIO_ON);
}
