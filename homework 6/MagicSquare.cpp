//
//  MagicSquare.cpp
//  homework6
//
//  Created by Casey Taylor on 11/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//


#include "MagicSquare.h"



/*operator>> reads from a stream into a vector <vector<int>> that will appropriately process the user's input
 @param matrix is a vector<vector<int>> storing the the magic square matrix
 @param in is an input stream of the magic square matrix, entered row by row with enteries separated by spaces, rows separated by [enter] and * signifying that the value does not matter
 @returns an input stream of the inputted matrix
 */
std::istream& operator>>(std::istream& in, std::vector<std::vector<int>>& matrix){
    
    int input; //user input
    
    if(matrix.size() == 0) { //if matrix size is 0
        std::cout << "Invalid size" << std::endl;
    }
        else if(matrix.size() == 1) { //if matrix size is 1
            std::cout << "Matrix size is equal to 1, Solution is: 1" << std::endl;
        }
            else if(matrix.size() >= 2) { //if matrix size is two or greater
        
                for(size_t i = 0; i < matrix.size(); i++){
                    
                    for(size_t j = 0; j < matrix.size(); j++){ //loop through rows and columns
                        
                        in >> input; //loop through each user input and read to input stream
                        
                        if(in.fail()) { //if input fails, indicates an * and slot should be set to 0
                            matrix[i][j] = 0; //set proper index to 0
                            //clear buffer
                            in.clear();
                            in.ignore();
                    
                        } else { //if input does not fail
                                matrix[i][j] = input; //set proper slot to value of user input
                        
                        }
                    }
                }
            }
    return in;
}


/*operator<< writes a std::vector< std::vector<int>> with an output stream in the format demonstrated
 @param an output stream of the magic square in demonstrated matrix format 
 @param matrix is a vector<vector<int>> storing the the magic square matrix
 @returns the output stream, printing out the matrix
 */
std::ostream& operator<<(std::ostream& out, std::vector< std::vector<int>> matrix){
    for(size_t i = 0; i < matrix.size(); i++){
        
        for(size_t j = 0; j < matrix.size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return out;
}



/*This function increments a count when neccessary and returns its count value
 @param increase is a bool value, with true indicating that counter should be incremented and false otherwise
 @returns count, the updated number of solutions for a given magic square
 */
int count(bool increase){
    static int counter = 0; //only intializes to 0 once
    if(increase){ //if it should increase
        counter++; //increase counter
    }
    return counter; //return updated counter
}



/* This function checks if a given position in the magic square matrix is empty
 */
bool empty(size_t row, size_t col, const std::vector<std::vector<int>>& check){
    if(check[row][col] == 0){ //if value of index is 0
        return true; //the spot is empty
    }
    return false; //otherwise, the spot is not empty
}


/*This function checks if a given integer value is already used in the magic square
 @param value is the integer value being checked
 @param check is the magic square matrix passed in by reference
 @returns bool, true if the given integer value is already taken and false otherwise
 */
bool taken(int value, const std::vector<std::vector<int>>& check){

    for(size_t i = 0; i < check.size(); i++){
    
        for(size_t j = 0; j < check.size(); j++){ //loop through rows and columns
            
            if(check[i][j] == value){ //if inputted value is found at a given matrix position
                return true; //the given number is taken
            }
        }
    }
    return false; //otherwise, the given number is not taken
}



/*This function checks if a complete magic square satisfies the proper conditions to be a solution
 @param check is the magic square matrix passed in by reference
 @returns bool, true if the square is a valid solution and false otherwise
 */
bool checkValid(const std::vector<std::vector<int>>& check){
    size_t firstRowSum = 0;
    size_t leftDiagSum = 0;
    size_t rightDiagSum = 0;
    
    //loop across rows to check sums
    for(size_t i = 0; i < check.size(); i++) {
        size_t rowSum = 0;
        for(size_t j = 0; j < check.size(); j++) { //loop across columns
            rowSum += check[i][j]; //calculate sum of row
        }
        
        if(i == 0) { //if first row
            firstRowSum = rowSum; //store first sum in new variable
        } else { //if not first row
            if(rowSum != firstRowSum){ //if row sum does not equal sum of first row
                return false; //square is invalid
            }
        }
    }
    
    //loop across columns to check sums
    for(size_t j = 0; j < check.size(); j++) { //loop through columns
        size_t colSum = 0;
        for (size_t i = 0; i < check.size(); i++) {
             colSum += check[i][j]; //calculate sum of column
        }
        if(colSum != firstRowSum){ //if column sum does not equal sum of first row
            return false; //square is invalid
        }
    }

    //check sum of left diagonal
    for(size_t i = 0, j = 0; i < check.size(); i++, j++){
        leftDiagSum += check[i][j]; //find sum of values on left diagonal
    }
    
    if(leftDiagSum != firstRowSum){ //if sum of left diagonal does not equal sum of first row
        return false; //square is invalid
    }
    
    
    //check sum of right diagonal
    for(size_t i = 0, j = (check.size()-1); i < check.size(); i++, j--){
            rightDiagSum += check[i][j]; //find sum of values on right diagonal
    }
    if(rightDiagSum != firstRowSum){ //if sum of right diagonal does not equal sum of first row
        return false; //square is invalid
    }
    
    
    return true; //if it reaches this point, square is valid
}



/*This recursive function solves the magic square
 @param index tracks the number of slots already considered in the recursion
 @param matrix is the vector passed in by value, bc each recursive call modifies the matrix
 */
void solveSquare (std::vector<std::vector<int>> matrix, int num){
    size_t totalNumOfSlots = ((matrix.size())*(matrix.size())); //total number of slots is equal to the size of the matrix squared
    
    if (num == totalNumOfSlots) { //if the number of slots considered equals total number of slots (matrix is full)
        //check if matrix is valid
        if (checkValid(matrix)) { //if matrix is valid
            std::cout << matrix << std::endl; //print matrix
            count(true); //increase solution counter
        }
    } else { //if matrix is not valid
        //determine if slot is empty
        
        //get row and column based on num
        int row = (num / (matrix.size()));
        int column = (num % (matrix.size()));
        if(empty(row,column,matrix)) {
            for(int value = 1; value <= totalNumOfSlots; value++){
                if(!taken (value, matrix)) { //if integer value isn't taken already in matrix
                    matrix[row][column] = value; //if spot isn't taken, input integer possibility
                    solveSquare(matrix, num+1); //try solving magic square for by repeating process with num + 1
                }
            }
        } else { //if slot is not empty
            solveSquare(matrix, num+1); //try solving magic square by looking at next slot
        }
    }
}


