/*
 * altitude.c
 *
 *  Created on: Sep 23, 2026
 *      Author: Joel
 *          Transitioned from STM to ESP by Prateek
 */

#include <math.h>

//  meters from pascals
double calculate_altitude(double pressure) {
    double altitude = 44330.77 * (1.0 - pow(pressure / 101325.0, 0.19026));

    return altitude;
}