#include "RationalNumber.h"
#include <iostream>

using namespace std;

RationalNumber RationalNumber::operator+(RationalNumber other)
{
    RationalNumber newRational;
    newRational.numerator = this->numerator * other.denominator +
                            this->denominator * other.numerator;
    newRational.denominator = this->denominator * other.denominator;
    newRational.reduce();
    return newRational;
}

RationalNumber RationalNumber::operator+(int other)
{
    RationalNumber result = *this + RationalNumber(other);
    return result;
}

RationalNumber operator+(int a, RationalNumber b)
{
    return RationalNumber(a) + b;
}

RationalNumber RationalNumber::operator-(RationalNumber other)
{
    RationalNumber newRational;
    newRational.numerator = this->numerator * other.denominator -
                            this->denominator * other.numerator;
    newRational.denominator = this->denominator * other.denominator;
    newRational.reduce();
    return newRational;
}

RationalNumber RationalNumber::operator-(int other)
{
    RationalNumber result = *this - RationalNumber(other);
    return result;
}

RationalNumber operator-(int a, RationalNumber b)
{
    return RationalNumber(a) - b;
}

RationalNumber RationalNumber::operator*(RationalNumber other)
{
    RationalNumber newRational;
    newRational.numerator = this->numerator * other.numerator;
    newRational.denominator = this->denominator * other.denominator;
    newRational.reduce();
    return newRational;
}

RationalNumber RationalNumber::operator*(int other)
{
    RationalNumber result = *this * RationalNumber(other);
    return result;
}

RationalNumber operator*(int a, RationalNumber b)
{
    return RationalNumber(a) * b;
}

RationalNumber RationalNumber::operator/(RationalNumber other)
{
    if (other.numerator == 0)
    {
        cout << "Error: Cannot divide by zero." << endl;
        exit(1);
    }
    RationalNumber newRational;
    newRational.numerator = this->numerator * other.denominator;
    newRational.denominator = this->denominator * other.numerator;
    newRational.reduce();
    return newRational;
}

RationalNumber RationalNumber::operator/(int other)
{
    if (other == 0)
    {
        cout << "Error: Cannot divide by zero." << endl;
        exit(1);
    }
    RationalNumber result = *this / RationalNumber(other);
    return result;
}

RationalNumber operator/(int a, RationalNumber b)
{
    return RationalNumber(a) / b;
}

ostream &operator<<(ostream &out, RationalNumber &rNum)
{
    out << rNum.numerator << "/" << rNum.denominator;
    return out;
}