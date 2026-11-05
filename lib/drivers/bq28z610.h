/*
 * BQ28Z610I2C.h
 *
 *  Created on: Sep 14, 2026
 *      Author: Joel
 *          Transitioned from STM to ESP by Anthony
 */

#ifndef BQ28Z610_H
#define BQ28Z610_H

#include "hal_i2c.h"

#include <stdint.h>

hal_err_t BQ28Z610_ReadVoltage(hal_i2c_t *bus, uint16_t *voltage);
hal_err_t BQ28Z610_ReadCurrent(hal_i2c_t *bus, int16_t *current);








#endif