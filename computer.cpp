#include <iostream>
#include "computer.h"
#include "program.h"

using namespace std;

Computer::Computer(double _clockRateGHz, double _cpiArith, double _cpiStore, double _cpiLoad, double _cpiBranch) {
    clockRateGHz = _clockRateGHz;
    cpiArith = _cpiArith;
    cpiStore = _cpiStore;
    cpiLoad = _cpiLoad;
    cpiBranch = _cpiBranch;
}

void Computer::printStats() {
    cout << "\nCOMPUTER STATS:\n";
    cout << "Clock rate (GHz): " << clockRateGHz << "\n";
    cout << "CPI Arith: " << cpiArith << "\n";
    cout << "CPI Store: " << cpiStore << "\n";
    cout << "CPI Load: " << cpiLoad << "\n";
    cout << "CPI Branch: " << cpiBranch << "\n";
}

double Computer::calculateGlobalCPI () {
    return cpiArith + cpiStore + cpiLoad + cpiBranch;
}