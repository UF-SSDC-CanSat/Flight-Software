#include "baro_cal.h"
#include <math.h>



#define CAL_MAX_SAMPLES 32
#define CAL_MIN_SAMPLES 3
#define CAL_OUTLIER_THRESHOLD_PA 250.0 // Number derived from 2026's flight log glitches

cal_err_t calibrate_pressure(const double* samples, size_t count, double* out_pressure, size_t* out_rejected)
{
    double copy[CAL_MAX_SAMPLES];
    

    if (count > CAL_MAX_SAMPLES) {
    return CAL_SAMPLE_OVERLOAD;
    }

    if (count < CAL_MIN_SAMPLES)
    {
        return CAL_MISSING_SAMPLE;
    }
    
    for (size_t i = 0; i < count; i++)
    {
        copy[i] = samples[i];
    }

    for ( size_t i = 1; i < count; i++) //sort into ascending order to find median
    {
        double temp = copy[i];
        size_t j = i;

        while (j > 0 && copy[j-1] > temp) 
        {
            copy[j] = copy[j-1];
            j--;
        }
        copy[j] = temp;
    }

    double median;

    if (count % 2 == 0)
    {
        median = (copy[(count / 2)] + copy[(count / 2 - 1)]) / 2.0;
    }
    else
    {
        median = copy[count / 2]; 
    }
    
    double sum = 0;
    size_t valid_count = 0;
    size_t rej_count = 0;

    for (size_t i = 0; i < count;i++)
    {
        double difference = fabs(samples[i] - median);
        if (difference > CAL_OUTLIER_THRESHOLD_PA)
        {
            rej_count++;
        }
        else
        {
            sum += samples[i];
            valid_count++;
        }
    }

    if (valid_count == 0 )
    {
        return CAL_SCATTER;
    }
    
    
    *out_pressure = sum / valid_count;
    *out_rejected = rej_count;
    double quarter_percent = count / 4;

    if ( rej_count > quarter_percent)
    {
        return CAL_SCATTER;
    }
    else
    {
        return CAL_OK;
    }
}