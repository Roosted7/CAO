#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers() {
    r[32] = {0};
    PC = 0;
}

void Registers::setRegister(int regNum, int value) {
    if (regNum == 0) return

    r[regnum] = value;
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
        cout << "register " << i << " contains: " << r[i];
    }
    cout << "PC contains: " << PC;

}