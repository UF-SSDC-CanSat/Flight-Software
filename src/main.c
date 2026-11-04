#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include <esp_log.h>

static const char *TAG = "RTOS";

// SEMAPHORES
SemaphoreHandle_t readSensorSmphr; // Sensor data read
SemaphoreHandle_t servoActuatedSmphr; // Servo actuated


void StartReadSensors(void *parameter) { // start reading sensors

    while (1) {
        // Read data

        // activate read sensor semaphore
        xSemaphoreGive(readSensorSmphr);

        vTaskDelay(pdMS_TO_TICKS(100));
    }

}

void StartReadCommands(void *parameter) { // start reading commands
    
    while (1) {
        // command process

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void StartSendTelemetry(void *parameter) { // start sending telemetry data
    while (1) {
        // send telemetry

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void StartGuideNavigationControl(void *parameter) { // start guide navigation control system
     while (1) {
        // start GNC system

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void StartInitSeq(void *parameter) { // start initialization
}

// Main application entry point in ESP-IDF
void app_main(void) {
    ESP_LOGI(TAG, "Initializing FreeRTOS Semaphores...");
    readSensorSmphr = xSemaphoreCreateBinary();
    servoActuatedSmphr = xSemaphoreCreateBinary();

    ESP_LOGI(TAG, "Starting FreeRTOS Tasks...");

    xTaskCreatePinnedToCore(
        StartReadCommands,   // Function
        "Read Commands",      // Description
        2048,                 // Stack size in bytes
        NULL,                 // Parameters
        3,                    // Priority
        NULL,                 // Task handle pointer
        0                     // Core #
    );

    xTaskCreatePinnedToCore(
        StartSendTelemetry,   // Function
        "Telemetry Data Send",      // Description
        2048,                 // Stack size in bytes
        NULL,                 // Parameters
        2,                    // Priority
        NULL,                 // Task handle pointer
        0                     // Core ID (0/1)
    );

    xTaskCreatePinnedToCore(
        StartInitSeq,   // Function
        "Initializes",      // Description
        2048,                 // Stack size in bytes
        NULL,                 // Parameters
        1,                    // Priority
        NULL,                 // Task handle pointer
        0                     // Core ID (0/1)
    );

    xTaskCreatePinnedToCore(
        StartGuideNavigationControl,   // Function
        "Guide Navigation Control System",      // Description
        2048,                 // Stack size in bytes
        NULL,                 // Parameters
        5,                    // Priority
        NULL,                 // Task handle pointer
        1                     // Core #
    );

    xTaskCreatePinnedToCore(
        StartReadSensors,   // Function
        "Sensor Read",      // Description
        2048,                 // Stack size in bytes
        NULL,                 // Parameters
        4,                    // Priority
        NULL,                 // Task handle pointer
        1                     // Core ID (0/1)
    );
}