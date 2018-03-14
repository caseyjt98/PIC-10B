//
//  BinarySearchTreeImplementations.cpp
//  Homework8
//
//  Created by Casey Taylor on 11/28/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.

/*
 I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
 I did not copy code from anyone, student or otherwise.
 I collaborated with KIANA MILLS and I affirm that we all contributed equally in the code.
 */

#include <stdio.h>
#include "BinarySearchTree.h"

namespace pic10b {

/* TREE IMPLEMENTATIONS */

/* Default constructor for empty tree, with size of 0 and root pointer set to null
 @param void
 @returns void
 */
Tree::Tree(): root(nullptr), sz(0) {} // set root pointer to null and size to 0
    
    
/* Descructor function frees up memory by deleting the tree, starting at the root
 @param void
 @returns void
 */
Tree::~Tree()
{
    deleteTree(root); // call deleteTree function, starting at the root
}

/* This function uses recursion to delete the binary search tree
 @param n is a pointer to the node being deleted
 @returns void
 */
void Tree:: deleteTree(node* n){
    if (n != nullptr) { // while current node exists
    // delete both subtrees
        if(n->left != nullptr) { // if node has a left child
        deleteTree(n->left); // call function recursively
        }
        if(n->right != nullptr) { // if node has a right child
            deleteTree(n->right); // call function recursively
        }
    delete n;
    n = nullptr;
    }
}


/* This function searches for a value in the tree, returning iterator for found value or returning null
 @param val is a reference to the sought after value 
 @returns iterator is the the iterator for found value (null if not found)
 */
Tree::iterator Tree::find(const double& val) const{
    node* n = root; // start with pointer to root
    
    while (n != nullptr) { // while n is not null
        
        if(n->val == val){ // if value equals sought after value
            return iterator(n,this); // return iterator to found value
        } else { // if current value does not equal sough after value
            if (n->val > val) { // if current value is greater than sought after value
                // go left
                n = n->left;
            }
            else if (n->val < val) { // if current value is less than sought after value
                // go right
                n = n->right;
            }
        }
    }
    // if value is not found
    return iterator(nullptr, this); // return iterator past end
}


/* This function swaps two Trees by swapping their root pointers and size variables
 @param first is a reference to the first Tree being swapped
 @param second is a reference to the second Tree being swapped
 @returns void
 */
void swap(Tree& first, Tree& second) {
    std::swap(first.root, second.root);
    std::swap(first.sz, second.sz);
}

/* This function takes in a double value and adds it to the tree
 @param val is a reference to the double value being added
 @returns void
 */
void Tree::insert(const double& val){
    if (!root) { // if the tree is empty
        root = new node(val); // make a new node and set it to be the root
        ++ sz; // increment size
    }
    else { // tree is not empty
        node *n = new node(val); // create a pointer to a new node
        
        // recursively pass it node to node until in place
        bool successfulInsert = root->insertNode(n);
        
        // successful insertion means that size should be incremented
        if (successfulInsert == true) {
            ++ sz; // increment size
        }
    }
}

/* copy constructor
 @param rhs is a reference to the tree being copied
 @returns void
 */
Tree::Tree(const Tree& rhs): root(nullptr) {
    traverseInsert(rhs.root); // calls a recursive function on nodes to copy
}

/* move constructor
 @param rhs is a reference to the tree being moved
 @returns void
 */
Tree::Tree(Tree&& rhs): root(rhs.root) {
    rhs.root = nullptr; // set root pointer to null
    
}

// assignment operator
Tree& Tree::operator=(Tree that) {
    swap(*this, that);
    return *this;
}


/* This function returns an iterator to begin position, the smallest node value in the tree
 @param void
 @returns iterator to begin position
 */
Tree::iterator Tree::begin() const { // return type requires scope
    if (root == nullptr) { // if root is null then the tree is empty
        return iterator(nullptr, this); // return iterator that is null
    }
    node *n = root; // start with pointer to root
    
    while (n->left != nullptr) { // while we can still go left to a lower value
        n = n->left; // go left
    }
    
    return iterator(n,this); // return iterator for node of smallest value
}

/* This function returns an iterator to past-the-end position, storing null
 @param void
 @returns iterator to past-the-end position
 */
Tree::iterator Tree::end() const { // return type requires scope
    return iterator(nullptr, this); // iterator past end is null
}

/* This function follows a recursive pattern to help with copying
 @param n is a pointer to the node being inserted into the tree through recursion
 @returns void
 */
void Tree::traverseInsert(node* n){
    insert(n->val); // insert value into tree
    
    if (n->left != nullptr) { // if left child exists
        traverseInsert(n->left);
    } // else, do nothing
    
    if(n->right != nullptr) { // if right child exists
        traverseInsert(n->right);
    } // else, do nothing
    
}

/* This function erases a node managed by the iterator from the tree
 @param itr is the iterator managing the node being erased
 @returns void
 */
void Tree::erase(iterator itr){
    if (root != nullptr) { // if the tree is not empty
        
        node* n = itr.curr; // pointer to current node
        double smallestInRightTree; // to replace node value in case 2
    
        
        // case 0: current node has 0 children
        if (n->left == nullptr && n->right == nullptr){
            // check if current node is left or right child of its parent
            if (n == n->parent->right){ // if current node is a right child
                n->parent->right = nullptr; // set to null
            }
            else if (n == n->parent->left){ // if current node is a left child
                 n->parent->left = nullptr; // set to null
            }
            
            delete n; // delete node
            n = nullptr; // set pointer to null
            --sz; // decrement size

        }
        
        // case 1: root node has 1 child
        else if (n->left == nullptr && n->right != nullptr) { // node has right child
            node* temp = n->right; // temporary pointer to right child
            temp->parent = n->parent; // set parent of right child to parent of node
            
            if (n->parent != nullptr && n->parent->val > n->val) { // if parent's value is greater than node's value
                n->parent->left = temp; // set parent's left child to temp
            }
            else if (n->parent != nullptr && n->parent->val <= n->val) { // if parent's value is less than node's value
                n->parent->right = temp; // set parent's right child to temp
            }
            else if (n->parent == nullptr) { // node being deleted is root
                root = temp; // update root pointer
            }
            delete n; // delete old node
            n = nullptr; // set to null
            --sz; // decrement size

        }
        
        else if (n->left != nullptr && n->right == nullptr) { // node has left child
            node* temp = n->left; // temporary pointer to left child
            temp->parent = n->parent; // set parent of left child to parent of node
            
            if (n->parent != nullptr && n->parent->val > n->val) { // if parent's value is greater than node's value
                n->parent->left = temp; // set parent's left child to temp
            }
            else if (n->parent != nullptr && n->parent->val < n->val) { // if parent's value is less than node's value
                n->parent->right = temp; // set parent's right child to temp
            }
            else if (n->parent == nullptr) { // node being deleted is root
                root = temp; // update root pointer
            }
            delete n; // delete old node
            n = nullptr; // set to null
            --sz; // decrement size

        
        }
        
        // case 2: current node has 2 children
        else if (n->left != nullptr && n->right != nullptr) {
            
            node *n = itr.curr->right; // start with pointer to the right child of current node
            
            while (n->left != nullptr) { // while we can still go left to a lower value
                n = n->left; // go left to smallest value in right tree
            }
            
            smallestInRightTree = n->val; // set smallest value in right tree
            
            // override current node value with smallest value in right tree
            itr.curr->val = smallestInRightTree;
           // itr.curr->right = n->right; // set n as new right child
            
            iterator i(n, this);
            
            // delete node with smallest value recursively
            erase(i);
            
            
        }
        
    }
}


/* NODE IMPLEMENTATIONS */


/* This function contructs a node, storing an inputted double value and storing pointers to its parent and left/ right children (initialized to null)
 @param const double& val is the inputted double value stored by the node
 */
Tree::node::node(const double& val): val(val), left(nullptr), right(nullptr), parent(nullptr){}



/* This function inserts a node to the tree using recursion,
 @param n is a pointer to the node being inserted
 @returns bool, true if the insertion was successful (increment size) and false otherwise
 */
bool Tree::node::insertNode(node* n) {
    // if the value is less than the new node value, new node should go to the right
    if (val < n->val) {
        if(right) { // if this node has a right child
            return right->insertNode(n); // recurse on the right child
        } else { // if the right child is null
            n->parent = this;
            right = n; // make this the right child
            return true;
        }
    }
    // if this value is larger than the new node value, new node should go to the left
    else if (val > n->val){
        if(left) { // if this node has a left child
            return left->insertNode(n); // recurse on the left child
        } else { // if the left child is null
            n->parent = this;
            left = n; // make this the left child
            return true;
        }
    }
    // nothing to add if new node is neither < or > current value
    return false;
}





/* ITERATOR IMPLEMENTATIONS */


/* This function constructs an iterator, setting the currently pointed to node and the Tree container
 @param node* n is the node to which the iterator points
 @param Tree* binaryTree is the container to which the iterator points
 */
Tree::iterator::iterator(node* n, const Tree* binaryTree): curr(n), container(binaryTree){}


/* This function overloads the comparison operator==, which checks for equality between two iterators
 @param rhs is a reference to the first iterator being compared
 @param is implicitly the member object, the second iterator being compared
 @returns bool, true if the iterators are equal
 */
bool Tree::iterator::operator==(const iterator& rhs) const {
    return ( (curr == rhs.curr) && (container == rhs.container) );
}

/* This function overloads the negation operator, which tests the inequality of two iterators
 @param first is a reference to the first iterator being compared
 @param second is a reference to the second iterator being compared
 @returns bool, true if the two iterators are unequal
 */
bool operator!=(const Tree::iterator& first, const Tree::iterator& second) {
    return !(first == second);
}

/* This unary function dereferences an iterator
 @param void
 @returns a reference to the integer element being pointed to by the iterator
 */
const double& Tree::iterator::operator*() const {
    return curr->val; // return reference to the int stored
}


/* This function overloads the prefix operator++, which increments the position of an iterator 
 @returns iterator to next element *INCOMPLETE*
 */
 Tree::iterator& Tree::iterator::operator++(){
     
     if (curr->right != nullptr) { // if current node has a right child
         curr = curr->right; // move to right child
         // now go as far left as possible
         while(curr->left != nullptr) { // while we can still go left
             curr = curr->left; // go left
             
         }
     }

     else { // if current node does not have a right child
    
         // move up through parent nodes until one of those upward moves takes us further right
             
         if (curr->parent != nullptr) { // if current node has a parent (it is not the root)
             // if the current node is a left child of its parent
             if(curr == curr->parent->left) {
                 curr = curr->parent; // move pointer to parent of current node
             }
                 
             // if the current node is a right child of its parent
             else if (curr == curr->parent->right) {
                     
                 curr = curr->parent; // move pointer to parent node
                     
                 while(curr->parent != nullptr && curr == curr->parent->right) { // while parent exists and node is the right child of the parent
                     curr = curr->parent; // keep moving up - move to parent
                 }
    
                 if(curr->parent == nullptr) { // if current node has no parent
                     curr = nullptr; // return nullptr
                     
                 } else { // current node is not null
                     curr = curr->parent;
                 }
             }
             
         } else { // if current node has no parent
             curr = nullptr;
         }
             
     }
     
        return *this;
}
                   
 /* This function overlaods the postfix operator++
 @param int is unused
 @returns a copy of the iterator object
 */
 Tree::iterator Tree::iterator::operator++(int) {
 iterator copy(*this); // copy object
 ++(*this); // increment
 return copy; // return copy of iterator object
 }
 
}

