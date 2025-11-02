#pragma once
#include <iostream>

class Fraction {
    private:
        int numerator_;
        int denominator_;
    public:
    Fraction (int numerator = 0, int denominator = 1){
        numerator_ = numerator;
        denominator_ = denominator;
    }
    int getNumerator() const {
        return numerator_;
    };
    int getDenominator() const {
        return denominator_;
    };
    void print() const {
        std::cout << numerator_ << "/" << denominator_ ;
    }
};

Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator+(const Fraction& a, const int& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const int& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const int& b);
Fraction operator/(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const int& b);