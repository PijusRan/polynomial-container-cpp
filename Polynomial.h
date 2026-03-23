#pragma once

#include <vector>
#include <memory>
using namespace std;

namespace polymath {
    class Polynomial {
        public:
            Polynomial(vector<int>& expression);
            ~Polynomial();
            string toString();

            Polynomial& operator+=(const Polynomial& rhs);
            Polynomial& operator-=(const Polynomial& rhs);
            Polynomial& operator*=(const Polynomial& rhs);

            bool operator==(Polynomial& other);
            bool operator!=(Polynomial& other);
            bool operator>(Polynomial& other);
            bool operator<(Polynomial& other);
            bool operator>=(Polynomial& other);
            bool operator<=(Polynomial& other);

            bool operator!();
            
        protected:
            class Impl;
            std::unique_ptr<Impl> pImpl; 
    };
}