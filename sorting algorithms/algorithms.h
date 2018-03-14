//
//  algorithms.h
//  Sorting Algorithms
//
//  Created by Casey Taylor on 12/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef algorithms_h
#define algorithms_h
#include <iostream>
#include <vector>


// selection sort
// takes in vector of integers by reference to sort
// takes in two size_t variables, one is the lowest index position to include in the sort, the other is the largest index position to include in the sort
void selSort(std::vector<int>&, size_t, size_t);


// bubble sort
// takes in vector of integers by reference to sort
// takes in two size_t variables, one is the lowest index position to include in the sort, the other is the largest index position to include in the sort
void bubSort(std::vector<int>&, size_t, size_t);


// merge sorted helper function
// takes in a vector of integers by reference to sort
// takes in three size_t variables
    // one is the lowest index position to include in the sort
    // another is the middle index, aka where the list is to be split
    // the last is the largest index position to include in the sort
void mergeSorted(std::vector<int>&, size_t, size_t, size_t);


// merge sort
// takes in vector of integers by ref to sort
// takes in two size_t variables, one is the lowest index position to include in the sort, the other is the largest index position to include in the sort
void mergeSort(std::vector<int>& v, size_t beg, size_t end);


// binary search
// takes in vector begin iterator
// takes in vector past end iterator
// takes in desired value
// returns bool

bool binSearch(const std::vector<int>::const_iterator, const std::vector<int>::const_iterator, int);


// sequential search
// takes in beginning vector const iterator
// takes in past end vector const iterator
// takes in desired value
// returns bool
bool seqSearch(std::vector<int>::const_iterator, std::vector<int>::const_iterator, int);






#endif /* algorithms_h */
