/********************************************************
* Assignment 1: Performance analyzer                    *
* Author: Bart van Nobelen & Thomas Roos                *
* Purpose: to analyze the performance of                *
* different implementations of an instructruction set   *
* architecture running different programs.              *
*                                                       *
* Usage:                                                *
* Run the program and the message appears               *
********************************************************/

#include <iostream>
#include "computer.cpp"
#include "program.cpp"

using namespace std;

// Main function to print stats
int main() {

    // Create Computer objects
    Computer c1 (1, 2, 2, 3, 4);
    Computer c2 (1.2, 2, 3, 4, 3);
    Computer c3 (2, 2, 2, 4, 6);
    
    // Create Program objects
    Program p1 (2000, 100, 100, 50);
    Program p2 (2000, 0.1, 0.4, 0.25);
    Program p3 (500, 100, 2000, 200);
    
    // Create arrays to loop over
    Computer c_arr[3] = {c1, c2, c3};
    Program p_arr[3] = {p1, p2, p3};

    for (int i = 0; i < 3; i++) {
        // Print program stats
        cout << "\n### Statistics for program " << i << ": ###\n";
        p_arr[i].printStats();
    }
    
    for (int i = 0; i < 3; i++) {
        // Print Computer stats
        cout << "\n### COMPUTER STATS " << i << ": ###\n";
        c_arr[i].printStats();
        cout << "Global CPI: " << c_arr[i].calculateGlobalCPI() << "\n";
        // Print global MIPS without knowledge of program
        cout << "MIPS: " << c_arr[i].calculateMIPS() << "\n";

        for (int j = 0; j < 3; j++) {
            cout << " - for program " << j << ":\n";

            // Print execTime
            cout << "Execution time: " << c_arr[i].calculateExecutionTime(p_arr[j]) << "\n";
        
            // Print MIPS for specific program
            cout << "Program specific MIPS: " << c_arr[i].calculateMIPS(p_arr[j]) << "\n";
        }
    }

    
    return 0;
}
