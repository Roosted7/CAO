#include <iostream>
#include "computer.h"
#include "program.h"

using namespace std;

Program::Program(int _numArith, int _numStore, int _numLoad, int _numBranch) {
    numArith = _numArith;
    numStore = _numStore;
    numLoad = _numLoad;
    numBranch = _numBranch;
    numTotal = _numArith + _numStore + _numLoad + _numBranch;
}

Program::Program(int _numTotal, double percArith, double percStore, double percLoad) {
    numArith = _numTotal * percArith;
    numStore = _numTotal * percStore;
    numLoad = _numTotal * percLoad;
    numBranch = _numTotal * (1 - percArith - percStore - percLoad);
    numTotal = _numTotal;
}

void Program::printStats() {
    cout << "\nPROGRAM STATS:\n";
    cout << "Arithmetic calculations: " << numArith << "\n";
    cout << "Stored data: " << numStore << "\n";
    cout << "Loaded data: " << numLoad << "\n";
    cout << "Jumps: " << numBranch << "\n";
    cout << "Total number of instructions: " << numTotal << "\n";
}