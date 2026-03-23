#include "Polynomial.h"

#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

namespace polymath{
    class Polynomial::Impl{
        // --- LAUKAI ---
        protected:
            set<int> contains;
            map<int, int> multipliers;

        public:
            // --- CONSTRUCTORS ---
            Impl(vector<int>& expression){
                for(int i = 0; i < expression.size(); i++){
                    if(expression[i] != 0){
                        contains.insert(i);
                        multipliers[i] = expression[i];
                    }
                }
            }

            // --- OPERATORS ---
            Impl& operator+=(Impl& other){
                for(int e : other.contains){
                    contains.insert(e);
                    multipliers[e] += other.multipliers[e];
                }
                return *this;
            }
            Impl& operator-=(Impl& other){
                for(int e : other.contains){
                    contains.insert(e);
                    multipliers[e] -= other.multipliers[e];
                    if(multipliers[e] == 0) contains.erase(e);
                }
                return *this;
            }
            Impl& operator*=(Impl& other){
                contains.clear();
                for(int e : other.contains){
                    contains.insert(e);
                    multipliers[e] = other.multipliers[e];
                }
                return *this;
            }

            // --- toString ---
            string toString(){
                stringstream ss;

                // Reverse iteration on contains
                set<int>::reverse_iterator rit; 
                for (rit = contains.rbegin(); rit != contains.rend(); rit++)  {
                    if(*rit != 0){
                        if(next(rit) != contains.rend()){
                            ss << multipliers[*rit] << "x^" << *rit << " + ";
                        }
                        else{
                            ss << multipliers[*rit] << "x^" << *rit << "\n";
                        }
                    }
                    else{
                        ss << multipliers[*rit] << "\n";
                    }
                }

                return ss.str();
            }
    };

    // pImpl declarations
    Polynomial::Polynomial(std::vector<int>& expression) : pImpl(std::make_unique<Impl>(expression)) {}
    Polynomial::~Polynomial() = default; 

    Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
        *(this->pImpl) += *(rhs.pImpl); 
        return *this;
    }
    Polynomial& Polynomial::operator-=(const Polynomial& rhs) {
        *(this->pImpl) -= *(rhs.pImpl);
        return *this;
    }
    Polynomial& Polynomial::operator*=(const Polynomial& rhs) {
        *(this->pImpl) *= *(rhs.pImpl);
        return *this;
    }

    string Polynomial::toString(){
        return pImpl->toString(); 
    }
}