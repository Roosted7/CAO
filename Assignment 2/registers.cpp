#include <iostream>
#include "registers.h"

using namespace std;

void Registers::setRegister(int regNum, int value) {
    if (regNum != 0)
        r[regNum] = value;
}

int Registers::getRegister(int regNum) {
    return r[regNum];
}

void Registers::setPC(int value) {
    PC = value;
}

int Registers::getPC() {
    return PC;
}

void Registers::print() {
    for (int i = 0; i < 32; i++) {
        cout << "register " << i << " contains: " << r[i] << "\n";
    }
    cout << "PC contains: " << PC << "\n\n";

}