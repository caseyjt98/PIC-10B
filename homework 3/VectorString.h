//
//  VectorString.h
//  homework3
//  Created by Casey Taylor on 10/18/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.

/*
 I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
 I did not copy code from anyone, student or otherwise.
 */

#ifndef VectorString_h
#define VectorString_h

#include <iostream>
#include <string>


namespace pic10b {

class VectorString {
private: //member variables
    size_t sz; //number of elements in vector
    size_t cap; //size of underlying dynamic array in memory
    std::unique_ptr<std::string[]> pointer; //smart pointer to dynamic array of strings
    
    
public: //declare member functions
    VectorString(); //default constructor
    VectorString(size_t);
    VectorString(size_t, const std::string&);
    VectorString(const VectorString&); //copy constructor
    VectorString(VectorString&&); //move constructor
    size_t size() const;
    size_t capacity() const;
    void push_back(const std::string&);
    void pop_back();
    void deleteAt(size_t);
    void insertAt(size_t, const std::string&);
    std::string& at(size_t);
};


}

#endif /* VectorString_h */
