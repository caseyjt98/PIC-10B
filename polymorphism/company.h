//
//  company.h
//  polymorphism
//
//  Created by Casey Taylor on 12/11/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef company_h
#define company_h

#include <iostream> 

class Contact { /*abstract class - cannot construct an instance of this class */
private:
    /* static means that there is only one such variable to be shared among all instances of these classes, with identical value. initialized before main routine
     */
    static size_t max_id; // private, so only accessible by Contact class

protected: // all derived class can access protected members
    std::string name;
    size_t ID;
    
public:
    // size_t getMaxId() { return max_id=1;} // returns maximum possible ID

    Contact(const std::string& theName); // default constructor takes in name and assigns ID
    
    Contact(std::istream& in); // read in info from stream
    
    // accessor to be implemented by derived classes, but not here
    virtual void displayInfo(std::ostream&) const = 0; // pure virtual function
    
    std::string getName() const {return name;} // returns the name
    
    size_t getID() const {return ID;} // returns ID
    
    
    virtual ~Contact() = default; // default destructor, tells compiler to do what it would normally do to clean up contact
    
};


/* public inheritance transfers over public and protected from base to derived. private members of base remain inaccessible to derived class */

class Employee: public Contact {
public:
    Employee(const std::string& theName, const std::string& theOffice); // derived class onstructor, base class constructor is called first
    
    /* explicit keyword indicates that the constructor must be called directly, not via copy initialization */
    explicit Employee(std::istream& in); // reads in info from stream
    
    virtual ~Employee(){} // destructor, empty body is same as default
    
    // displays name and employee info
    virtual void displayInfo(std::ostream& out) const;
    
protected:
    std::string office;
    
};

class TeamMember: public Employee {
public:
    // constructor
    TeamMember (const std::string&, const std::string&, const std::string&, double); // takes in name, office, team, and wage. also generates ID
    
    explicit TeamMember(std::istream&); // reads info from stream
    
    virtual void displayInfo(std::ostream&) const;
    
    double chequeAmount() const; // money on check
    
    void setHours(int); // set hours worked
    
    void setWage(double); // set wage
    
    virtual ~TeamMember() = default;
    
protected:
    
private: // only need to be accessed by TeamMember class
    double wage; // hourly wage
    int hours; // hours worked
    std::string team;
    
};


class TeamManager : public Employee {
public:
    TeamManager(const std::string& name, const std::string& office, double annualSalary): Employee(name,office), salary(annualSalary){}
    
    // suppose that each object should store a list of teams to manage, included in displayInfo
    void displayInfo(std::ostream& out) const {
     out << "Name: " + name + "-Employee-" + office + "(" + team + "," + teamsManaged + ")";
    }
protected:
private:
    double salary;
    std::string teamsManaged;
    std::string team;
};











#endif /* company_h */
