#ifndef HAL_SPI_H
#define HAL_SPI_H

#include "hal_err.h"
#include <stdint.h>
#include <stddef.h>


/*
*Creates the struct for calling to either transmit or receive
*When rx or tx is NULL, the backend clocks out padding bytes. And for rx NULL: the incoming bytes are discarded.
*One length covers both buffers since SPI moves one bit out and one bit in per clock tick!
*CS is handled in the backend by ESP-IDF.
*Blocking takes place, when the call returns, the transfer is complete and rx is filled.

*/


typedef struct
{
    void *ctx;
    hal_err_t (*transfer)(void *ctx, const uint8_t *tx, uint8_t *rx, size_t length);
} hal_spi_t;




#endif