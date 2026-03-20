#include "Polynomial.h"

#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

namespace math_polynomial{
    class Polynomial::Impl{
        // --- LAUKAI ---
        private:
            set<int> contains;
            map<int, int> multipliers;

        public:
            // --- KONSTRUKTORIUS ---
            

            // --- toString ---
            string toString(){
                return "String";
            }
    };
    Polynomial::Polynomial() : pImpl(std::make_unique<Impl>()) {}
    Polynomial::~Polynomial() = default; 

    string Polynomial::toString(){
        pImpl->toString(); 
    }
}

/*
Impl(vector<int>& expression){
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] != 0){
            contains.insert(i);
            multipliers[i] = expression[i];
        }
    }
}
*/