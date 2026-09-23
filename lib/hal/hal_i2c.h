#ifndef HAL_I2C_H
#define HAL_I2C_H


#include "hal_err.h"
#include <stdint.h>
#include <stddef.h>

/*
*device address 7 bit and unshifted
*Register addressing is 8 bit, always.
*Calls block, so the bytes are in the buffer when read_reg returns
*The backend serialises the bus, drivers never lock
*/

typedef struct
{
    void *ctx;
    hal_err_t (*read_reg)(void *ctx, uint8_t device_address, uint8_t reg, uint8_t *rx, size_t byte_num);
    hal_err_t (*write_reg)(void *ctx, uint8_t device_address, uint8_t reg, const uint8_t *tx, size_t byte_num);
}hal_i2c_t;



#endif