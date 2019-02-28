#ifndef _REGISTERS_H_
#define _REGISTERS_H_

class Registers {

    int r[32] = {0};
    int PC = {0};
    
public:

    void setRegister (int regNum, int value);
    int getRegister (int regNum);
    void setPC (int value);
    int getPC ();
    void print ();
};

#endif	/* _REGISTERS_H_ */
