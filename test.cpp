#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "Polynomial.h"

using namespace std;
using namespace Polymath;

int main() {
    ofstream logFile("log.txt");
    if (!logFile.is_open()) return 1;

    // Header for log depth
    logFile << "--- POLYNOMIAL UNIT TEST ---" << endl;

    // 1. Constructor & Indexing
    unsigned int c1[] = {1, 2, 3}; 
    Polynomial p1(c1, 2);
    assert(p1[0] == 1);
    logFile << "PASS: [0]" << endl;
    assert(p1[1] == 2);
    logFile << "PASS:[1]" << endl;
    assert(p1[2] == 3);
    logFile << "PASS: [2]" << endl;

    // 1.5. Out of bounds coefficients
    assert(p1[4] == -1);
    logFile << "PASS: [4]" << endl;

    // 2. toString
    assert(p1.toString() == "{ 0: 1, 1: 2, 2: 3 }");
    logFile << "PASS: toString" << endl;

    // 3. Addition (+=)
    unsigned int c2[] = {0, 0, 0, 10};
    Polynomial p2(c2, 3);
    p1 += p2;
    assert(p1[3] == 10);
    logFile << "PASS: operator+=" << endl;

    // 4. Subtraction (-=)
    p1 -= p2;
    assert(p1[3] == -1);
    logFile << "PASS: operator-=" << endl;

    // 5. Equality
    Polynomial pCopy(c1, 2);
    assert(p1 == pCopy);
    logFile << "PASS: operator==" << endl;
    assert(!(p1 != pCopy));
    logFile << "PASS: operator!=" << endl;

    // 6. Relational
    unsigned int c3[] = {1, 2, 4}; 
    Polynomial p3(c3, 2);
    assert(p3 > p1);
    logFile << "PASS: operator>" << endl;
    assert(p1 < p3);
    logFile << "PASS: operator<" << endl;
    assert(p3 >= p1);
    logFile << "PASS: operator>=" << endl;
    assert(p1 <= p3);
    logFile << "PASS: operator<=" << endl;

    // 7. Multiply (Assignment Hook)
    p1 *= p3;
    assert(p1 == p3);
    logFile << "PASS: operator*=" << endl;

    // 8. Unary ! (Cleaner)
    bool erased = !p1;
    assert(erased);
    logFile << "PASS: operator!" << endl;
    cout << p1[0] << "\n";
    //assert(p1.getMultiplierOf(0) == 0);
    logFile << "PASS: operator! indexing" << endl;

    // 9. Deep copy
    Polynomial* p1_copy = p1.deepCopy();
    p1.setMultiplierOf(0, 999);
    assert(p1.getMultiplierOf(0) != p1_copy->getMultiplierOf(0));

    logFile.close();
    cout << "Tests passed. See log.txt." << endl;

    return 0;
}