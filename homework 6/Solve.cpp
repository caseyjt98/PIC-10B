//
//  Solve.cpp
//  homework6
//
//  Created by Casey Taylor on 11/14/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

/*
 I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
 I did not copy code from anyone, student or otherwise.
 I collaborated with SANJAY SHUKLA and KIANA MILLS and I affirm that we all contributed equally in the code.
 */

#include <stdio.h>
#include "MagicSquare.h"

int main(){
    
    size_t size; //size of magic square
    
    
    //prompt user for valid square size
    std::cout << "This program finds magic square solutions." << std::endl;
    std::cout << "Enter a square size: ";
    std::cin >> size; //read in size
    
    std::vector<std::vector<int>> matrix (size, std::vector<int>(size)); //vector of vector of ints stores matrix, sets rows and columns to inputted size
    
    //prompt for square format
    std::cout<< "Enter square format: " << std::endl;
    std::cout << "You may specify certain numbers, or enter * for a blank space." << std::endl;
    std::cout << "For example: " << std::endl;
    std::cout << "*3*" << std::endl;
    std::cout << "**2" << std::endl;
    std::cout << "***" << std::endl;
    std::cout << std::endl;
    std::cin >> matrix; //read in the matrix
    
    //print matrix
    std::cout << matrix << std::endl;
    
    //solve magic square
    solveSquare(matrix,0);
    
    //print number of solutions found
    std::cout << "Solving complete!" << std::endl;
    std::cout << "There were " << count(false) << " " << "solutions." << std::endl;
    
    
    return 0;
}

