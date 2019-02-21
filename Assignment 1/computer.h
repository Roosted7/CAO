#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

#include "program.h"

// Creating the Class for computer
class Computer {
    double clockRateGHz;     // Clock rate in GHz
    double cpiArith;         // CPI of instruction class Arith
    double cpiStore;         // CPI of instruction class Store
    double cpiLoad;          // CPI of instruction class Load
    double cpiBranch;        // CPI of instruction class Branch
public:
    Computer (double, double, double, double, double);
    void printStats ();
    double calculateGlobalCPI ();
    double calculateExecutionTime (Program);
    double calculateMIPS ();
    double calculateMIPS (Program);
};

#endif // COMPUTER_H_INCLUDED
