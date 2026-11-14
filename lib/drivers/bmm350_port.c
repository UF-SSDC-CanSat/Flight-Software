#include "bmm350_port.h"
#include "bmm350.h"

#include <stint.h>

/*notes for Anthony rn so I don't forget. These are the definitions that bosch provides and needs to fill their struct when initializing. 
Each field in the struct is a function pointer( that calls our wrapper in order to provide info that bosch does not give)*/

static BMM350_INTF_RET_TYPE bmm350_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    bmm350_intf_t *intf = (bmm350_intf_t *)intf_ptr;
    hal_err_t e = intf->bus->read_reg(intf->bus->ctx,intf->device_address, reg_addr, reg_data, len );
    if (e != HAL_OK)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

static BMM350_INTF_RET_TYPE bmm350_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    bmm350_intf_t *intf = (bmm350_intf_t *)intf_ptr;
    hal_err_t e = intf->bus->write_reg(intf->bus->ctx, intf->device_address, reg_addr, reg_data, len);
    if (e != HAL_OK)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*begin working on the delay function make sure to understand the units and what the mission guide needs*/




