#include <unity.h>
#include "altitude.h"

void setUp(void)    { }
void tearDown(void) { }

void test_altitude_values(void)
{
    // 101325, 95461, 89876, 79501 and 69682
    TEST_ASSERT_FLOAT_WITHIN(1, 0, calculate_altitude(101325.0));
    TEST_ASSERT_FLOAT_WITHIN(1, 499.99, calculate_altitude(95461.0));
    TEST_ASSERT_FLOAT_WITHIN(1, 999.87, calculate_altitude(89876.0));
    TEST_ASSERT_FLOAT_WITHIN(1, 1999.41, calculate_altitude(79501.0));
    TEST_ASSERT_FLOAT_WITHIN(1, 3047.96, calculate_altitude(69682.0));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_altitude_values);
    return UNITY_END();
}