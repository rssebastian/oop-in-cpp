#pragma once

#include <string>
#include "RationalNumber.h"

class RationalNumber
{

private:
    // INSTANCE VARIABLES
    int numerator;
    int denominator;

    // HELPER METHODS
    void reduce()
    {
        int reduceBy = gcd(numerator, denominator);
        numerator /= reduceBy;
        denominator /= reduceBy;
    }

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    // CONSTRUCTORS
    RationalNumber()
    {
        numerator = 0;
        denominator = 1;
    }

    RationalNumber(int num)
    {
        numerator = num;
        denominator = 1;
    }

    RationalNumber(int numer, int denom)
    {
        this->numerator = numer;
        this->denominator = denom;
    }

    RationalNumber(const RationalNumber &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    // ACCESSORS AND MUTATORS
    void setNumerator(int numer) { this->numerator = numer; }
    void setDenominator(int denom) { this->denominator = denom; }
    int getNumerator() const { return this->numerator; }
    int getDenominator() const { return this->denominator; }

    std::string printRational();

    // OPERATORS
    RationalNumber operator+(RationalNumber other);
    RationalNumber operator+(int other);
    friend RationalNumber operator+(int a, RationalNumber b);
    RationalNumber operator-(RationalNumber other);
    RationalNumber operator-(int other);
    friend RationalNumber operator-(int a, RationalNumber b);
    RationalNumber operator*(RationalNumber other);
    RationalNumber operator*(int other);
    friend RationalNumber operator*(int a, RationalNumber b);
    RationalNumber operator/(RationalNumber other);
    RationalNumber operator/(int other);
    friend RationalNumber operator/(int a, RationalNumber b);
    friend std::ostream &operator<<(std::ostream &out, RationalNumber &rNum);
};
