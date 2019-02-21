#include <iostream>
#include "computer.h"
#include "program.h"

using namespace std;

// Constructor for the computer
Computer::Computer(double _clockRateGHz, double _cpiArith, double _cpiStore, double _cpiLoad, double _cpiBranch) {
    clockRateGHz = _clockRateGHz;
    cpiArith = _cpiArith;
    cpiStore = _cpiStore;
    cpiLoad = _cpiLoad;
    cpiBranch = _cpiBranch;
}

// Print the basic properties of the computer
void Computer::printStats() {
    cout << "Clock rate (GHz): " << clockRateGHz << "\n";
    cout << "CPI Arith: " << cpiArith << "\n";
    cout << "CPI Store: " << cpiStore << "\n";
    cout << "CPI Load: " << cpiLoad << "\n";
    cout << "CPI Branch: " << cpiBranch << "\n";
}

// Calculating global CPI (sum)
double Computer::calculateGlobalCPI () {
    return (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4;
}

// Calculate total exec time in second for specific program
double Computer::calculateExecutionTime (Program p) {
    double cycles = 0;

    cycles += p.get_Arith() * cpiArith;
    cycles += p.get_Store() * cpiStore;
    cycles += p.get_Load() * cpiLoad;
    cycles += p.get_Branch() * cpiBranch;

    return cycles / (clockRateGHz * 1e9);
}

// Calculate global MIPS without knowledge of program
double Computer::calculateMIPS () {
    return (clockRateGHz * 1e3) / calculateGlobalCPI();
}

// Calculate MIPS for specific program
double Computer::calculateMIPS (Program p) {
    return p.get_Total()/(calculateExecutionTime(p)*1e6);
}