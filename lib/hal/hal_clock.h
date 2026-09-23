#ifndef HAL_CLOCK_H
#define HAL_CLOCK_H

#include <stdint.h>



/*
*delay:ms <yields>, < waits at least n amount of milliseconds not exact>
*now_ms <counts the milliseconds since boot, monotonic and wraps>
*All calls block (Meaning the function will not return anything until finished)
*do not call delay_ms while a device transaction is in progress, because another task runs during the wait and may use the same bus. Finish the transaction first.
*/

typedef struct {
    void *ctx;
    void (*delay_ms)(void *ctx, uint32_t ms);
    uint32_t (*now_ms)(void *ctx);
} hal_clock_t;

#endif 