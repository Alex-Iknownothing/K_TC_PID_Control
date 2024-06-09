/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: pid_control.hpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Implements PID control for temperature regulation and monitors system for safety conditions.
 * Inputs/Outputs:
 *   - Inputs: Current temperature
 *   - Outputs: Control signals to SSR and fan
 */

#ifndef PID_CONTROL_HPP
#define PID_CONTROL_HPP

#include "QuickPID.hpp"

// Function declarations
void setup_pid(QuickPID* myPID);
void run_pid_controller(QuickPID* myPID, float* Input, float* Output, float Setpoint);
void safety_check(float Input, float Setpoint);

#endif // PID_CONTROL_HPP
