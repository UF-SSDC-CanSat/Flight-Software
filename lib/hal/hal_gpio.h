#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "hal_err.h"
#include <stdint.h>



typedef struct
{
    void *ctx;
    hal_err_t (*get)(void *ctx, uint8_t pin_number, uint8_t *out_level);
    hal_err_t (*set)(void *ctx, uint8_t pin_number, uint8_t level);
}hal_gpio_t;


#endif