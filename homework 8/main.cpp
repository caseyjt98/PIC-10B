//
//  main.cpp
//  Homework8
//
//  Created by Casey Taylor on 11/28/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <iostream>
#include<ctime>
#include "BinarySearchTree.h"


using namespace pic10b;

int main() {

    std::srand(std::time(nullptr)); // seed
    
    
    pic10b::Tree t1; // empty tree
    
    t1.insert(50);
    t1.insert(75);
    t1.insert(25);
    t1.insert(10);
    t1.insert(99);
    t1.insert(49);
    t1.insert(60);
  
    std::cout << "Elements: "; // and print the elements
    for (auto itr = t1.begin(); itr != t1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Count of elements: " << t1.size() << std::endl; // count elements in t1
    
    pic10b::Tree t2 = t1; // t2 is a copy of t1
    
    
    double low, up; // lower and upper bounds for value removal
    std::cout << "Enter lower and upper values for removal: ";
    std::cin >> low >> up; // read in values
    auto itr = t1.begin();
    while (itr != t1.end()){ // while not at the end
        if ((low <= *itr) && (*itr <= up)){ // check if node value in range
            t1.erase(itr); // if so, erase it
            itr = t1.begin(); // and go back to the beginning
            continue; // repeat the loop, ignoring the increment
            }
        ++itr; // if not in range then increment the iterator
    }
    
    
    std::cout << "Elements: "; // and print the elements
    for (auto itr = t1.begin(); itr != t1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    
    // List all the elements of the two trees
    std::cout << "t1 and t2 elements: " << std::endl;
    for (auto itr = t1.begin(); itr != t1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    for (auto itr = t2.begin(); itr != t2.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    

    t2 = std::move(pic10b::Tree()); // move a default Tree
    std::cout << "t2 size now: " << t2.size() << std::endl;
    t2.insert(3.14); // add two numbers
    t2.insert(100);
    
    pic10b::Tree::iterator iter_to_first = t2.begin();
    if (t2.find(3.14) == iter_to_first) { // check if 3.14 in collection and if first
        std::cout << "3.14 first item!" << std::endl;
    }
    
    
    return 0;
}
