#define BinNodePtr(T) BinNode<T>*
#define stature(p) ( (p) ? (p)->height: -1)
typedef enum {RB_RED, RB_BLACK} RBColor;

template <typename T> struct BinNode {
    T data; 
    BinNodePtr(T) parent; BinNodePtr(T) lc; BinNodePtr(T) rc;
    int height;
    int npl; // null path length (for left heap)
    RBColor color;

    BinNode():
        parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(0), color(RB_RED) {}
    BinNode(T e, BinNodePtr(T) p = nullptr, BinNodePtr(T) l = nullptr, BinNodePtr(T) r = nullptr,
            int h = 0, int l = 0, RBColor r = RB_RED): 
        data(e), parent(p), lc(l), rc(r), height(h), npl(l), color(r) {}
    
    int size();
    BinNodePtr(T) insertAsLC (T const &);
    BinNodePtr(T) insertAsRC (T const &);
    BinNodePtr(T) succ();
    
    template <typename VST> void travLevel(VST &);
    template <typename VST> void travPre(VST &);
    template <typename VST> void travIn(VST &);
    template <typename VST> void travPost(VST &);

    bool operator< (BinNode const & bn) {return data < bn.data;}
    bool operator> (BinNode const & bn) {return data > bn.data;}
    bool operator== (BinNode const & bn) {return data == bn.data;}

};

/* Status of BinNode */
#define IsRoot(x) ( !(x).parent )
#define IsLChild(x) ( !IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( !IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( !IsRoot(x) )
#define HasLChild(x) ( (x)->lc )
#define HasRChild(x) ( (x)->rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( !HasChild(x) )
/* Specific relation with BinNode */
#define sibling(p) \
    ( IsLChild(*(p)) ? (p)->parent->rc: (p)->parent->lc )
#define uncle(x) \
    ( IsLChild( *((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc )
#define FromParentTo(x) \
    ( IsRoot(x) ? _root :  (IsLChild(x) ? (x).parent->lc : (x)->parent->rc) )