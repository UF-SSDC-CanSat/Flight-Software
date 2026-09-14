#ifndef HAL_I2C_FAKE_H
#define HAL_I2C_FAKE_H

#include "hal_i2c.h"

typedef struct {
    uint8_t canned[4];      
    uint8_t last_address;     
    uint8_t last_reg;         
    hal_err_t next_result;    
} fake_i2c_t;

void fake_i2c_init(hal_i2c_t *bus, fake_i2c_t *f);


#endif