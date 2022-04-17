#include <stdlib.h>
#include <iostream>
#define Operand int
#define Operator char
using namespace std;

class VarBinNode {   
public:
  virtual bool isLeaf() = 0;
  virtual void trav() = 0;
};

class LeafNode : public VarBinNode {
private:
  Operand var; 
public:
  LeafNode(const Operand& val)
    { var = val; }
  bool isLeaf() { return true; }
  Operand value() { return var; }
  void trav() { cout << "Leaf: " << value() << endl; }
};

class IntlNode : public VarBinNode {
private:
  VarBinNode* lc;   // Left child
  VarBinNode* rc;   // Right child
  Operator opx;     // Operator value
public:
  IntlNode(const Operator& op,
           VarBinNode* l, VarBinNode* r)
    { opx = op; lc = l; rc = r; }
  bool isLeaf() { return false; }
  VarBinNode* left() { return lc; } 
  VarBinNode* right() { return rc; } 
  Operator value() { return opx; }
  void trav() {
    if (left() != NULL) left()->trav();
    cout << "Internal: " << value() << endl;
    if (right() != NULL) right()->trav();
  }
};
