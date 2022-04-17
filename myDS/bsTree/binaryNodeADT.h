#ifndef _BINARYNODEADT__H
#define _BINARYNODEADT__H

#include <iostream>

/* definition of tree node ADT */
template <typename T> class Node {
    public:
        // Base destructor
        virtual ~BinNode() {} 

        // Return value of the node
        virtual T& element() = 0;

        // Set the value of the node
        virtual void setElement(const E &) = 0;

        // Return the left child of node
        virtual Node* left() const = 0;

        // Set the left child of node
        virtual void setLeft(Node*) = 0;

        // Return the right child of node
        virtual Node* right() const = 0;

        // Set the right child of node
        virtual void setRight(Node *) = 0;

        // Return bool value of statement - If the node is a leaf
        virtual bool isLeaf() = 0
};

#endif