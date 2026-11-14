#ifndef BMM350_PORT_H
#define BMM350_PORT_H

#include "hal_i2c.h"
#include "hal_clock.h"
#include "bmm350_defs.h"



/* this intf struct allows us to provide information to our functions that bosch does not provide*/

typedef struct
{
    hal_i2c_t* bus;
    hal_clock_t* clk;  /*clk is for the delay call that we will have to eventually use*/
    uint8_t device_address;
} bmm350_intf_t;

typedef struct 
{
    float mag_X_mgauss;
    float mag_Y_mgauss;
    float mag_Z_mgauss;
    float temp_C; 
}bmm350_data_t;


typedef enum
{
    BMM350_OK = 0,
    BMM350_ERR_INIT,
    BMM350_ERR_CHIPID
    
}bmm350_err_t;

/* This init takes the struct provided by Bosch and our I2C struct to initialize the bmm350 
    intf must outlive the device, we must fill out the 3 members of the intf struct before initializing
*/
bmm350_err_t bmm350_port_init(struct bmm350_dev *dev, bmm350_intf_t *intf);

/*Takes the device struct and fills out the bmm350's data fields
    units out: mgauss (per the mission requirements) converted from Bosch’s µT


*/

/* bmm350_dev is the struct that Bosch used to connect their platform to our hardware*/
bmm350_err_t bmm350_port_read(struct bmm350_dev *dev, bmm350_data_t *data);


#endif