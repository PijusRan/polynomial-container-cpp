#pragma once

#include <memory>
using namespace std;

namespace polymath {
    class Polynomial {
        public:
            Polynomial(unsigned int* inputArray, size_t maxExponent);
            ~Polynomial();
            string toString();

            Polynomial& operator+=(const Polynomial& other);
            Polynomial& operator-=(const Polynomial& other);
            Polynomial& operator*=(const Polynomial& other);

            bool operator==(Polynomial& other);
            bool operator!=(Polynomial& other);
            bool operator>(Polynomial& other);
            bool operator<(Polynomial& other);
            bool operator>=(Polynomial& other);
            bool operator<=(Polynomial& other);

            bool operator!();
            int operator[](int exponent);
            
        protected:
            class Impl;
            std::unique_ptr<Impl> pImpl; 
    };
}