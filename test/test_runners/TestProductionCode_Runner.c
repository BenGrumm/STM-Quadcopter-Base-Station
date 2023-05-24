#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(AverageCode)
{
  RUN_TEST_CASE(AverageCode, Simple_Test);
  RUN_TEST_CASE(AverageCode, Null_Test);
  RUN_TEST_CASE(AverageCode, Random_Test);
}

TEST_GROUP_RUNNER(BlinkCode)
{
  RUN_TEST_CASE(BlinkCode, LED_On);
}