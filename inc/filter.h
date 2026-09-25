#ifndef _PLAUSIBILITY_FILTER_
#define _PLAUSIBILITY_FILTER_

typedef struct FilterInfo
{
    float sensor_reading;
    float baseline;
    float threshold;
} FilterInfo;

//In the sensor read loop, determine whether drastic changes in sensor readings are plausibile by rejecting the changes (return false) if they exceed a certain threshold for reasonable changes in the value;
//However, if the value has been rejected more than max_rejections, we are most likely facing a real change in the readings and will return true
bool plausibility_filter(const FilterInfo* const sensor_changes, int* rejections, const int max_rejections);

#endif