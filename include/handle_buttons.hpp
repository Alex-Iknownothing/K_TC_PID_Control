/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: handle_buttons.hpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Header file for managing button inputs.
 * Inputs/Outputs:
 *   - Inputs: Button presses
 *   - Outputs: Changes in mode or settings
 */

#ifndef HANDLE_BUTTONS_HPP
#define HANDLE_BUTTONS_HPP

#include "driver/gpio.h"

// Button pins
#define BUTTON_UP    GPIO_NUM_2
#define BUTTON_DOWN  GPIO_NUM_3
#define BUTTON_LEFT  GPIO_NUM_4
#define BUTTON_RIGHT GPIO_NUM_5
#define BUTTON_SELECT GPIO_NUM_6

// Function declarations
void setup_buttons();
void handle_buttons();

#endif // HANDLE_BUTTONS_HPP
