#include "VarBinNodeComp.h"
// Inorder traversal
void traverse(VarBinNode *root) {  
  if (root != NULL)
    root->trav();
}


int main()
{
    LeafNode* A = new LeafNode(2);
	LeafNode* B = new LeafNode(3);
	IntlNode* C = new IntlNode('+', A, B);
    traverse(C);
    return 0;
}