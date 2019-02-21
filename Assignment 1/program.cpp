#include <iostream>
#include "computer.h"
#include "program.h"

using namespace std;

// Constructor for program
Program::Program(int _numArith, int _numStore, int _numLoad, int _numBranch) {
    numArith = _numArith;
    numStore = _numStore;
    numLoad = _numLoad;
    numBranch = _numBranch;
    numTotal = _numArith + _numStore + _numLoad + _numBranch;
}

// Overloaded constructor for program
Program::Program(int _numTotal, double percArith, double percStore, double percLoad) {
    numArith = _numTotal * percArith;
    numStore = _numTotal * percStore;
    numLoad = _numTotal * percLoad;
    numBranch = _numTotal * (1 - percArith - percStore - percLoad);
    numTotal = _numTotal;
}

// Getters
int Program::get_Arith()    { return numArith; }
int Program::get_Store()    { return numStore; }
int Program::get_Load()     { return numLoad; }
int Program::get_Branch()   { return numBranch; }
int Program::get_Total()    { return numTotal; }

// Defining the program stats to be printed
void Program::printStats() {
    cout << "Arithmetic calculations: " << numArith << "\n";
    cout << "Stored data: " << numStore << "\n";
    cout << "Loaded data: " << numLoad << "\n";
    cout << "Jumps: " << numBranch << "\n";
    cout << "Total number of instructions: " << numTotal << "\n";
}