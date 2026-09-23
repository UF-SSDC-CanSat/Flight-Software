
#ifndef HAL_ERR_H
#define HAL_ERR_H

typedef enum
{
    HAL_OK = 0,
    HAL_ERR_TIMEOUT,
    HAL_ERR_BUS,
    HAL_ERR_PARAM,
} hal_err_t;

#endif