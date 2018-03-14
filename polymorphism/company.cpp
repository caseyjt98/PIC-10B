//
//  company.cpp
//  polymorphism
//
//  Created by Casey Taylor on 12/11/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include <stdio.h>
#include "company.h"



// assign name, assign ID to max_id value and increment the static value for future contacts
Contact::Contact(const std::string& theName): name(theName), ID(max_id++){}


// read in info from stream in format [NAME] [TAB] [ID]
Contact::Contact(std::istream& in){
    std::getline(in,name,'\t'); // read up until tab and remove it
    in >> ID; // read in id
}

// passes name to base class for construction, sets office
Employee::Employee(const std::string& theName, const std::string& theOffice): Contact(theName), office(theOffice){}

Employee::Employee(std::istream& in): Contact(in) {
    // contact reads in [NAME][TAB][ID]
    // left with [TAB][OFFICE][TAB]
    in.ignore(); // remove tab
    std::getline(in,office,'\t'); // read in office, remove tab
}

// displays name and employee info
void Employee::displayInfo(std::ostream& out) const{
    out << "Name: " + name + "-Employee-" + office; // name is accessible here because it is protected in base
}


// passes name and office to employee (which will pass name to Contact constructor), sets team and wage, sets hours to 0
TeamMember::TeamMember(const std::string& theName, const std::string& theOffice, const std::string& theTeam, double theWage): Employee(theName, theOffice), team(theTeam), wage(theWage), hours(0){}

TeamMember::TeamMember(std::istream& in): Employee(in), hours(0) { // still needs to set hours to 0!
    // contact reads in [NAME][TAB][ID]
    // employee reads in [TAB][OFFICE][TAB]
    // left with [TEAM][TAB][WAGE][TAB]
    std::getline(in,team,'\t'); // read in team and remove tab
    in >> wage; // read in wage

}

// displays name, employee status, office, team
void TeamMember::displayInfo(std::ostream& out) const {
    out << "Name: " + name + "-Employee-" + office + "(" + team + ")";
}

// returns amount of teamMember check
double TeamMember::chequeAmount() const {
    return hours*wage;
}

// set hours worked
void TeamMember::setHours(int hrs){
    hours = hrs;
}
// set wage
void TeamMember::setWage(double theWage){
    wage = theWage;
}







