#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

class Instruction {
protected:
    int r1, r2, r3;

public:
    Instruction(int _r1, int _r2, int _r3);
    virtual ~Instruction() {};

    virtual void disassemble() = 0;
    virtual int execute (Registers *) = 0;
};

class AddInstruction: public Instruction {
    using Instruction::Instruction;
public:
    void disassemble();
    int execute(Registers *);
};

class SubInstruction: public Instruction {
    using Instruction::Instruction;
public:
    void disassemble();
    int execute(Registers *);
};

class OriInstruction: public Instruction {
    using Instruction::Instruction;
public:
    void disassemble();
    int execute(Registers *);
};

class BrneInstruction: public Instruction {
    using Instruction::Instruction;
public:
    void disassemble();
    int execute(Registers *);
};

#endif /* _INSTRUCTION_H_ */
