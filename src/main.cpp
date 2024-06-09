/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: main.cpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Main application file for PID temperature control using ESP-IDF.
 * Uses a MAX6675 thermocouple, an SSD1306 OLED display, and PID control to manage
 * the temperature profiles for soldering, coffee roasting, and tea brewing.
 * Includes custom auto-tuning for optimal PID parameters and smooth setpoint ramping.
 * Inputs/Outputs:
 *   - Inputs: Button states, temperature readings
 *   - Outputs: PID control output, OLED display updates
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/ledc.h"
#include "driver/spi_master.h"
#include "driver/i2c.h"
#include "esp_task_wdt.h"
#include "driver/rtc_io.h"
#include "soc/timer_group_struct.h"
#include "soc/timer_group_reg.h"
#include "soc/rtc_wdt.h"
#include "display_manager.hpp"
#include "handle_buttons.hpp"
#include "config.hpp"
#include "pid_control.hpp"
#include "ssd1306.h"
#include "QuickPID.h"

#define I2C_MASTER_SCL_IO           22
#define I2C_MASTER_SDA_IO           21
#define I2C_MASTER_NUM              I2C_NUM_0
#define I2C_MASTER_FREQ_HZ          100000

#define OLED_ADDR                   0x3C
#define OLED_WIDTH                  128
#define OLED_HEIGHT                 64

#define MAX6675_CS                  5
#define MAX6675_DO                  19
#define MAX6675_CLK                 18

#define OUTPUT_PIN                  25
#define FAN_PIN                     26
#define AIR_PUMP_PIN                27

static const char *TAG = "main";

ssd1306_t dev;
float Setpoint, Input, Output;
QuickPID myPID(&Input, &Output, &Setpoint, 1.0, 0.5, 0.1, QuickPID::Action::direct);

void disableWatchdog() {
    // Disable Task Watchdog Timer (TWDT) for both cores
    esp_task_wdt_init(10, false);
    esp_task_wdt_delete(NULL);

    // Disable Interrupt Watchdog Timer (IWDT) for Timer Group 0 and Timer Group 1
    TIMERG0.wdt_wprotect = TIMG_WDT_WKEY_VALUE;
    TIMERG0.wdt_feed = 1;
    TIMERG0.wdt_config0.en = 0;
    TIMERG0.wdt_wprotect = 0;

    TIMERG1.wdt_wprotect = TIMG_WDT_WKEY_VALUE;
    TIMERG1.wdt_feed = 1;
    TIMERG1.wdt_config0.en = 0;
    TIMERG1.wdt_wprotect = 0;

    // Disable RTC Watchdog Timer
    rtc_wdt_disable();
}

void init_oled() {
    i2c_config_t i2c_config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ
    };
    i2c_param_config(I2C_MASTER_NUM, &i2c_config);
    i2c_driver_install(I2C_MASTER_NUM, i2c_config.mode, 0, 0, 0);

    ssd1306_init(&dev, I2C_MASTER_NUM, OLED_ADDR, OLED_WIDTH, OLED_HEIGHT);
    ssd1306_clear_screen(&dev);
    ssd1306_display_text(&dev, 0, "Initializing...", 14, false);
}

extern "C" void app_main(void) {
    ESP_LOGI(TAG, "Setup started");

    // Disable watchdog timers
    disableWatchdog();
    ESP_LOGI(TAG, "Watchdog timers disabled");

    // Initialize OLED display
    init_oled();
    ESP_LOGI(TAG, "OLED initialized");

    // Initialize buttons
    setup_buttons();
    ESP_LOGI(TAG, "Buttons initialized");

    // Initialize PID
    setup_pid(&myPID);
    ESP_LOGI(TAG, "PID initialized");

    // Initialize PWM
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT,
        .freq_hz = 5000,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);
    ledc_channel_config_t ledc_channel = {
        .channel = LEDC_CHANNEL_0,
        .duty = 0,
        .gpio_num = OUTPUT_PIN,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .hpoint = 0,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);
    ESP_LOGI(TAG, "PWM initialized");

    ssd1306_clear_screen(&dev);
    ssd1306_display_text(&dev, 0, "Setup Complete", 14, false);

    while (true) {
        handle_buttons();
        run_pid_controller(&myPID, &Input, &Output, Setpoint);
        update_display(&dev, Input, Setpoint, current_mode, stage_remaining_time);
        safety_check(Input, Setpoint);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
