#ifndef _REGISTERS_H_
#define _REGISTERS_H_

class Registers {

    int r[32];
    int PC;
    
public:
    void setRegister (int regNum, int value);
    int getRegister (int regNum);
    void setPC (int value);
    int getPC ();
    void print ();
};

#endif	/* _REGISTERS_H_ */
