//
//  main.cpp
//  Sorting Algorithms
//
//  Created by Casey Taylor on 12/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <iostream>
#include <vector>
#include "algorithms.h"

int main() {
    
    //create a vector of integers storing six values
    std::vector<int> intVec { 3, 9, 11, 6, 2, 10};
    mergeSort(intVec, 0, 5);
    for(const auto x: intVec){
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
    
    std::vector<int> intVec2 { 3, 9, 11, 6, 2, 10};
    selSort(intVec2, 0, 5);
    for(const auto x: intVec2){
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
    
    std::vector<int> intVec3 { 3, 9, 11, 6, 2, 10};
    bubSort(intVec3, 0, 5);
    for(const auto x: intVec3){
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
    
    // true
    std::cout << binSearch(intVec.begin(), intVec.end(), 3);
    std::cout << std::endl;
    
    return 0;
}
