#include <unity.h>
#include "hal_err.h"
#include "hal_spi.h"
#include "hal_i2c.h"
#include "hal_gpio.h"
#include "hal_clock.h"

void setUp(void)    { }
void tearDown(void) { }

void test_harness_works(void)
{
    TEST_ASSERT_EQUAL_INT(4, 2 + 2);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_harness_works);
    return UNITY_END();
}