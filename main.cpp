#include <iostream>
#include "computer.cpp"
#include "program.cpp"

using namespace std;


int main() {
    Computer c1 (1, 2, 2, 3, 4);
    Computer c2 (1.2, 2, 3, 4, 3);
    Computer c3 (2, 2, 2, 4, 6);
    
    Program p1 (2000, 100, 100, 50);
    Program p2 (2000, 0.1, 0.4, 0.25);
    Program p3 (500, 100, 2000, 200);
    
    c1.printStats();
    cout << "Global CPI: " << c1.calculateGlobalCPI() << "\n";

    p1.printStats();
    p2.printStats();


    return 0;
}
