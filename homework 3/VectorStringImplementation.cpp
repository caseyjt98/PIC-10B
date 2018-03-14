//
//  VectorStringImplementation.cpp
//  homework3
//
//  Created by Casey Taylor on 10/18/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <stdio.h>
#include "VectorString.h"

using namespace std;

namespace pic10b {
    
/* Default constructor allocates a dynamic array of size cap, with a unique pointer at the first element
*/
VectorString::VectorString(): cap(1), sz(0), pointer(new std::string[cap]) {
}

    
/* Constructor function allocates a dynamic array of twice the input size, with all string variables set to the empty string. It initializes sz to the input and cap to twice the input.
 @param size is the specified number of string elements in the dynamic array
 */
VectorString::VectorString(size_t size): sz(size), cap(sz*2), pointer(new std::string[cap]) {
}

    
/* Constructor function allocates a dynamic array of twice the input size and intializes all the string variables to the input string
 @param size is the specificied number of elements
 @param &inputString is a reference to the inputted string
 */
VectorString::VectorString(size_t size, const std::string& inputString): sz(size), cap(2*sz), pointer(new std::string[cap]){
    for(size_t i=0;i<sz;i++){
        pointer[i] = inputString; //set all string variables to input string
    }
}

    
/* Copy constructor copies all the values stored in the assigned-from object
 @param &copyVec is a reference to the vector being copied
 */
VectorString::VectorString(const VectorString& copyVec): sz(copyVec.sz), cap(copyVec.cap) {
    pointer.reset(new std::string[cap]); //pointer now points to a default constructed dynamic array
    for(size_t i=0;i<sz;i++){
        pointer[i]= copyVec.pointer[i]; //copy elements into new dynamic array
    }
}

    
/*Move constructor creates a new object by harvesting the resources of an old object
@param vec is the old vector whose resources will be used to construct a new vector
*/
VectorString::VectorString(VectorString&& vec): sz(vec.sz), cap(vec.cap), pointer(move(vec.pointer)){
}

    
/* This function returns the size of the vector
 @returns sz, the number of elements in the vector (never negative)
 */
size_t VectorString::size() const{
    return sz;
}
    

/* This function returns the capacity of the vector
@returns cap, the size of underlying dynamic array in memory (never negative)
*/
size_t VectorString::capacity() const{
    return cap;
}

    
/* This function adds an element to the end of the vector if capacity allows or creates a new dynamic array with double capacity, moving the old elements over and adding the new element
 @param &element is a reference to the inputted element that will be added to end of the dynamic array
 @return void
 */
void VectorString::push_back(const std::string& element){
    if (cap > sz){ //if there is space available in allocated memory
        pointer[sz] = element; //add element to available index
        ++sz; //update size
        
    }else{ //if allocated memory is full
        cap = cap*2; //double capacity
        std::unique_ptr<std::string[]> temp(new std::string[cap]); //temporary smart pointer to new allocated array with updated capacity
        
        for(size_t i=0;i<sz;i++){ //copy old elements over into new array
            temp[i] = pointer[i];
            
        }
        //add element to new dynamic array
        temp[sz] = element;
        ++sz;
        //reset pointer to new dynamic array
        pointer.reset(temp.release()); //relinquish control of heap object and reset pointer to that value
    }
}

    
/* This function "removes" the last element of the vector by updating its sz value
 @returns void
 */
void VectorString::pop_back(){
    sz = sz - 1; //decrement size by one
}

    
/* This function removes element at input position, shifting elements back as appropriate
 @param index is the specified index of the element which is to be removed 
 @return void
 */
void VectorString::deleteAt(size_t index){
    for(size_t i = (index+1); i < sz; i++){
        pointer[i-1] = pointer[i]; //shift elements over one
    }
    sz--; //decrement size
}

    
/* This function first checks capacity, moving old elements to a new dynamically allocated array if needed. Given that capacity is sufficient, it adds a new element at input position and shifts elements over as appropriate.
 @param index is the specified index into which the new element will be inserted
 @param &element is a reference to the element that is being inserted
 @return void
 */
void VectorString::insertAt(size_t index, const std::string& element){
    
    if (cap > sz){ //if there is space available in allocated memory
        for(size_t i = sz; i>index; i--){ //move over old elements to make space for new element
            pointer[i] = pointer[i-1]; //move element over one
        }
        pointer[index] = element; //insert element to specified index
        
    }else{ //if allocated memory is full
        cap = cap*2; //double capacity
        std::unique_ptr<std::string[]> temp(new std::string[cap]); //temporary smart pointer to new allocated array with updated capacity
        
        for(size_t i=0;i<sz;i++){ //copy old elements over into new array
            temp[i] = pointer[i];
        }
        
            for(size_t i = sz; i>index; i--){ //move over old elements to make space for new element
                temp[i] = temp[i-1]; //move element over one
            }
            temp[index] = element; //insert element to specified index
        
        pointer.reset(temp.release()); ////relinquish control of heap object and reset new pointer to that value
    }
    sz++; //increment size
}

    
/* This function returns the element at the given index by reference
 @param index is the specified index of the element which is to be returned 
 @returns string& is a reference to the string element at the specified index
 */
std::string& VectorString::at(size_t index){
    if (sz < index){
        throw std::logic_error("index out of bounds");
    }
    return pointer[index]; // otherwise, return last element
}

    
}
