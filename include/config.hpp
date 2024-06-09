/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: config.hpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Configuration settings, mode definitions, pin assignments, and detailed temperature profiles.
 * Inputs/Outputs:
 *   - Inputs: None
 *   - Outputs: Temperature profiles and configuration settings
 */

#ifndef CONFIG_HPP
#define CONFIG_HPP

typedef struct {
    unsigned long duration;  // Duration at this setpoint in seconds
    float temperature;       // Target temperature in Celsius
    float rateOfChange;      // Rate of change in °C/s to reach this point
} ProfilePoint;

// Solder profiles
extern ProfilePoint solderSn63Pb37[];
extern ProfilePoint solderSn60Pb40[];
extern ProfilePoint solderSn96_5Ag3_0Cu0_5[];
extern ProfilePoint solderSn99_3Cu0_7[];
extern ProfilePoint solderSn95Ag4Cu1[];
extern ProfilePoint solderSn42Bi58[];

// Coffee profiles
extern ProfilePoint lightRoastCoffee[];
extern ProfilePoint mediumRoastCoffee[];
extern ProfilePoint darkRoastCoffee[];

// Tea profiles
extern ProfilePoint greenTea[];
extern ProfilePoint blackTea[];
extern ProfilePoint oolongTea[];
extern ProfilePoint whiteTea[];
extern ProfilePoint mintTea[];
extern ProfilePoint spearmintTea[];
extern ProfilePoint lemonTea[];
extern ProfilePoint orangeBlossomTea[];
extern ProfilePoint earlGreyTea[];

// Array of profiles and their lengths
extern ProfilePoint* profiles[];
extern const int profileLengths[];
extern const int numProfiles;

#endif // CONFIG_HPP
