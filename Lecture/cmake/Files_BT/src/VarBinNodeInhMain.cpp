#include "VarBinNodeInh.h"

// Inorder traversal
void traverse(VarBinNode *subroot) {
  if (subroot == NULL) return; // Empty
  if (subroot->isLeaf())    // Do leaf node
    cout << "Leaf: "
         << ((LeafNode *)subroot)->value()
         << endl;
  else {                // Do internal node
    
    traverse(
		 ((IntlNode *)subroot)->leftchild());
    cout << "Internal: "
         << ((IntlNode *)subroot)->value()  
         << endl;
    traverse(
		 ((IntlNode *)subroot)->rightchild());
  }
}

int main()
{
    LeafNode* A = new LeafNode(2);
	LeafNode* B = new LeafNode(3);
	IntlNode* C = new IntlNode('+', A, B);
    traverse(C);
    return 0;
}