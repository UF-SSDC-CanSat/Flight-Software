#include <unity.h>
#include "bmp5.h"

void setUp(void)    { }
void tearDown(void) { }

int8_t mock_read(uint8_t reg_addr, uint8_t *read_data, uint32_t len, void *intf_ptr){
    // if not temp data reg or incorrect byte count
    if(reg_addr != BMP5_REG_TEMP_DATA_XLSB || len != 6)
        return -1;
    
    uint32_t temp = 25 * 65536; // 25 C
    uint32_t press = 101325 * 64; // 101325 Pa

    // registers store 8 bytes with least significant first
    read_data[0] = temp & 0xFF;
    read_data[1] = (temp >> 8) & 0xFF;
    read_data[2] = (temp >> 16) & 0xFF;
    read_data[3] = press & 0xFF;
    read_data[4] = (press >> 8) & 0xFF;
    read_data[5] = (press >> 16) & 0xFF;

    return BMP5_INTF_RET_SUCCESS;
}

int8_t mock_write(uint8_t reg_addr, const uint8_t *read_data, uint32_t len, void *intf_ptr){
    return BMP5_INTF_RET_SUCCESS;
}

void mock_delay(uint32_t period, void *intf_ptr){
    
}

void test_values(void)
{
    // sensor init
    struct bmp5_dev sensor = {
        .chip_id = 0,
        .intf_ptr = NULL,
        .read = mock_read,
        .write = mock_write,
        .delay_us = mock_delay,
        .intf_rslt = BMP5_INTF_RET_SUCCESS,
        .intf = BMP5_I2C_INTF,
    };

    // enable pressure
    struct bmp5_osr_odr_press_config sensor_config = {
        .press_en = BMP5_ENABLE
    };

    struct bmp5_sensor_data sensor_data = {0};

    int8_t sensor_results = bmp5_get_sensor_data(&sensor_data, &sensor_config, &sensor);
    
    TEST_ASSERT_EQUAL(BMP5_OK, sensor_results);
    TEST_ASSERT_FLOAT_WITHIN(0.1, 25.0, sensor_data.temperature);
    TEST_ASSERT_FLOAT_WITHIN(1.0, 101325.0, sensor_data.pressure);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_values);
    return UNITY_END();
}