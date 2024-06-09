/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: handle_buttons.cpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Manages button inputs for navigating menus and changing settings.
 * Inputs/Outputs:
 *   - Inputs: Button presses
 *   - Outputs: Changes in mode or settings
 */

#include "handle_buttons.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "buttons";

void setup_buttons() {
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << BUTTON_UP) | (1ULL << BUTTON_DOWN) | (1ULL << BUTTON_LEFT) | (1ULL << BUTTON_RIGHT) | (1ULL << BUTTON_SELECT);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);
}

void handle_buttons() {
    if (gpio_get_level(BUTTON_UP) == 0) {
        ESP_LOGI(TAG, "Button UP pressed");
    }
    if (gpio_get_level(BUTTON_DOWN) == 0) {
        ESP_LOGI(TAG, "Button DOWN pressed");
    }
    if (gpio_get_level(BUTTON_LEFT) == 0) {
        ESP_LOGI(TAG, "Button LEFT pressed");
    }
    if (gpio_get_level(BUTTON_RIGHT) == 0) {
        ESP_LOGI(TAG, "Button RIGHT pressed");
    }
    if (gpio_get_level(BUTTON_SELECT) == 0) {
        ESP_LOGI(TAG, "Button SELECT pressed");
    }
}
