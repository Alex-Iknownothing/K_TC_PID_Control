/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: display_manager.cpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Implements OLED display operations for system status, menu, and graphical representation of temperature profiles.
 * Inputs/Outputs:
 *   - Inputs: Current mode, temperature readings
 *   - Outputs: Visual feedback on OLED display
 */

#include "display_manager.hpp"
#include "ssd1306.h"

void update_display(ssd1306_t *dev, float Input, float Setpoint, int currentMode, int stageRemainingTime) {
    ssd1306_clear_screen(dev);
    char buffer[64];

    snprintf(buffer, sizeof(buffer), "Mode: %d", currentMode);
    ssd1306_display_text(dev, 0, buffer, strlen(buffer), false);

    snprintf(buffer, sizeof(buffer), "Temp: %.2f C", Input);
    ssd1306_display_text(dev, 1, buffer, strlen(buffer), false);

    snprintf(buffer, sizeof(buffer), "Set: %.2f C", Setpoint);
    ssd1306_display_text(dev, 2, buffer, strlen(buffer), false);

    snprintf(buffer, sizeof(buffer), "Time: %d s", stageRemainingTime);
    ssd1306_display_text(dev, 3, buffer, strlen(buffer), false);

    ssd1306_refresh_gram(dev);
}
