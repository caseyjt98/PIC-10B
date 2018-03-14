//
//  BinarySearchTree.h
//  Homework8
//
//  Created by Casey Taylor on 11/28/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <iostream>


namespace pic10b {

/* @class Tree
 @brief stores the properties and functions of a binary search tree
 */
class Tree {
private:
    class node; // nested node class
    node* root; // pointer references root of the tree
    void deleteTree(node*); // to recursively delete the tree
    void traverseInsert(node*); // to help with copying
    size_t sz; // number of elements in tree
    
public:
    class iterator; // nested iterator class
    Tree(); // default constructor for empty tree
    ~Tree(); // destructor 
    Tree(const Tree&); // copy constructor
    Tree(Tree&&); // move constructor
    Tree& operator=(Tree); // assignment operators 
    void insert(const double& val); // adds value to the tree
    void erase(iterator); // erases node managed by the iterator from the tree
    iterator begin() const; // iterator to begin position
    iterator end() const; // iterator to past-the-end position
    size_t size() { return sz; } // returns number of elements in tree
    iterator find(const double& val) const; // returns iterator for found value or returns null
    friend void swap(Tree& first, Tree& second); // swap two Trees
    
   
};

/* @class node
 @brief stores the properties and functions of a node within a binary search tree
*/
class Tree::node {
    friend Tree; // tree member functions may search through nodes
    friend iterator; // to be able to advance by checking node values
private:
    node(const double&); // constructor
    node* left; // left child
    node* right; // right child
    node* parent; // parent node
    double val; // data value stored
    bool insertNode(node*); // member function for inserting node
    //  bool is used to check if valid to know whether or not to update size
};


/* @class iterator
 @brief stores the properties and functions of an iterator within a binary search tree
*/
class Tree::iterator {
    friend Tree; // allows iterator modifications by Tree operations
private:
    iterator(node*, const Tree*); // iterator constructor
    node* curr; // pointer to current position
    const Tree *container; // holding container
public:
    iterator &operator++(); // prefix ++
    iterator operator++(int); // postfix ++
    const double& operator*() const; // dereferencing operator
    const double* operator->() const { return &(curr->val); } // arrow operator
    bool operator==(const iterator& rhs) const; // comparison operator
};

    bool operator!=(const Tree::iterator& lhs, const Tree::iterator& rhs);


} // end namespace






#endif /* BinarySearchTree_h */
