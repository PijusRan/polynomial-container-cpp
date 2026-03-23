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

            bool operator==(Impl& other){
                if(contains == other.contains && multipliers == other.multipliers){
                    return true;
                }
                else{
                    return false;
                }
            }
            bool operator!=(Impl& other){
                if(!(*this == other)){
                    return true;
                }
                else{
                    return false;
                }
            }
            bool operator>(Impl& other){
                auto e_it1 = contains.rbegin();
                auto e_it2 = other.contains.rbegin();

                if(*this != other){
                    while(e_it1 != contains.rend() && e_it2 != contains.rend()){
                        if(*e_it1 > *e_it2){
                            return true;
                        }
                        else if(*e_it1 == *e_it2){
                            if(multipliers[*e_it1] > multipliers[*e_it2]) return true;
                            else if(multipliers[*e_it1] > multipliers[*e_it2]) continue;
                            else return false;
                        }
                        else{
                            return false;
                        }
                    }
                    return true;
                }
                else return false;
            }
            bool operator<(Impl& other){
                if(!(*this > other) && *this != other) return true;
                else return false;
            }
            bool operator>=(Impl& other){
                if((*this > other) || (*this == other)) return true;
                else return false;
            }
            bool operator<=(Impl& other){
                if((*this < other) || (*this == other)) return true;
                else return false;
            }

            // --- CLEANER ---
            bool operator!(){
                contains.clear();
                multipliers.clear();
                return true;
            }

            // --- INDEXING ---
            int operator[](int exponent){
                return multipliers[exponent];
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

    Polynomial& Polynomial::operator+=(const Polynomial& other) {
        *(this->pImpl) += *(other.pImpl); 
        return *this;
    }
    Polynomial& Polynomial::operator-=(const Polynomial& other) {
        *(this->pImpl) -= *(other.pImpl);
        return *this;
    }
    Polynomial& Polynomial::operator*=(const Polynomial& other) {
        *(this->pImpl) *= *(other.pImpl);
        return *this;
    }

    bool Polynomial::operator==(Polynomial& other){
        return *(this->pImpl) == *(other.pImpl);
    }
    bool Polynomial::operator!=(Polynomial& other){
        return *(this->pImpl) != *(other.pImpl);
    }
    bool Polynomial::operator>(Polynomial& other){
        return *(this->pImpl) > *(other.pImpl);
    }
    bool Polynomial::operator<(Polynomial& other){
        return *(this->pImpl) < *(other.pImpl);
    }
    bool Polynomial::operator>=(Polynomial& other){
        return *(this->pImpl) >= *(other.pImpl);
    }
    bool Polynomial::operator<=(Polynomial& other){
        return *(this->pImpl) <= *(other.pImpl);
    }
    
    bool Polynomial::operator!(){
        return !(*(this->pImpl));
    }
    int Polynomial::operator[](int exponent){
        return (*(this->pImpl))[exponent];
    }

    string Polynomial::toString(){
        return pImpl->toString(); 
    }
}