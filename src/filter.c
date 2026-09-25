
#include "../inc/filter.h"
#include <stdbool.h>
#include <math.h>

bool plausibility_filter(const FilterInfo* const sensor_changes, int* rejections, const int max_rejections)
{
    const float change_in_reading = abs(sensor_changes->sensor_reading - sensor_changes->baseline);

    if (change_in_reading > sensor_changes->baseline)
    {
        *rejections++;

        if (*rejections > max_rejections)
        {
            return true;
        }

        return false;
    }

    return true;
}