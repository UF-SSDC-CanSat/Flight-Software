#include "math.h"

//  meters from pascals
float calculate_altitude(double pressure) {
    if (pressure <= 0 || pressure > 101325.0) {
        return -1.0; // invalid
    }

    float altitude = 44330.77 * (1.0 - pow(pressure / 101325.0, 0.19026));

    return altitude;
}