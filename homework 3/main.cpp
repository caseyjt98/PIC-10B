//
//  main.cpp
//  homework3
//
//  Created by Casey Taylor on 10/15/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "VectorString.h"


    pic10b::VectorString foo() {
        return pic10b::VectorString(2);
    }

    int main(){
    
        pic10b::VectorString vs;
        std::cout << "vs stats: " << vs.size() << " " << vs.capacity() << std::endl;
        vs.push_back("hello");
        std::cout << "vs stores: " << vs.at(0) << std::endl;
        pic10b::VectorString vs2(foo());
        std::cout << "vs2 stats: " << vs2.size() << " " << vs2.capacity() << std::endl;
        std::cout << "vs2 stores: ";
        for (std::size_t i = 0; i < vs2.size(); ++i) {
            std::cout << vs2.at(i) << ",";
        }
        pic10b::VectorString vs3(4, "beta");
        vs3.pop_back();
        vs3.push_back("delta");
        vs3.push_back("epsilon");
        vs3.at(1)= "gamma";
        vs3.insertAt(0, "alpha");
        std::cout << std::endl;
        vs3.push_back("zeta");
        vs3.push_back("theta");
        vs3.insertAt(vs3.size() - 1, "eta");
        vs3.deleteAt(3);
        std::cout << "v3 stats: " << vs3.size() << " " << vs3.capacity() << std::endl; 
        std::cout << "v3 stores: ";
        for (std::size_t i = 0; i < vs3.size(); ++i) {
            std::cout << vs3.at(i) << ",";
        }
        std::cin.get();
    
        return 0;
    }

    
    
    

