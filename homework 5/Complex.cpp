//
//  Complex.cpp
//  homework5
//
//  Created by Casey Taylor on 11/1/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Complex.h"


/*default constructor sets the real and imaginary parts to their inputted values, setting them to 0 in the case that no parameter was entered
 @param r is the inputted real number
 @param i is the inputted imaginary number
 @returns void
 */
Complex::Complex(double r, double i): real(r), imaginary(i) {}

/*binary operator+= adds two complex numbers, changing the left hand side
 @param rhs is the complex number being added
 note that first object parameter is implicitly the class object itself
 @returns a pointer to the updated object
 */
Complex &Complex::operator+=(const Complex& rhs){
    real += rhs.real;
    imaginary += rhs.imaginary;
    return *this; //return updated object
}

/*binary operator+ adds two complex numbers, returning the sum
 @param rhs is the first complex numbers being added
 @param lhs is the second complex number being added
 @returns lhs += rhs, the sum of the two complex numbers
 */
Complex &operator+(Complex lhs, const Complex& rhs){
    return lhs += rhs;
}
    
/*unary operator+ returns copy of complex number
 note that the first object parameter is implicitly the class object itself
 @returns a pointer to the updated object
 */
Complex const &Complex::operator+(){
    return *this;
}

/*prefix operator++ increments real part of complex number by 1
 @returns a pointer to the updated object
 */
Complex &Complex::operator++(){
    ++real; //increment
    return *this; //return updated object
}

/*postfix operator++ increments real part of complex number by 1
 @param int is unused
 @returns a copy of the class object
 */
Complex Complex::operator++(int){
    Complex copy(*this); //copy current object
    ++real; //increment real by 1
    return copy; //return the copy
}

/*binary operator-= subtracts two complex numers, changing the left hand side
 @param rhs is the complex number being subtracted
 note that the first paramater is implicitly the class object itself 
 @returns a pointer to the updated object
 */
Complex &Complex::operator-=(const Complex& rhs){
    real -= rhs.real;
    imaginary -= rhs.imaginary;
    return *this; //return updated object
}

/*unary operator- negates the real and imaginary parts of a complex number
 note that the first paramater is implicitly the class object itself
 @returns (0-*this), a negated version of the class object
 */
Complex Complex::operator-() const{
    return (0 - *this); //return updated object
}

/*binary operator- subtracts two complex numbers, returning the difference
 @param lhs is the first complex number being subtracted
 @param rhs is the second complex numer being subtracted
 @returns lhs -= rhs, the difference between the two complex numbers
 */
Complex &operator-(Complex lhs, const Complex& rhs){
    return lhs -= rhs;
}

/*prefix operator-- decrements real part of the complex number by 1
 @returns a pointer to the updated object
 */
Complex &Complex::operator--(){
    --real; //decrement
    return *this; //return updated object
}

/*postfix operator-- decrements real by 1
 @param int is unused
 @returns a copy of the class object
 */
Complex Complex::operator--(int){
    Complex copy(*this); //copy current object
    --real; //decrement real by 1
    return copy;
}

/*binary operator*= multiplies two complex numbers, changing the left-hand side
 @param c2 is the first complex number being multiplied
 note that the first paramater is implicitly the class object itself
 @returns the updated object
 */
Complex &Complex::operator*=(const Complex& c2){

    //(a + bi)(c + di) = (ac − bd) + (bc + ad)i
    
    double tempReal = real; //create temporary variable that is initialized to the value of real part
    
    //calculate real part
    real = (tempReal * c2.real) - (imaginary * c2.imaginary);             //(ac-bd)
    
    //calculate imaginary part
    imaginary = (c2.imaginary * tempReal) + (imaginary * c2.real);    //(bc+ad)
    return *this;
  
}

/*binary operator* multiplies two complex numbers, returning the product
 @param lhs is the first complex number being multiplied
 @param rhs is the second complex number being multiplied
 @returns the product of the two complex numbers
 */
Complex operator*(Complex lhs, const Complex& rhs){
    return lhs*=rhs; //return product
}

/*binary operator/= divides two complex numbers, changing the left hand side
 @param c2 is the complex number being divided
 note that the first paramater is implicitly the class object itself
 @returns the updated object
 */
Complex &Complex::operator/=(const Complex& c2){
    
    //(a + bi)/(c + di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)
    
    double tempReal = real; //temporary variable that stores value of real
    double tempImag = imaginary; //temporary variable that stores value of imaginary
    
    //calculate real part
    real=((tempReal * c2.real) + (tempImag * c2.imaginary)) /        //(ac+bd) divided by
    ((c2.real * c2.real)+(c2.imaginary * c2.imaginary));             //(c^2+d^2)
    
    //calculate imaginary part
    imaginary=((tempImag * c2.real) - (tempReal * c2.imaginary)) /   //(bc-ad) divided by
    ((c2.real * c2.real)+(c2.imaginary * c2.imaginary));             //(c^2+d^2)
    return *this;
    
}

/*binary operator/ divides two complex numbers, returning the quotient
 @param lhs is the first complex number being divided
 @param rhs is the second complex number being divided
 @returns the quotient of the two complex numbers
 */
Complex operator/(Complex lhs, const Complex& rhs){
    return (lhs)/=(rhs); //return quotient
}


/*call operator sets complex number to 0
 @param void
 @returns the updated object, which has been set to 0
 */
Complex &Complex::operator()(){
    real = 0; //set real to 0
    imaginary = 0; //set imaginary to 0
    return *this; //return object
}



/*subscript operator takes in real or imaginary as arguments and returns the parts of the number by reference, throwing an out of range exception with an error description if the subscript is invalid
 @param string subscript is either "real" or "imag" 
 @returns double, the real or imaginary part of the number by reference
 */
double &Complex:: operator[](const std::string& subscript){
            if (subscript == "real") {
                return real;
            }
            else if( subscript == "imag") {
                return imaginary;
            }
            else { // then invalid index
                throw std::out_of_range("Invalid Index: " + subscript);
                //note that try catch block is not needed because it is in main.cpp
            }
        }



/*operator<< prints the complex number with an output stream with regards to the signs of the real and imaginary parts of the number
@param c is the complex number
@param an output stream of the real and imaginary parts of the complex number
*/
std::ostream& operator<<(std::ostream& out, const Complex& c){
    //fulfill all conditions for complex number combinations
    if ((c.real>0) && (c.imaginary>0)){
        out << c.real << "+" << c.imaginary << "i ";    //a+bi
    }else if((c.real>0) && (c.imaginary<0)){
        out << c.real << c.imaginary << "i";            //a-bi
    }else if((c.real<0) && (c.imaginary>0)){
        out << c.real << "+" << c.imaginary << "i";     //-a+bi
    }else if((c.real==0) && (c.imaginary>0)){
        out << c.imaginary << "i";                      //bi
    }else if((c.real>0) && (c.imaginary==0)){
        out << c.real;                                  //a
    }else if((c.real<0) && (c.imaginary<0)){
        out << c.real << c.imaginary << "i";            //-a-bi
    }else if((c.real<0) && (c.imaginary==0)){
        out << c.real;                                  //-a
    }else if((c.real==0) && (c.imaginary<0)){
        out << c.imaginary << "i";                      //-bi
    }else if((c.real == 0) && (c.imaginary == 0)){
        out << 0;                                       //0
    }
    
    return out;
}


/*operator<< reads in two double values and sets the real/ imaginary parts of the complex number on the right side of an input stream
 @param c is the inputted complex number object
 @returns an input stream with the real and imaginary parts of the complex number
*/
std::istream& operator>>(std::istream& in, Complex& c){
    in >> c.real >> c.imaginary; //read in two values
    return in;
}

/*comparison operator< checks whether one complex number is less than another
 @param c1 is the first complex number being compared
 @param c2 is the second complex number being compared
 @returns bool isLessThan, true if c1 was less than c2
 */
bool operator<(const Complex& c1, const Complex& c2){
    bool isLessThan = false;
    if(c1.real < c2.real){
        isLessThan = true;
    }
    else if(c1.real > c2.real){
        isLessThan = false;
    }
    else{ //real parts are equal, so compare imaginary parts
        if(c1.imaginary < c2.imaginary){
            isLessThan = true;
        }
    }
    return isLessThan;
}

/*comparison operator== checks for equality between two complex numbers
 @param c1 is the first complex number being compared
 @param c2 is the second complex number being compared
 @returns bool, true if c1 was equal to c2 (both their real and imaginary parts are equal)
 */
bool operator==(const Complex& c1, const Complex& c2){
    //equality btwn two complex numbers is when the real AND imaginary parts are equal
    return (c1.real == c2.real) && (c1.imaginary == c2.imaginary);
}

/*comparison operator> checks whether one complex number is greater than another
@param c1 is the first complex number being compared
@param c2 is the second complex number being compared
@returns bool isGreaterThan, true if c1 was greater than c2
*/
bool operator>(const Complex& c1, const Complex& c2){
    bool isGreaterThan = false;
    if(c1.real > c2.real){
        isGreaterThan = true;
    }
    else if(c1.real < c2.real){
        isGreaterThan = false;
    }
    else{ //real parts are equal, so compare imaginary parts
        if(c1.imaginary > c2.imaginary){
            isGreaterThan = true;
        }
    }
    return isGreaterThan;
}

/*comparison operator<= checks whether one complex number is less than or equal to another
 @param c1 is the first complex number being compared
 @param c2 is the second complex number being compared
 @returns bool isLessThanOrEqualTo, true if c1 was less than or equal to c2
 */
bool operator<=(const Complex& c1, const Complex& c2){
    bool isLessThanOrEqualTo = false;
    if (c1.real == c2.real && c1.imaginary == c2.imaginary){ //if real and imaginary parts are equal
        isLessThanOrEqualTo = true;
    }
    else if (c1.real < c2.real){ //otherwise, compare real parts
        isLessThanOrEqualTo = true;
    }
    else if(c1.real > c2.real){
        isLessThanOrEqualTo = false;
    }
    else{ //if real parts are equal, compare imaginary parts
        if(c1.imaginary < c2.imaginary){
            isLessThanOrEqualTo = true;
        }
    }
    
    return isLessThanOrEqualTo;
}

/*comparison operator>= checks whether one complex number is greater than or equal to another
 @param c1 is the first complex number being compared
 @param c2 is the second complex number being compared
 @returns bool isGreaterThanOrEqualTo, true if c1 was greater than or equal to c2
 */
bool operator>=(const Complex& c1, const Complex& c2){
    bool isGreaterThanOrEqualTo = false;
    if (c1.real == c2.real && c1.imaginary == c2.imaginary){ //if real and imaginary parts are equal
        isGreaterThanOrEqualTo = true;
    }
    else if (c1.real > c2.real){ //otherwise, compare real parts
        isGreaterThanOrEqualTo = true;
    }
    else if(c1.real < c2.real){
        isGreaterThanOrEqualTo = false;
    }
    else{ //if real parts are equal, compare imaginary parts
        if(c1.imaginary > c2.imaginary){
            isGreaterThanOrEqualTo = true;
        }
    }
    return isGreaterThanOrEqualTo;
}

/*comparison operator!= checks for inequality between two complex numbers
 @param c1 is the first complex number being compared
 @param c2 is the second complex number being compared
 @returns bool, true if c1 did not equal c2 (either their real or imaginary parts were not equal)
 */
bool operator!=(const Complex& c1, const Complex& c2){
    //two complex numbers are not equal if their real parts OR imaginary parts are not equal
    return ((c1.real != c2.real) || (c1.imaginary != c2.imaginary));
}



/*conversion operator converts Complex object to string
 @returns string, the full complex number number
 */
Complex::operator std::string() const{

    std::string result;//string which will contain the result
    
    std::stringstream convert; // stringstream used for the conversion
    
    //add values of real and imaginary to the stream
    if(real == 0 && imaginary == 0){
        convert << 0 << " "; //add 0 to the stream
    } else {
        convert << real; //add a to the stream
        if (imaginary < 0){
            convert << imaginary << "i" << " "; //add -bi to the stream
        } else { //imaginary is greater than 0
            convert << "+" << imaginary << "i" << " "; //add +bi to the stream
        }
    }
    
    result = convert.str();
    
    return result;
}


/*user defined literal function converts an expression such as 4.1 i to the complex number 0+4.1i
 @param long double c is the inputted expression to be converted
 @returns a complex number with real part set to 0 and a cast to double for the imaginary part
 */
Complex operator""_i(long double c){
    return Complex(0, static_cast<double>(c)); //set real part to 0, cast to double for imaginary part
}




    
