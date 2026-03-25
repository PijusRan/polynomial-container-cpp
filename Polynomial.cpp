#include "Polynomial.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace polymath{
    class Polynomial::Impl{
        // --- LAUKAI ---
        private: 
            void resize(size_t newMaxExponent){
                valueArray = (unsigned int*) realloc(valueArray, (newMaxExponent+1) * sizeof(unsigned int));
                maxExponent = newMaxExponent;
            }

        protected:
            unsigned int* valueArray;
            size_t maxExponent;

        public:
            // --- CONSTRUCTORS ---
            Impl(unsigned int* inputArray, size_t maxExponent){
                if(sizeof(inputArray) < maxExponent+1){
                    throw runtime_error("size_t maxExponent is bigger than the size of array.");
                }
                this->valueArray = (unsigned int*) malloc((maxExponent + 1) * sizeof(unsigned int));
                if (this-> valueArray == nullptr) {
                    throw bad_alloc();
                }
                this->maxExponent = maxExponent;

               

                for(int i = maxExponent; i >= 0; i--){
                    valueArray[i] = inputArray[i];
                    if(i == maxExponent && valueArray[i] == 0) resize(i-1);
                }
            }

            // --- OPERATORS ---
            Impl& operator+=(Impl& other){
                if(other.maxExponent > maxExponent) resize(other.maxExponent);

                for(int i = maxExponent; i >= 0; i--){
                    valueArray[i] += other.valueArray[i];
                    if(i == maxExponent && valueArray[i] == 0) resize(i-1);
                }

                return *this;
            }
            Impl& operator-=(Impl& other){
                if(other.maxExponent > maxExponent) resize(other.maxExponent);

                for(int i = maxExponent; i >= 0; i--){
                    valueArray[i] -= other.valueArray[i];
                    if(i == maxExponent && valueArray[i] == 0) resize(i-1);
                }

                return *this;
            }
            Impl& operator*=(Impl& other){
                resize(other.maxExponent);

                for(int i = maxExponent; i >= 0; i--){
                    valueArray[i] = other.valueArray[i];
                    if(i == maxExponent && valueArray[i] == 0) resize(i-1);
                }

                return *this;
            }

            const bool operator==(const Impl& other){
                if(maxExponent != other.maxExponent) return false;

                for(int i = 0; i <= maxExponent; i++){
                    if(valueArray[i] != other.valueArray[i]) return false;
                }
                return true;
            }
            const bool operator!=(const Impl& other){
                if(!(*this == other)) return true;
                else return false;
            }
            const bool operator>(const Impl& other){
                if(maxExponent > other.maxExponent) return true;

                for(int i = maxExponent; i > 0; i--){
                    if(valueArray[i] > other.valueArray[i]) return true;
                    else if(valueArray[i] == other.valueArray[i]) continue;
                    else return false;
                }
                return false;
            }
            const bool operator<(const Impl& other){
                if(!(*this > other) && *this != other) return true;
                else return false;
            }
            const bool operator>=(const Impl& other){
                if((*this > other) || (*this == other)) return true;
                else return false;
            }
            const bool operator<=(const Impl& other){
                if((*this < other) || (*this == other)) return true;
                else return false;
            }

            // --- CLEANER ---
            bool operator!(){
                resize(0);
                return true;
            }

            // --- INDEXING ---
            const int operator[](const int exponent){
                if(exponent > maxExponent) return 0;
                return valueArray[exponent];
            }

            // --- toString ---
            string toString(){
                stringstream ss;

                // Reverse iteration on contains
                ss << "{ ";
                for(int i = 0; i < maxExponent; i++)  {
                    if(valueArray[i] != 0) ss << i << ": " << valueArray[i] << ", ";
                }
                ss << maxExponent << ": " << valueArray[maxExponent]  << " }\n";

                return ss.str();
            }
    };

    // pImpl declarations
    Polynomial::Polynomial(unsigned int* inputArray, size_t maxExponent) : pImpl(std::make_unique<Impl>(inputArray, maxExponent)) {}
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