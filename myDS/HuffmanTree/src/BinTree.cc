#include "../include/BinTree.hh"

template <typename T>
BinNodePtr(T) BinNode<T>::insertAsLC(T const & elem) 
{
    return lc = new BinNode(elem, this);
}

template <typename T>
BinNodePtr(T) BinNode<T>::insertAsRC(T const & elem) 
{
    return rc = new BinNode(elem, this);
}

# TODO: finish traversal methods
template <typename T, typename VST>
void BinNode<T>::travIn( VST & visit)
{
    switch( rand() % 5 ){
        case 1: travIN_I1 (this, visit); break;
        case 2: travIN_I2 (this, visit); break;
        case 3: travIN_I3 (this, visit); break;
        case 4: travIN_I4 (this, visit); break;
        default : travIN_R (this, visit); break;
    }
}

