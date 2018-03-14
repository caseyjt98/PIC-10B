//
//  Complex.h
//  homework5
//
//  Created by Casey Taylor on 11/1/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef Complex_h
#define Complex_h
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>


class Complex {
private:
    double real; //stores real part of complex number
    double imaginary; //stores imaginary part of complex number
    
public:
    Complex(double r = 0, double i = 0); //default constructor, initializes real and imag to 0
    
    Complex &operator+=(const Complex&); //adds two complex numbers, changing the left hand side
    
    friend Complex &operator+(Complex, const Complex&); //binary, non member fnc
    
    Complex const &operator+(); //unary member fnc, the object parameter is implicitly *this
    
    Complex &operator++(); //prefix
    
    Complex operator++(int); //postfix, increments real by 1
    
    Complex &operator-=(const Complex&); //subtracts two complex numers, changing the left hand side
    
    friend Complex &operator-(Complex, const Complex&); // binary, non member fnc
    
    Complex operator-() const; //unary member fnc, return a complex # with negated real and imaginary parts
    
    Complex &operator--(); //prefix
    
    Complex operator--(int); //postfix, decrements real by 1
    
    Complex &operator*=(const Complex&); //multiplies two complex numbers, changing the left hand side
    
    friend Complex operator*(Complex, const Complex&); //binary non member fnc multiplies two complex numbers, returning the product
    
    Complex &operator/=(const Complex&); //divides two complex numbers, changing the left hand side
    
    friend Complex operator/(Complex, const Complex&); //binary non member fnc divides two complex numbers, returning the quotient
    
    
    Complex& operator()(); //call operator, sets the complex number to 0- PLACEMENT OF &??
    
    double &operator[](const std::string&); //subscript operator- returns number by reference??

    friend std::ostream& operator<<(std::ostream& os, const Complex& c); //prints complex number
    
    friend std::istream& operator>>(std::istream& in, Complex& c); //comparison operator
    
    friend bool operator<(const Complex& c1, const Complex& c2); //comparison operator
    
    friend bool operator==(const Complex& c1, const Complex& c2); //comparison operator
    
    friend bool operator>(const Complex& c1, const Complex& c2); //comparison operator
    
    friend bool operator<=(const Complex& c1, const Complex& c2); //comparison operator
    
    friend bool operator>=(const Complex& c1, const Complex& c2); //comparison operator
    
    friend bool operator!=(const Complex& c1, const Complex& c2); //comparison operator
    
    operator std::string() const; //conversion operator from Complex object to string
    
    
};

Complex operator""_i(long double c); //user defined literal function, non member fnc



#endif /* Complex_h */
