/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: display_manager.hpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Header file for OLED display operations.
 * Inputs/Outputs:
 *   - Inputs: Current mode, temperature readings
 *   - Outputs: Visual feedback on OLED display
 */

#ifndef DISPLAY_MANAGER_HPP
#define DISPLAY_MANAGER_HPP

#include "ssd1306.h"

// Function declarations
void update_display(ssd1306_t *dev, float Input, float Setpoint, int currentMode, int stageRemainingTime);

#endif // DISPLAY_MANAGER_HPP
