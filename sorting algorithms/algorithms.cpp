//
//  algorithms.cpp
//  Sorting Algorithms
//
//  Created by Casey Taylor on 12/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include "algorithms.h"

/* sorts a vector by repeatedly finding the minimum of the unsorted list and swapping the minimum with the first of the unsorted entries
 @param vec is the vector of integers being sorted
 @param beg is the lowest index included in the sort
 @param end is the largest index included in the sort
 note that stuff at beginning of list is put in place first
 */
void selSort(std::vector<int>& vec, size_t beg, size_t end){
    
    // first check is indices are valid for the sort
    // vec.size()-1 because we are dealing with indices, which start at 0
    if ( (end > vec.size()-1) || (beg > end) ) {
        throw std::logic_error("invalid input range"); // throw logic error
    }
    
    if (beg==end) { // nothing to sort
        return;
    }
    
    // get index of the smallest value, initially just first value in list
    size_t minimumPos = beg; // set to first value in list
    
    // start at second position in list (after minimumPos) and loop through indices
    for (size_t i = beg+1; i <=end; ++i) {
        if(vec[i] < vec[minimumPos]) { // if current element is smaller than previous minimum element
            minimumPos = i; // store current element in mimimumPos
        }
    }
    
    // place smallest element of unsorted range in place
    std::swap(vec[beg], vec[minimumPos]);
    
    // first element has been set
    // sort next part of the vector so that beg is in proper place
    selSort (vec, beg+1, end); // increment beg
    
}


/* sorts a vector by moving through the list and swapping adjacent entires if not already in sorted ordering, then cycling back over the unsorted list until all the tiems have been sorted
 @param vec is the inputted vector being sorted
 @param beg is the lowest index position included in the sort
 @param end is the largest index position included in the sort
 
 note that stuff at the end of the list is put in place first
 */

void bubSort(std::vector<int>& vec, size_t beg, size_t end){
    
    // first check if range is valid
    if ( (end > vec.size()-1) || (beg > end) ) {
        throw std::logic_error("invalid input range"); // throw logic error
    }
    
    if (beg==end) { // if nothing to sort
        return; // done
    }
    
    // loop through elements of the list, comparing and swapping adjacent elements if left element is larger than right element
    
    for (size_t i = beg; i < end; ++i) {
        if ( vec[i] > vec[i+1] ) { // if left element is larger than right element
            std::swap(vec[i], vec[i+1]); // swap the elements
        }
    }
    
    // last element has been set
    // with end value now in place, recurse over smaller range
    bubSort(vec, beg, end-1);
    
}

/* mergeSorted helper function
 @param vec is the vector of integers by reference being sorted
 @param beg is the lowest index position included in sort
 @param mid is the middle index position, the highest index included in first list, with index mid+1 being the lowest value included in second list
 @param end is the largest index position included in sort
 */
void mergeSorted(std::vector<int>& vec, size_t beg, size_t mid, size_t end){
    // set positions of the first and second parts of the vector and create a vector to store the result
    
    // first index
    size_t first = beg; // starts at first value of first list
    // second index
    size_t second = mid+1; // starts at first value of second list
    
    // create temporary vector to store sorted result
    std::vector<int> result(end-beg+1); // size due to inclusive range of values
    // temporary vector's index
    size_t vecIndex = 0; // starts at 0, first index of new vector
    
   
    // while both indices are in range
    while ( (first <= mid) && (second <= end) ) {
        // check if first value pointed to is less than second
        if (vec[first] < vec[second]) {
            // store first list value in result vector
            result[vecIndex] = vec[first];
            // increment first list index and result vector index
            vecIndex++; first++;
        }
        else { // if value in second list was less than value in first list
            // store second list value in result vector
            result[vecIndex] = vec[second];
            // increment second list index and result vector index
            vecIndex++; second++;
        }
    }
    
    // only one of the two while loops below will run
        
    while (first <= mid) { // while first index is within range of first list
        result[vecIndex] = vec[first];
        vecIndex++; first++;
    }
    while (second <= end) { // while second index is within range of second list
        result[vecIndex] = vec[second];
        vecIndex++; second++;
    }
    
    // now copy over correctly ordered values from result vector back to vec
    for (vecIndex = 0; vecIndex < result.size(); ++vecIndex) {
        vec[beg+vecIndex] = result[vecIndex];
    }
    
}


// sorts a vector by splitting it into smaller lists, sorting them, and then merging the sorted lists together
void mergeSort(std::vector<int>& vec, size_t beg, size_t end){
    // check indices
    if (beg==end) { // nothing to sort
        return; // done
    }
    
    // get middle position of overall list using integer division
    size_t mid = (beg+end)/2;
    
    mergeSort(vec,beg,mid); // sort the first half
    mergeSort(vec,mid+1,end); // sort the second half
    
    // with first and second halves sorted, the list can be merged
    
    mergeSorted(vec,beg,mid,end);
}


// searches for a value in vector<int> over a range of iterators by determing if it should search the upper/ lower half of the list
bool binSearch (std::vector<int>::const_iterator beg, std::vector<int>::const_iterator past_end, int val){
    
    if (beg==past_end) { // nothing to search through
        return false; // not found
    }
    
    // if only one item in range
    if (beg == (past_end-1) ) {
        if (*beg == val) { // if single value equals desired value
            return true; // found
        } else { // if not
            return false; // not found
        }
    }
    
    auto numElements = past_end - beg; // num of elements, auto bc it involves subtraction of iterators
    auto mid = beg + numElements/2;
    if (*mid == val) { // check if value equals mid value
        return true;
    } else if (val > *mid) { // if desired value is larger than mid, search top half of list
        return binSearch(mid+1, past_end, val);
    } else { // desired value is less than mid, search left half of list
        return binSearch(beg,mid,val);
    }
}


/* searches for a desired value by looping through and checking every value
 @param beg the beginning vector const iterator
 @param past_end the past end vector const iterator
 @val the desired value
 @returns bool, true if found
 */
bool seqSearch(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator past_end, int val){
    while (beg != past_end) { // while not past valid end
        if (*beg == val) {
            return true; // if equal, value is found
        }

    ++ beg; // increment beg
    }
    return false; // no match found if beg reaches past_end
}






