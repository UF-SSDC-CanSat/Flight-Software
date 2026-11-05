#ifndef BMM350_H
#define BMM350_H

#include "hal_i2c.h"
#include "hal_clock.h"
#include "bmm350_defs.h"

typedef struct 
{
    hal_i2c_t* bus;
    hal_clock_t* clk;
    uint8_t device_address;
} bmm350_intf_t;


typedef enum
{
    BMM350_ERR_BUS,
    BMM350_ERR_INNIT,
    BMM350_ERR_CHIPID
}bmm350_err_t;

bmm350_err_t BMM350_init(struct bmm350_dev* bmm350, struct bmm350_intf_t* )










#endif