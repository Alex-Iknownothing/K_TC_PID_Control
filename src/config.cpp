/*
 * Project: Multi-Use Workbench Hot Plate
 * File Name: config.cpp
 * Version: 1.0
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Description: Defines temperature profiles for soldering, coffee roasting, and tea brewing.
 * Inputs/Outputs:
 *   - Inputs: None
 *   - Outputs: Arrays and constants for temperature profiles
 */

#include "config.hpp"

// Solder profiles
ProfilePoint solderSn63Pb37[] = {
    {0, 25, 0}, {60, 150, 2.08}, {120, 183, 0.55}, {180, 220, 0.62}, {240, 220, 0}
};

ProfilePoint solderSn60Pb40[] = {
    {0, 25, 0}, {60, 140, 1.92}, {120, 183, 0.72}, {180, 215, 0.53}, {240, 215, 0}
};

ProfilePoint solderSn96_5Ag3_0Cu0_5[] = {
    {0, 25, 0}, {60, 170, 2.42}, {120, 217, 0.78}, {180, 245, 0.47}, {240, 245, 0}
};

ProfilePoint solderSn99_3Cu0_7[] = {
    {0, 25, 0}, {60, 160, 2.25}, {120, 227, 1.12}, {180, 240, 0.22}, {240, 240, 0}
};

ProfilePoint solderSn95Ag4Cu1[] = {
    {0, 25, 0}, {60, 180, 2.58}, {120, 221, 0.68}, {180, 240, 0.32}, {240, 240, 0}
};

ProfilePoint solderSn42Bi58[] = {
    {0, 25, 0}, {60, 100, 1.25}, {120, 138, 0.63}, {180, 180, 0.35}, {240, 180, 0}
};

// Coffee profiles
ProfilePoint lightRoastCoffee[] = {
    {0, 25, 0}, {60, 150, 2.08}, {120, 200, 0.83}, {180, 210, 0.17}, {240, 210, 0}
};

ProfilePoint mediumRoastCoffee[] = {
    {0, 25, 0}, {60, 150, 2.08}, {120, 210, 1.00}, {180, 220, 0.17}, {240, 220, 0}
};

ProfilePoint darkRoastCoffee[] = {
    {0, 25, 0}, {60, 150, 2.08}, {120, 220, 1.17}, {180, 230, 0.17}, {240, 230, 0}
};

// Tea profiles
ProfilePoint greenTea[] = {
    {0, 25, 0}, {60, 70, 0.75}, {120, 80, 0.17}, {180, 85, 0.08}, {240, 85, 0}
};

ProfilePoint blackTea[] = {
    {0, 25, 0}, {60, 100, 1.25}, {120, 95, -0.08}, {180, 90, -0.08}, {240, 90, 0}
};

ProfilePoint oolongTea[] = {
    {0, 25, 0}, {60, 85, 1.00}, {120, 90, 0.08}, {180, 95, 0.08}, {240, 95, 0}
};

ProfilePoint whiteTea[] = {
    {0, 25, 0}, {60, 70, 0.75}, {120, 75, 0.08}, {180, 80, 0.08}, {240, 80, 0}
};

ProfilePoint mintTea[] = {
    {0, 25, 0}, {60, 90, 1.08}, {120, 95, 0.08}, {180, 95, 0}, {240, 95, 0}
};

ProfilePoint spearmintTea[] = {
    {0, 25, 0}, {60, 80, 0.92}, {120, 85, 0.08}, {180, 85, 0}, {240, 85, 0}
};

ProfilePoint lemonTea[] = {
    {0, 25, 0}, {60, 90, 1.08}, {120, 95, 0.08}, {180, 95, 0}, {240, 95, 0}
};

ProfilePoint orangeBlossomTea[] = {
    {0, 25, 0}, {60, 85, 1.00}, {120, 90, 0.08}, {180, 90, 0}, {240, 90, 0}
};

ProfilePoint earlGreyTea[] = {
    {0, 25, 0}, {60, 95, 1.17}, {120, 100, 0.08}, {180, 100, 0}, {240, 100, 0}
};

// Array of profiles and their lengths
ProfilePoint* profiles[] = {
    solderSn63Pb37, solderSn60Pb40, solderSn96_5Ag3_0Cu0_5, solderSn99_3Cu0_7, solderSn95Ag4Cu1, solderSn42Bi58,
    lightRoastCoffee, mediumRoastCoffee, darkRoastCoffee,
    greenTea, blackTea, oolongTea, whiteTea,
    mintTea, spearmintTea, lemonTea, orangeBlossomTea, earlGreyTea
};

const int profileLengths[] = {
    sizeof(solderSn63Pb37) / sizeof(solderSn63Pb37[0]),
    sizeof(solderSn60Pb40) / sizeof(solderSn60Pb40[0]),
    sizeof(solderSn96_5Ag3_0Cu0_5) / sizeof(solderSn96_5Ag3_0Cu0_5[0]),
    sizeof(solderSn99_3Cu0_7) / sizeof(solderSn99_3Cu0_7[0]),
    sizeof(solderSn95Ag4Cu1) / sizeof(solderSn95Ag4Cu1[0]),
    sizeof(solderSn42Bi58) / sizeof(solderSn42Bi58[0]),
    sizeof(lightRoastCoffee) / sizeof(lightRoastCoffee[0]),
    sizeof(mediumRoastCoffee) / sizeof(mediumRoastCoffee[0]),
    sizeof(darkRoastCoffee) / sizeof(darkRoastCoffee[0]),
    sizeof(greenTea) / sizeof(greenTea[0]),
    sizeof(blackTea) / sizeof(blackTea[0]),
    sizeof(oolongTea) / sizeof(oolongTea[0]),
    sizeof(whiteTea) / sizeof(whiteTea[0]),
    sizeof(mintTea) / sizeof(mintTea[0]),
    sizeof(spearmintTea) / sizeof(spearmintTea[0]),
    sizeof(lemonTea) / sizeof(lemonTea[0]),
    sizeof(orangeBlossomTea) / sizeof(orangeBlossomTea[0]),
    sizeof(earlGreyTea) / sizeof(earlGreyTea[0])
};

const int numProfiles = sizeof(profiles) / sizeof(profiles[0]);
