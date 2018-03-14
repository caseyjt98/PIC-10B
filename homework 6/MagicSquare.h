//
//  MagicSquare.h
//  homework6
//
//  Created by Casey Taylor on 11/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef MagicSquare_h
#define MagicSquare_h

#include <stdio.h>
#include <iostream>
#include <vector>



    std::istream& operator>>(std::istream&,std::vector<std::vector<int>>&); //read from a stream inre&to a vector <vector<int>> that will properly process the user’s input
 
    std::ostream& operator<<(std::ostream&, std::vector< std::vector<int>>); //writes a std::vector< std::vector<int>> with an output stream in the format demonstrated
    
    int count(bool); //stores a local static variable to track the number of solutions found and which returns the value of its count
    
    bool empty(size_t, size_t, const std::vector<std::vector<int>>&); //checks if a given position in the magic square is empty

    bool taken(int value, const std::vector<std::vector<int>>&); //checks if a given number is already used in the magic square
    
    bool checkValid(const std::vector<std::vector<int>>&); //to check if a complete magic square satisfies the proper conditions to be a solution
    
    void solveSquare (std::vector<std::vector<int>>, int); //recursive function, index tracks the number of slots already considered in the recursion, pass the vector into the function by value!!! for solveSquare


    









#endif /* MagicSquare_h */
