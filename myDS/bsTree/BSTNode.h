#ifndef _BSTNODE__H
#define _BSTNODE__H

#include "binaryNode.h"

/* definition of a binary search tree node */
template <typename T, typename key_T>
class BSTNode : public Node {
    private:
        key_T key; // The node's key
        T value; // The node's value
        BSTNode* lc; // The node's left child
        BSTNode* rc; // The node's right child
    
    public:
        // Constructor -- with or without initial values
        BSTNode() { lc = rc = nullptr; }
        BSTNode(key_T k, T e, BSTNode* l = nullptr, BSTNode* r = nullptr) :
            key(k), it(e), lc(l), rc(r) {};
        ~BSTNode() {}; // Destructor

        // Setter & Getter
        T& element() {return value;}
        void setElement (const E & v) {value = v;}
        key_T& key() {return key;}
        void setKey(const key_T & k) {key = k;}
        BSTNode* left() const {return lc;}
        void setLeft(BSTNode* n) {lc = n;}
        // above in book is setLeft(BinNode<T>* b) {lc = (BSTNode*)b;}
        BSTNode* right() const {return rc;}
        void setRight(BSTNode* n) {rc = n;}

        // is Leaf
        bool isLeaf() {retrun (lc==nullptr) && (rc==nullptr);}
};

#endif