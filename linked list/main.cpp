//
//  main.cpp
//  homework7
//
//  Created by Casey Taylor on 11/21/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"


using namespace pic10b;

int main() {
    pic10b::LinkedList list1;
    list1.push_back(8);
    std::cout << "List 1: " << list1 << std::endl;
    list1.push_back(3);
    std::cout << "List 1: " << list1 << std::endl;
    list1.push_back(14);
    std::cout << "List 1: " << list1 << std::endl;
    list1.push_back(-13);
    std::cout << "List 1: " << list1 << std::endl;
    list1.push_back(0);
    std::cout << "List 1: " << list1 << std::endl;
    list1.push_back(3); // a second 3!!!
    std::cout << "List 1: " << list1 << std::endl;
    
    list1.sort();
    std::cout << "List 1: " << list1 << std::endl;
    
    
    auto it = list1.begin();
    ++it;
    list1.insert(it, 144);
    std::cout << "List 1: " << list1 << std::endl;
    
    list1.insert(list1.end(), 44);
    std::cout << "List 1: " << list1 << std::endl;
    list1.pop_back();
    std::cout << "List 1: " << list1 << std::endl;
    
   
    const pic10b::LinkedList list2 = list1;
    std::cout << "List 2: " << list2 << std::endl;
    
    
    
    std::cout << "List 1: " << list1 << std::endl;
    std::cout << "List 2: " << list2 << std::endl;
    auto beg1 = list1.begin();
    auto end1 = list1.end();
    end1--; // so it last element will not be searched through in the searches to come...
    //auto beg2 = list2.begin();
    //auto end2 = list2.end();
    //bool found1 = pic10b::seqSearch(beg1, end1, 144);
    //bool found2 = pic10b::seqSearch(beg2, end2, 144);
    // the bool alpha turns the 0/1 for false/true into "false" and "true"
    //std::cout << std::boolalpha << found1 << " " << found2 << std::endl;
    std::cin.get();
     
    return 0;
}
