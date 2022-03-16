#ifndef _BINNODE__H
#define _BINNODE__H

template <typename T>
using BinNodePosi = BinNode<T>*;

#define stature(p) ((p) ? (p)->height: -1)
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lchild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rchild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lchild)
#define HasRChild(x) ((x).rchild)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!(HasChild(x)))

#define sibling(p)
    (IsLChilf)


typedef enum { RB_RED, RB_BLACK} RBColor;

template <typename T> struct BinNode {
    // members, for simplification we set them to public
    T data;
    BinNodePosi(T) parent; BinNodePosi(T) lchild; BinNodePosi(T) rchild;
    int height;
    int npl; // Null path Length
    RBcolor color;
    // constructor
    BinNode():
        parent(nullptr), lchild(nullptr), rchild(nullptr), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED ) :
        date(e), parent(p), lchild(lc), rchild(rc), height(h), npl(l), color(RBColor) {}
    // operation interface
    int size();
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();
    template <typename VST> void travLevel(VST&);
    template <typename VST> void travPre(VST&);
    template <typename VST> void travIn(VST&);
    template <typename VST> void travPost(VST&);
    // comparator, equator
    bool operator< (BinNode const& bn) {return data < bn.data;}
    bool operator== (BinNode const& bn) {return data == bn.data;}
};

#endif