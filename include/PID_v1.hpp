/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: PID_v1.hpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: PID Library - Version 1.2.1
 * A simple implementation of a PID control algorithm.
 * Provides functions for setting tuning parameters, computing the PID output,
 * and configuring the controller mode, output limits, and sample time.
 * Inputs/Outputs:
 *   - Inputs: Setpoint, current temperature
 *   - Outputs: PID control output
 */

#ifndef PID_V1_HPP
#define PID_V1_HPP

#define LIBRARY_VERSION 1.2.1

class PID {
  public:
    // Constants used in some of the functions below
    #define AUTOMATIC 1
    #define MANUAL    0
    #define DIRECT    0
    #define REVERSE   1
    #define P_ON_M    0
    #define P_ON_E    1

    // Constructor
    PID(double*, double*, double*, double, double, double, int);

    // Function to set the mode to manual or automatic
    void SetMode(int Mode);

    // Function to compute the PID output
    bool Compute();

    // Function to set output limits
    void SetOutputLimits(double, double);

    // Functions to set tuning parameters
    void SetTunings(double, double, double);
    void SetTunings(double, double, double, int);

    // Function to set controller direction
    void SetControllerDirection(int);

    // Function to set sample time
    void SetSampleTime(int);

    // Functions to get tuning parameters and mode
    double GetKp();
    double GetKi();
    double GetKd();
    int GetMode();
    int GetDirection();

  private:
    void Initialize();

    double dispKp;  // Displayed Kp
    double dispKi;  // Displayed Ki
    double dispKd;  // Displayed Kd

    double kp;  // Proportional Tuning Parameter
    double ki;  // Integral Tuning Parameter
    double kd;  // Derivative Tuning Parameter

    int controllerDirection;
    int pOn;

    double *myInput;   // Pointers to the Input, Output, and Setpoint variables
    double *myOutput;
    double *mySetpoint;

    unsigned long lastTime;
    double outputSum, lastInput;

    unsigned long SampleTime;
    double outMin, outMax;
    bool inAuto, pOnE;
};

#endif // PID_V1_HPP
