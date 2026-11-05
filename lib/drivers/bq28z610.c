/*
 * BQ28Z610I2C.c
 *
 *  Created on: Sep 14, 2026
 *      Author: Joel
 *              Transitioned from STM to ESP by Anthony
 */

 #include "bq28z610.h"
 
 #define CMD_Voltage 0x08
 #define CMD_Current 0x0C
 #define BQ28Z610_I2C_ADDR 0x55

 /* Reads pack voltage.
 * returns a hal_err, mV, 0 to 12000
 * if it returns HAL_OK, *voltage was written. If not, *voltage is untouched and holds whatever it held before.
 */
 
 hal_err_t BQ28Z610_ReadVoltage(hal_i2c_t *bus, uint16_t *voltage)
 {
    uint8_t rx[2];
    hal_err_t status = bus->read_reg(bus->ctx, BQ28Z610_I2C_ADDR, CMD_Voltage, rx, 2);
    if (status == HAL_OK)
    {
        uint16_t shifted = rx[1] << 8;
		uint16_t lower = rx[0];
		*voltage = shifted | lower;
    }

    return status;

 }


 /* Reads current flow through the sense resistor.
 * returns a hal_err, mA, range: not specified
 * returns a signed int value, and updated every 1 s
 */
 

 hal_err_t BQ28Z610_ReadCurrent(hal_i2c_t *bus, int16_t *current)
 {
    uint8_t rx[2];
    hal_err_t status = bus->read_reg(bus->ctx, BQ28Z610_I2C_ADDR, CMD_Current, rx, 2);
    if (status == HAL_OK)
	{
		uint16_t shifted = rx[1] << 8;
		uint16_t lower   = rx[0];
		*current = (int16_t)(shifted | lower);
	}
    return status;
 }