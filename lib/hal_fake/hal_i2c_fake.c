
#include "hal_i2c_fake.h"
#include <string.h>
static hal_err_t fake_read_reg(void *ctx, uint8_t addr, uint8_t reg, uint8_t *rx, size_t len)
{
    fake_i2c_t *f = (fake_i2c_t *)ctx;
    f->last_address = addr;
    f->last_reg = reg;

    if (len > sizeof(f->canned)) {
    return HAL_ERR_PARAM;
}
    
    memcpy(rx, f->canned, len);
    return f->next_result;

}

static hal_err_t fake_write_reg(void *ctx, uint8_t addr, uint8_t reg, const uint8_t *tx, size_t len)
{
    fake_i2c_t *f = (fake_i2c_t *)ctx;
    f->last_address = addr;
    f->last_reg = reg;
    (void)tx;
    (void)len;
    

    return f->next_result;
}


void fake_i2c_init(hal_i2c_t *bus, fake_i2c_t *f)
{
    bus->read_reg  = fake_read_reg;
    bus->write_reg = fake_write_reg;
    bus->ctx       = f;
}


