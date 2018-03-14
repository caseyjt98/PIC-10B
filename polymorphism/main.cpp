//
//  main.cpp
//  polymorphism
//
//  Created by Casey Taylor on 12/11/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "company.h"


// must initialize static variable above main routine
size_t Contact::max_id = 1; // set max ID to 1

int main() {
    // create vector of contact pointers
    std::vector<Contact*> vecContact;
    vecContact.push_back (new Employee("Casey","San Francisco"));
    vecContact.push_back (new Employee("Claire","San Diego"));
    
    std::ofstream out("outputFile.txt");
    for (const Contact* ptr : vecContact) { // loop over each pointer
        ptr->displayInfo(out); // print object's info
        out << std::endl;
    }
    /* static type of each pointer was Contact* (what appears in the code)
        But, underlying pointed- to object was Employee (dynamic type). The pointer behaves as an Employee*. The virtual function displayInfo is being called upon the Employee objects (VIRTUAL FUNCTIONS ARE CALLED BASED ON DYNAMIC TYPE)
     */
    
    // a better implementation would be with smart pointers, to avoid memory leaks
    // create a vector of shared_ptr to Contact objects
    std::vector <std::shared_ptr<Contact> > vc;
    
    // recall that make shared constructs an object, wrapping it with a shared pointer
    vc.push_back (std::make_shared <Employee> ("Casey","San Francisco"));
    vc.push_back (std::make_shared <Employee> ("Claire", "San Diego"));
    
    std::ofstream out2("outputFile.txt");
    for (const auto& sptr : vc) {
        sptr->displayInfo(out2);
        out2 << std::endl;
    }
    
    
    std::vector<std::shared_ptr <Employee> > companyList;
    // push back shared TeamManager or TeamMember pointers
    for (const auto& employeePtr : companyList) {
        employeePtr->displayInfo(std::cout);
        std::cout << std::endl;
    }
    
    
    
    return 0;
}

