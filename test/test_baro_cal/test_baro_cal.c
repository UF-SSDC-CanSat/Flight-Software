#include "baro_cal.h"

#include <unity.h>

void setUp(void)    { }
void tearDown(void) { }

void test_clean_samples_average_correctly(void)
{
    double out_pressure;
    size_t out_rejected;
    double samples[] = {88736, 88962, 92256, 92018, 92357, 92393, 92377, 92398, 91827, 92370};
    cal_err_t err = calibrate_pressure(samples, 10, &out_pressure, &out_rejected);
    TEST_ASSERT_EQUAL_INT(CAL_SCATTER, err);
    TEST_ASSERT_EQUAL_UINT(4, out_rejected);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 92358.5, out_pressure);

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_clean_samples_average_correctly);
    return UNITY_END();
}

