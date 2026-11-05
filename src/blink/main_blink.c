#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_system.h>

static const char *TAG = "blink";

void app_main(void)
{
    ESP_LOGI(TAG, "reset reason: %d", esp_reset_reason());
    while (1)
    {
        ESP_LOGI(TAG, "alive");
        vTaskDelay(pdMS_TO_TICKS(500));
    }

}