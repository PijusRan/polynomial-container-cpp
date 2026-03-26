#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace polymath;
using namespace std;

int main() {
    // 1. Data
    // polynomial 1: 5 + 2x + 1x^2
    unsigned int k1[] = {5, 2, 1}; 
    // polynomial 2: 1 + 3x^1
    unsigned int k2[] = {1, 3};    

    // 2. Creation
    Polynomial p1(k1, 2);
    Polynomial p2(k2, 1);

    cout << "--- Stage 1: Polynomials ---" << endl;
    cout << "P1: " << p1.toString() << endl;
    cout << "P2: " << p2.toString() << endl;

    // 3. Test Accessor (operator[])
    cout << "\n--- Stage 2: Accessing Coefficients ---" << endl;
    cout << "P1 coefficient of 1: " << p1[1] << endl;

    // 4. Arithmetics (+=, -=, *=)
    cout << "\n--- Arithmetic Operations ---" << endl;
    
    p1 += p2;
    cout << "P1 += P2: " << p1.toString() << endl;
    p1 -= p2;
    cout << "P1 -= P2 (same as in Stage 1): " << p1.toString() << endl;

    // 5. Test Comparison Operators
    cout << "\n--- Comparisons ---" << endl;
    cout << "P1 == P2? " << (p1 == p2) << endl;
    cout << "P1 != P2? " << (p1 != p2) << endl;
    cout << "P1 > P2?  " << (p1 > p2) << endl;
    cout << "P1 < P2?  " << (p1 < p2) << endl;
    cout << "P1 >= P2?  " << (p1 >= p2) << endl;
    cout << "P1 >= P2?  " << (p1 >= p2) << endl;
    
    // 6. Erasing polynomial
    if (!p1) {
        cout << "P1 cleared." << endl;
    }

    return 0;
}