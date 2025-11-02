#include "fraction.h"
#include <limits>
#include <exception>

int GCD(int a, int b){
    while (b !=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction operator+(const Fraction& a, const Fraction& b){
    int newNumerator = a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator();
    int newDenominator = a.getDenominator() * b.getDenominator();
    int GCDvalue = GCD(newNumerator, newDenominator);
    return Fraction(newNumerator / GCDvalue, newDenominator / GCDvalue);
};
Fraction operator+(const Fraction& a, const int& b){
    int newNumerator = a.getNumerator() + b * a.getDenominator();
    int newDenominator = a.getDenominator();
    return Fraction(newNumerator, newDenominator);
};
Fraction operator-(const Fraction& a, const Fraction& b){
    int newNumerator = a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator();
    int newDenominator = a.getDenominator() * b.getDenominator();
    int GCDvalue = GCD(newNumerator,newDenominator);
    return Fraction(newNumerator / GCDvalue, newDenominator / GCDvalue);
}
Fraction operator-(const Fraction& a, const int& b){
    int newNumerator = a.getNumerator() - b * a.getDenominator();
    int newDenominator = a.getDenominator();
    return Fraction(newNumerator, newDenominator);
}
Fraction operator*(const Fraction& a, const Fraction& b){
    int newNumerator = a.getNumerator() * b.getNumerator();
    int newDenominator = a.getDenominator() * b.getDenominator();
    int GCDvalue = GCD(newNumerator,newDenominator);
    return Fraction(newNumerator / GCDvalue,newDenominator / GCDvalue);
}
Fraction operator*(const Fraction&a ,const int& b){
    if (b == 0){
        return Fraction(0,1);
    }
    int newNumerator = a.getNumerator() * b;
    int newDenominator = a.getDenominator();
    int GCDvalue = GCD(newNumerator, newDenominator);
    return Fraction(newNumerator / GCDvalue, newDenominator / GCDvalue);
}
Fraction operator/(const Fraction& a, const Fraction& b){
    int newNumerator = a.getNumerator() * b.getDenominator();
    int newDenominator = a.getDenominator() * b.getNumerator();
    int GCDvalue = GCD(newNumerator,newDenominator);

    return Fraction(newNumerator / GCDvalue,newDenominator / GCDvalue);
}
Fraction operator/(const Fraction& a, const int& b){
    try {
        if (b == 0){
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        int newNumerator = a.getNumerator();
        int newDenominator = a.getDenominator() * b;
        int GCDvalue = GCD(newNumerator, newDenominator);
        return Fraction(newNumerator / GCDvalue, newDenominator / GCDvalue);
    }
    catch (std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
        int newB {};
        while (true){
            std:: cout << "Enter a non-zero integer to divide by:" << std::endl;
            if (std:: cin >> newB){
                if (newB !=0){
                    int newNumerator = a.getNumerator();
                    int newDenominator = a.getDenominator() * newB;
                    int GCDvalue = GCD(newNumerator, newDenominator);
                    return Fraction(newNumerator / GCDvalue, newDenominator / GCDvalue);
                }
                else{
                    std:: cout << "Denominator can't be zero. Enter again" << std:: endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
    }
}