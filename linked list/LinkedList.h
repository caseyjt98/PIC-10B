//
//  LinkedList.h
//  homework7
//
//  Created by Casey Taylor on 11/20/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>


namespace std {
    
    /* 
     Function swaps to objects of type T
     @tparam T the type of the two objects
     @param first the first argument
     @param second the second argument
     */
    template<typename T>
    void oswap(T& first, T& second){
        T temp (std::move(first));
        first = std::move(second);
        second = std::move(temp);
    }
}

namespace pic10b {
    
    class node; // declare the node
    class iterator; // declare a normal iterator
    class const_iterator; // declare an iterator to work on const LinkedLists
    
    // Linked List Class
    class LinkedList{
        
        friend iterator; // iterators need to know first element
        friend const_iterator;
        friend void swap(LinkedList&, LinkedList&); // to swap two LinkedLists
        
    private:
        node *first, *last; // pointers to first and last nodes
        size_t sz = 0;
        
    public:
        LinkedList(); // default constructor to start empty
        LinkedList(const LinkedList&); // copy constructor copies over elements one by one
        LinkedList(LinkedList&&); // move constructor ensures that the pointers are in a descructible state
        ~LinkedList(); // destructor
        LinkedList& operator=(LinkedList); // assignment operators 
        const_iterator begin() const; // obtain const begin iterator
        const_iterator end() const; // obtain const iterator pointing past end
        iterator begin(); // obtain begin iterator
        iterator end(); // obtain iterator pointing past end
        void insert(iterator, int); // insert value before current position
        void erase(iterator); // erase value at position
        void push_back(int); // append to end
        void pop_back(); // remove from the end, throwing an exception if the list is empty
        void push_front(int); // add to beginning
        void pop_front(); // remove from beginning, throwing an exception if the list is empty
        size_t size() {return sz;}; // retrieve number of elements in list
        void sort(); //sort elements in ascending order from beginning to end;
        friend std::ostream &operator<<(std::ostream &output, const LinkedList &ell); //output operator
        
    };
    
    // Node Class
    class node{
        
        friend LinkedList; //LinkedList needs to construct nodes and to know next/prev of node        for insertions, deletions, etc.
        friend iterator; // iterators need to know next/prev to move, etc.
        friend const_iterator;
        friend std::ostream &operator<<(std::ostream &output, const LinkedList &ell); //output operator
        
    private:
        int val; // the data
        node *prev, *next; // previous and next nodes
        node(int i); // constructor to create new node is PRIVATE, so only its friends can construct a node
    };
    
    
    // Iterator Class
    class iterator{
        
        // LinkedList may change data of iterator during operations
        friend LinkedList; //private constructor
        friend node;
        
    
        
    public:
        iterator& operator++(); // prefix ++
        iterator operator++(int); // postfix ++
        iterator& operator--(); // prefix - -
        iterator operator--(int); // postfix - -
        int& operator*(); // dereferencing operator (unary)
        bool operator==(const iterator&) const; // comparison
        operator const_iterator() const; //conversion operator
        
    private:
        node *curr; // currently managed node
        const LinkedList *container; // the iterator should not change the list
        // constructor: requires a node and list to point to
        iterator(node*, const LinkedList*);
    };
    
    // != defined by negating ==
    bool operator!=(const iterator&, const iterator&);
    
    
    
    // Const Iterator Class
    class const_iterator{
        // LinkedList may change data of iterator during operations
        friend LinkedList;
        friend node;
        friend iterator;
        
        
    public:
        const_iterator& operator++(); // prefix ++
        const_iterator operator++(int); // postfix ++
        const_iterator& operator--(); // prefix - -
        const_iterator operator--(int); // postfix - -
        const int& operator*() const; // dereferencing operator (unary)
        bool operator==(const const_iterator&) const; // comparison
        
    private:
        node *curr; // currently managed node
        const LinkedList *container; // the iterator should not change the list
        const_iterator(node*, const LinkedList*); //constructor requires a node and list to point to
    };
    
    // != defined by negating ==
    bool operator!=(const const_iterator&, const const_iterator&);
    
    
    
    bool SeqSearch(const_iterator first, const_iterator past_end, int val);
}



#endif /* LinkedList_h */
