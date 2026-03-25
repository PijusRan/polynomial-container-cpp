#include "Polynomial.h"

#include <iostream>
using namespace std;

int main(){
    unsigned int in1[] = {1, 2, 3};
    polymath::Polynomial pol1 = polymath::Polynomial(in1, 2);

    unsigned int in2[] = {4, 5, 6};
    polymath::Polynomial pol2 = polymath::Polynomial(in2, 2);

    // Turime pol1
    cout << pol1.toString() << "\n";

    // Pridedame pol2
    pol1 += pol2;
    cout << pol1.toString() << "\n";
    
    // Atimame pol2 (tas pats kas pol1)
    pol1 -= pol2;
    cout << pol1.toString() << "\n";

    // pol1 tampa pol2
    pol1 *= pol2;
    cout << pol1.toString() << "\n";
}