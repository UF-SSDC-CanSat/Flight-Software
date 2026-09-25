#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "RTOS_DEMO";

// TASKS
// Thread 1: read sensors
// Thread 2: read commands
// Thread 3: send telemetry
// Thread 4: guide navigation control
// Thread 5: Initialize

// SEMAPHORES
// Sensor data read
// Servo actuated

// Logs data to the serial monitor SAMPLE THREAD
void task_serial_logger(void *pvParameters) {
    while(1) {
        ESP_LOGI(TAG, "Task 1 is running on core %d", xPortGetCoreID());
        // Delay task execution for 1000ms (converted to FreeRTOS clock ticks)
        vTaskDelay(pdMS_TO_TICKS(1000)); 
    }
}

// Main application entry point in ESP-IDF
void app_main(void) {
    ESP_LOGI(TAG, "Starting FreeRTOS Tasks...");

    // Create Task 1 and pin it to Core 0
    xTaskCreatePinnedToCore(
        task_serial_logger,   // Function
        "Serial Logger",      // Description
        2048,                 // Stack size in bytes
        NULL,                 // Parameters
        1,                    // Priority
        NULL,                 // Task handle pointer
        0                     // Core ID (0/1)
    );
}