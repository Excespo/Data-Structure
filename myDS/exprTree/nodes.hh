#ifndef _NODES__H
#define _NODES__H

#include <iostream>
#include <string>
#include <vector>

using operand = int;
using operator_ch = char;
typedef enum {
    ADD=0, SUB=1, MUL=2, DIV=3
} op_idx;
const char ops[] = {'+', '-', '*', '/'};

/* Node abstract base class */
class BaseNode {
    public:
        virtual ~BaseNode() {}
        virtual bool isLeaf() = 0;
        virtual void visit() = 0;
};

/* Leaf node, store operands */
class OperandNode: public BaseNode {
    private:
        operand value;
    public:
        OperandNode(cosnt & v) {value = v;}
        bool isLeaf() {return true;}
        void visit() {std::cout << "Leaf: " << value << std::endl;}
        operand val() {return value;} 
};

/* Internal node, store operators */
class OperatorNode: public BaseNode {
    private:
        operator_ch op;
        BaseNode* left;
        BaseNode* right;
    public:
        OperatorNode(const & operator_ch);
        bool isLeaf() {return false;}

};

#endif