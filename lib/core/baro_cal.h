
//Returns calibrated PRESSURE not ALTITUDE

//samples and out_pressure are Pa , out_rejected is the amount of samples discarded as outliers, HIGH count means recalibrate   

#ifndef BARO_CAL_H
#define BARO_CAL_H

#include <stddef.h>


typedef enum
{
    CAL_OK = 0,
    CAL_MISSING_SAMPLE,
    CAL_SCATTER,
    CAL_SAMPLE_OVERLOAD,
} cal_err_t;

cal_err_t calibrate_pressure(const double* samples, size_t count, double* out_pressure, size_t* out_rejected);



#endif 