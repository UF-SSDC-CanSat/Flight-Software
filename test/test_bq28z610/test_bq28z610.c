#include <unity.h>
#include "hal_i2c_fake.h"
#include "bq28z610.h"


void setUp(void)    { }
void tearDown(void) { }

void test_voltage_decodes(void)
{
    
    fake_i2c_t f;
    hal_i2c_t bus;
    f.canned[0] = 0x9C;
    f.canned[1] = 0x0F;
    f.next_result = HAL_OK;

    fake_i2c_init(&bus, &f);

    uint16_t voltage;
    BQ28Z610_ReadVoltage(&bus, &voltage);
    TEST_ASSERT_EQUAL_UINT16(3996, voltage);

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_voltage_decodes);
    return UNITY_END();
}