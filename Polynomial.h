#pragma once

#include <vector>
#include <memory>
using namespace std;

namespace math_polynomial {
    class Polynomial {
        public:
            Polynomial();
            ~Polynomial();
            string toString();
            
        private:
            class Impl;
            std::unique_ptr<Impl> pImpl; 
    };
}