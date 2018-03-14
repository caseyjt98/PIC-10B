//
//  LinkedList.cpp
//  homework7
//
//  Created by Casey Taylor on 11/20/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

/*
 I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
 I did not copy code from anyone, student or otherwise.
 I collaborated with SANJAY SHUKLA and KIANA MILLS and I affirm that we all contributed equally in the code.
 */

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"


using namespace std;

namespace pic10b {
    

// LINKED LIST IMPLEMENTATIONS
    
    /* This function default constructs a LinkedList object, creating an empty list null first and last 
     @param void
     */
    LinkedList::LinkedList() : first(nullptr), last(nullptr) {} // empty list with null first and last
    
    
    /* This function contructs a node, storing an integer value with pointers set to null on either side
     @param int _val is the inputted integer value stored by the node
     */
    node::node(int _val) : val(_val), prev(nullptr), next(nullptr) {} // node stores value but points to null on either side
    
    
    /* This function constructs an iterator, setting the currently pointed to node and the LinkedList container
     @param node* n is the dereferenced node to which the iterator points
     @param LinkedList* ell is the derefenced container to which the iterator points
     */
    iterator::iterator(node* n, const LinkedList* ell) : curr(n), container(ell) {} // iterator references node n for list ell
    
    
    /* This function constructs a constant iterator, setting the currently pointed to node and the LinkedList container
     @param node* n  is the dereferenced node to which the const iterator points
     @param LinkedList* ell is the derefenced container to which the const iterator points
     */
    const_iterator::const_iterator(node* n, const LinkedList* ell): curr(n),container(ell) {} // const iterator references node n for list ell

    
    /* This function overloads the output operator, displaying all elements of the list with spaces between them
     @param &output is a reference to the output stream
     @param &ell is a reference to the linked list being printed via the output stream
     @returns the ouput stream
     */
    std::ostream &operator<<(std::ostream &output, const LinkedList &ell){
            node *n = ell.first; // start at first node
            while (n != nullptr) { // while not past the end denoted by nullptr
                node *temp = n->next; // temporarily store the next position
                output << n->val << " "; // add each value to ouput stream
                n = temp; // move n right
            }
        return output;
    }

    
    /* This function sort elements in the list in ascending order from beginning to end
    @param void, but takes in a linked list object implicitly as a member function
    @returns void
     */
    void LinkedList::sort(){
    
        size_t numOfSortedItems = 0; // initialize number of sorted elements to 0
        iterator itr1 = begin(); // initialize iterator one to first element
        while(numOfSortedItems != sz){ // while num of sorted items does not equal size of list
            iterator itr2 = begin(); // set second iterator to first element
            
            for(size_t i = 0; i < numOfSortedItems; i++){
                itr2++; // increment iterator to start at unsorted items
            }
            //number of elements compared
            int count = 1; // initialize count to 1
            
            while(count < (sz-numOfSortedItems)){
                itr2++; // increment second iterator
                if (*itr1 > *itr2){ // if first element is greater than second element
                    //swap first and second element in list
                    int temp = *itr2;
                    itr2.curr->val = *itr1;
                    itr1.curr->val = temp;
                } // otherwise values already in ascending order or equal
                count++; // increment count
            }
            numOfSortedItems++; // increment number of sorted items
            if(numOfSortedItems != sz){ itr1++;} // if within bounds of list, increment iterator one
        }
        
    }
    
    /* This function obtains a const begin iterator
     @param void
     @returns a const_iterator constBeginIt pointing to first element
     */
    const_iterator LinkedList::begin() const{
        const_iterator constBeginIt(first, this);
        return constBeginIt;
    }
    
    /* This function obtains a const iterator pointing past end
     @param void
     @returns a const_iterator constEndIt pointing to past the last element
     */
    const_iterator LinkedList::end() const{
        const_iterator constEndIt(last->next, this);
        return constEndIt;
    }
    
    
    /* This function obtains a begin iterator
     @param void
     @returns an iterator beginIt pointing to first element
     */
    iterator LinkedList::begin(){
        iterator beginIt(first, this);
        return beginIt;
    }

    /* This function obtains iterator pointing past end
     @param void
     @returns aa iterator endIt pointing past the last element
     */
    iterator LinkedList::end(){
        iterator endIt(last->next, this);
        return endIt;
    }
  
    
    /* This function overloads the assignment operator
     @param that is the first LinkedList, note that second parameter is implicitly the member object itself
     @returns a reference to LinkedList object
     */
    LinkedList& LinkedList::operator=(LinkedList that){
        swap(*this,that); //set the lists equal to each other using swap
        return *this;
    }
    
    /* This function directly swaps the pointers of two linked lists
     @param one is a reference to the first LinkedList being swapped
     @param two is a reference to the second LinkedList being swapped
     @returns void
     */
    void swap(LinkedList& one, LinkedList& another){
        std::oswap(one.first, another.first); // swap first pointers
        std::oswap(one.last, another.last); // swap last pointers
    }
    
    /* This function is the copy constructor, copying elements over one by one
     @param rhs is a const reference to the LinkedList being copied
     */
    LinkedList::LinkedList(const LinkedList& rhs) : first(nullptr), last(nullptr) {
        for (auto itr = rhs.begin(); itr != rhs.end(); ++itr) {
            push_back(*itr);
            std::cout << "list 2: " << *this << endl;
        }
    }
    
    /* This function is the move constructor, taking pointers to first and last then setting rhs pointers to null so it is in valid destructible state 
     @param &&rhs is the LinkedList being moved
     */
    LinkedList::LinkedList(LinkedList&& rhs) : first(rhs.first), last(rhs.last) {
        rhs.first = rhs.last = nullptr;
    }
    
    
    /* This function appends an element to the end of the linked list
     @param val is the integer element being added
     */
    void LinkedList::push_back(int val){
        node *n = new node(val); // create a new node
        if (last) { // if last node not null
            last->next = n; // make last point to n
            n->prev = last; // make n have last as its previous
            last = n; // update the last position
        }
        else { // in this case the last node is null so list is empty
            first = last = n; // both equal to n
        }
        sz++; //increment size
    }
    
    /* This function adds an element to the beginning of the linked list
     @param val is the integer element being added
     */
    void LinkedList::push_front(int val){
        node *n = new node(val); // create a new node
        if (first) { // if first node not null
            first->prev = n; // make first point to n
            n->next = first; // make n have first as its next
            first = n; // update the last position
        }
        else { // in this case the last node is null so list is empty
            last = first = n; // both equal to n
        }
        sz++;  //increment size

    }
    
    
    /* This function removes an element from the beginning, throwing an exception if the list is empty
     @param void
     @returns void
     */
    void LinkedList::pop_front(){
        if (!last) { // list is empty if last null
            throw std::logic_error("pop back on empty list"); //throw exception
        }
        else if (first == last){ // if just one element
            delete first; // free heap memory
            first = last = nullptr; // make both null because empty again
        }
        else {
            node *newfirst = first->next; // store the new first node
            newfirst->prev = nullptr; // set its prev pointer to null
            delete first; // free the heap memory
            first = newfirst; // update the first value
        }
        sz--;

    }
    
    /* This function removes an element from the end, throwing an exception if the list is empty
     @param void
     @returns void
     */
    void LinkedList::pop_back(){
        if (!last) { // list is empty if last null
            throw std::logic_error("pop back on empty list"); //throw exception
        }
        else if (first == last){ // if just one element
            delete first; // free heap memory
            first = last = nullptr; // make both null because empty again
        }
        else {
            node *newlast = last->prev; // store the new last node
            newlast->next = nullptr; // set its next pointer to null
            delete last; // free the heap memory
            last = newlast; // update the last value
        }
        sz--;
    }
    
    /* This function inserts a value before current position
     @param it is the iterator pointing to the current position
     @param val is the integer value being added
     */
    void LinkedList::insert(iterator it, int val) {
        if (it.curr == nullptr) { // then inserting before past-the-end
            push_back(val);
        }
        else if (it.curr == first) { // then at beginning
            push_front(val);
        }
        else{ // then in middle
            node *n = new node(val); // create new node
            n->next = it.curr; // set n’s next
            n->prev = it.curr->prev; // set n’s previous
            it.curr->prev->next = n; // make current previous’ next node into n
            it.curr->prev = n; // make current previous node into n
            sz++;
        }
    }
    
    /* This function erases a value at specified position
     @param it is the  iterator pointing to the specified position
     */
    void LinkedList::erase(iterator it) {
        if (it.curr == first) { // removing first
            pop_front(); // remove first
        }
        else if (it.curr == last) { // removing last
            pop_back(); // remove last
        }
        else {
            it.curr->prev->next = it.curr->next; // reroute next of previous
            it.curr->next->prev = it.curr->prev; // reroute previous of next
            delete it.curr; // free the heap memory of item being removed
            sz--;
        }
    }
    
    /* This function is the destructor for a linked list object, dealing with the deletion of heap memory
     @param void
     @returns void
     */
    LinkedList::~LinkedList() {
        node *n = first; // start at first node
        while (n != nullptr) { // while not past the end denoted by nullptr
            node *temp = n->next; // temporarily store the next position
            delete n; // delete the node on heap
            n = temp; // move n right
        }
    }
    
// ITERATOR IMPLEMENTATIONS
    
    /* This function overloads the prefix operator--, which decrements the position of an iterator
    @returns iterator to previous element
    */
    iterator& iterator::operator--(){
        if(curr == container->first) { // cannot go before first
            throw std::logic_error("Invalid address");
        }
        else if(curr == nullptr) { // just past the end, go to last
            curr = container->last; // now make iterator refer to last element
        }
        else {
            curr = curr->prev; // reference previous node
        }
        return *this;
    }
    
    /* This function overlaods the postfix operator--
     @param int is unused
     @returns a copy of the iterator object
     */
    iterator iterator::operator--(int) {
        iterator copy(*this); // copy object
        --(*this); // increment object
        return copy; // return copy of object
    }
    
    /* This function overloads the prefix operator++, which increments the position of an iterator
     @returns iterator to next element
     */
    iterator& iterator::operator++(){
        if (curr == container->last) { // cannot go beyond last
            throw std::logic_error("Invalid address");
        }
        else if (curr == nullptr) { // just before first element, go to first
            curr = container->first; // make iterator refer to first element
        }
        else {
            curr = curr->next; // reference next node
        }
        return *this;
    }
    
    /* This function overlaods the postfix operator++
     @param int is unused
     @returns a copy of the iterator object
     */
    iterator iterator::operator++(int) {
        iterator copy(*this); // copy object
        ++(*this); // increment
        return copy; // return copy of object
    }
    
    /* This unary function dereferences an iterator
     @param void
     @returns a reference to the integer element being pointed to by the iterator
     */
    int& iterator::operator*(){
        return curr->val; // return reference to the int stored
    }
    
    
    /* This function overloads the comparison operator==, which checks for equality between two iterators
     @param rhs is a reference to the first iterator being compared
     @param is implicitly the member object, the second iterator being compared
     @returns bool, true if the iterators are equal
     */
    bool iterator::operator==(const iterator& rhs) const {
        return ( (curr == rhs.curr) && (container == rhs.container) );
    }
    
    /* This function overloads the conversion operator from iterator to const iterator
     @param void
     @returns a converted const_iterator
     */
    iterator::operator const_iterator() const {
        return const_iterator(curr, container);
    }
    
    
    /* This function overloads the negation operator, which tests the inequality of two iterators
     @param first is a reference to the first iterator being compared
     @param second is a reference to the second iterator being compared
     @returns bool, true if the two iterators are unequal
    */
    bool operator!=(const iterator& first, const iterator& second){
        return !(first == second);
    }
    
    /* This function overloads the negation operator, which tests the inequality of two constant iterators
     @param first is a reference to the first const iterator being compared
     @param second is a reference to the second const iterator being compared
     @returns bool, true if the two const iterators are unequal
     */
    bool operator!=(const const_iterator& first, const const_iterator& second){
        return !(first == second);
    }
    
    
// CONST ITERATOR IMPLEMENTATIONS
    
    /* This unary function dereferences a constant iterator
     @param void
     @returns a reference to the integer element being pointed to by the const iterator
     */
    const int& const_iterator::operator*() const {
        return curr->val; //return copy of the int stored
    }
    
    /* This function overloads the comparison operator==, which checks for equality between two constant iterators
     @param rhs is a reference to the first const iterator being compared
     @param is implicitly the member object, the second const iterator being compared
     @returns bool, true if the const iterators are equal
     */
    bool const_iterator::operator==(const const_iterator& rhs) const {
        return ( (curr == rhs.curr) && (container == rhs.container) );
    }
    
    /* This function overloads the prefix operator++, which increments the position of a constant iterator
     @returns a constant iterator to next element
     */
    const_iterator& const_iterator::operator++(){
        if (curr == container->last->next) { //cannot go out of bounds of list
            throw std::logic_error("Invalid address");
        }
        else if (curr == nullptr) { //just before first element, go to first
            curr = container->first; //make iterator refer to first element
        }
        else {
            curr = curr->next; //reference next node
        }
        return *this;
    }
    
    /* This function overlaods the postfix operator++
     @param int is unused
     @returns a copy of the constant iterator object
     */
    const_iterator const_iterator::operator++(int){
        const_iterator copy(*this); // copy object
        ++(*this); // increment
        return copy; // return copy of object}
    }
    
    /* This function overloads the prefix operator--, which decrements the position of a constant iterator
     @returns constant iterator to previous element
     */
    const_iterator& const_iterator::operator--(){
        if(curr == container->first) { // cannot go before first
            throw std::logic_error("Invalid address");
        }
        else if(curr == nullptr) { // just past the end, go to last
            curr = container->last; // now make iterator refer to last element
        }
        else {
            curr = curr->prev; // reference previous node
        }
        return *this;
    }
    
    /* This function overlaods the postfix operator--
     @param int is unused
     @returns a copy of the constant iterator object
     */
    const_iterator const_iterator::operator--(int){
        const_iterator copy(*this); // copy object
        --(*this); // increment object
        return copy; // return copy of object
    }
    
    
    /* This function should search over the range provided by the iterators from the first up to but not including the second iterator.
     @param first is the const iterator marking the beginning of the search range
     @param first is the const iterator marking the end of the search range (non inclusive)
     @param val is the value being searched for
     @returns bool, true is the sought value is found. Otherwise, false.
     */
     //bool SeqSearch(const_iterator first, const_iterator past_end, int val){}
     
     
} //close namespace






