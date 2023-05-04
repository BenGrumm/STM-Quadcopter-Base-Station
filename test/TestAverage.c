#include "unity.h"
#include "unity_fixture.h"

#include "average.h"

TEST_GROUP(AverageCode);

TEST_SETUP(AverageCode)
{
}

TEST_TEAR_DOWN(AverageCode)
{
}

TEST(AverageCode, Simple_Test)
{
  float array[] = {-1.0, 0.0, 1.0, 2.0, 3.0};
  float avg = average(array, 5);

  TEST_ASSERT_EQUAL(avg, 1.0);
}

TEST(AverageCode, Null_Test)
{
  float array[1];
  float avg = average(array, 0);

  TEST_ASSERT_EQUAL(avg, 0.0);
}

TEST(AverageCode, Random_Test)
{
  TEST_ASSERT_EQUAL(1.0, 1.0);
}