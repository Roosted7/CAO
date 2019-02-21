#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

// Creating the Class for program
class Program {
    int numArith;        // Arithmetic and logic calculations
    int numStore;        // Store data into memory
    int numLoad;         // Load data from memory
    int numBranch;       // Conditional and unconditional jumps
    int numTotal;        // Total number of instructions
public:
    Program(int, int, int, int);
    Program(int, double, double, double);

    int get_Arith();
    int get_Store();
    int get_Load();
    int get_Branch();
    int get_Total() ;
    
    void printStats();
};

#endif // PROGRAM_H_INCLUDED
