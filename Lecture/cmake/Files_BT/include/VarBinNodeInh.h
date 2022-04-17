#include <stdlib.h>
#include <iostream>
#define Operand int
#define Operator char
using namespace std;

class VarBinNode {  
public:
  virtual bool isLeaf() = 0;
};

class LeafNode : public VarBinNode { 
private:
  Operand var;       
public:
  LeafNode(const Operand& val){ var = val; }
  bool isLeaf() { return true; }
  Operand value() { return var; }
};

// Internal node
class IntlNode : public VarBinNode {
private:
  VarBinNode* left;     // Left child
  VarBinNode* right;    // Right child
  Operator opx;         // Operator value
public:
  IntlNode(const Operator& op,
           VarBinNode* l, VarBinNode* r)
    { opx = op; left = l; right = r; }
  bool isLeaf() {return false;}
  VarBinNode* leftchild() {return left;}
  VarBinNode* rightchild() {return right;} 
  Operator value() { return opx; }
};


