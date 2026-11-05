#ifndef SG90_H
#define SG90_H

#include <stdint.h>
#include "esp_err.h"
#include "driver/ledc.h"

esp_err_t sg90_init(int gpio, ledc_channel_t channel);
esp_err_t sg90_rotate(ledc_channel_t channel, float angle);

#endif