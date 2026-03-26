#pragma once

#include <memory>
using namespace std;

namespace polymath {
    /**
        * @class Polynomial
        * @brief A class representing a polynomial.
    */
    class Polynomial {
        public:
            /**
                * @brief Constructs a new Polynomial object.
                * @param inputArray Pointer to  array of unsigned ints representing coefficients.
                * @param maxExponent The highest degree of the polynomial (defines array size as maxExponent + 1).
                * @throw std::runtime_error If the provided maxExponent is inconsistent with input.
            */
            Polynomial(unsigned int* inputArray, size_t maxExponent);
            /**
                * @brief Destructor.
            */
            ~Polynomial();

            /**
                * @brief Accesses the coefficient for a specific exponent.
                * @param exponent The degree of the term to retrieve.
                * @return The coefficient at the given exponent, or 0 if the exponent exceeds max degree.
            */
            int operator[](int exponent);
            /**
                * @brief Returns a string representation of the polynomial.
                * @return String in the format "{ exp: coeff, ... }".
            */
            string toString();


            /** @name Arithmetic Assignment Operators */
            ///@{
            /** @brief Adds another polynomial to this one. */
            Polynomial& operator+=(const Polynomial& other);
            /** @brief Subtracts another polynomial from this one. */
            Polynomial& operator-=(const Polynomial& other);
            /** @brief Multiplies (currently performs assignment/copy in implementation) this polynomial. */
            Polynomial& operator*=(const Polynomial& other);
            ///@}

            /** @name Comparison Operators */
            ///@{
            /** @brief Checks if two polynomials are identical in degree and coefficients. */
            bool operator==(Polynomial& other);

            /** @brief Checks if two polynomials are different. */
            bool operator!=(Polynomial& other);

            /** @brief Compares degree, then coefficients from highest to lowest. */
            bool operator>(Polynomial& other);

            /** @brief Checks if this polynomial is less than another. */
            bool operator<(Polynomial& other);

            /** @brief Checks if this polynomial is greater than or equal to another. */
            bool operator>=(Polynomial& other);

            /** @brief Checks if this polynomial is less than or equal to another. */
            bool operator<=(Polynomial& other);

            ///@}

            /**
                * @brief Logical NOT cleans it's values.
                * @return Resets the cleared polynomial.
            */
            bool operator!();
            
            
        protected:
            class Impl;
            std::unique_ptr<Impl> pImpl; 
    };
}