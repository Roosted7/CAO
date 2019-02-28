#include <iostream>
#include "instruction.h"

using namespace std;

Instruction::Instruction(int _r1, int _r2, int _r3) {
    r1 = _r1;
    r2 = _r2;
    r3 = _r3;
};

int AddInstruction::execute(Registers *reg) {
    reg->setRegister(r1, reg->getRegister(r2) + reg->getRegister(r3));
    return reg->getPC() + 1;
};
void AddInstruction::disassemble() {
    cout << "add $" << r1 << ", $" << r2 << ", $" << r3 << "\n";
};

int SubInstruction::execute(Registers *reg) {
    reg->setRegister(r1, reg->getRegister(r2) - reg->getRegister(r3));
    return reg->getPC() + 1;
};
void SubInstruction::disassemble() {
    cout << "sub $" << r1 << ", $" << r2 << ", $" << r3 << "\n";
};

int OriInstruction::execute(Registers *reg) {
    reg->setRegister(r1, reg->getRegister(r2) | r3);
    return reg->getPC() + 1;
};
void OriInstruction::disassemble() {
    cout << "ori $" << r1 << ", $" << r2 << ", " << r3 << "\n";
};

int BrneInstruction::execute(Registers *reg) {
    if (reg->getRegister(r1) != reg->getRegister(r2))
        return reg->getPC() + 1 + r3;
    else 
        return reg->getPC() + 1;
};
void BrneInstruction::disassemble() {
    cout << "brne $" << r1 << ", $" << r2 << ", " << r3 << "\n";
};