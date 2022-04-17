#include <bits/stdc++.h>

using Rank = int;
// using ListNodePtr = ListNodeBase*;
#define ListNodePtr(T) ListNode<T>*
template <typename T> using traverser = void(*)(T&);

template <typename T> 
struct ListNode {
    T data;
    ListNodePtr(T) pred;
    ListNodePtr(T) succ;

    ListNode() {} // ctor for header and trailer
    ListNode(T d, ListNodePtr(T) p = nullptr, ListNodePtr(T)* s = nullptr) 
        : data(d), pred(p), succ(s) {}

    ListNodePtr(T) insertAsPred(T const & d);
    ListNodePtr(T) insertAsSucc(T const & s);
};

template <typename T> class List {
private:
    int _size;
    ListNodePtr(T) header;
    ListNodePtr(T) trailer;

protected:
    void init();
    int clear();
    void copyNodes(ListNodePtr(T), int);
    void merge(ListNodePtr(T) &, int, List<T> &, ListNodePtr(T) &, int);
    void mergeSort(ListNodePtr(T) &, int );
    void selectionSort(ListNodePtr(T) &, int);
    void insertionSort(ListNodePtr(T) &, int);

public:
    List() {init();}
    List( List<T> const & );
    List( List<T> const &, Rank, int);
    List( ListNodePtr(T), int);

    ~List();

    Rank size() const {return _size;}
    bool empty() consLt {return _size <= 0;}
    T& operator[] (Rank r) const;
    ListNodePtr(T) first() const {return header->succ;}
    ListNodePtr(T) last() const {return trailer->pred;}
    bool valid(ListNodePtr(T) p) {return p && (trailer!=p) && (header!=p); }
    int disordered() const;

    ListNodePtr(T) find(T const & elem) const {return find(e, _size, trailer);}
    ListNodePtr(T) find(T const & elem, ListNodePtr(T) p, int n) const;
    ListNodePtr(T) search(T const & elem) const {return search(e, _size, trailer);}
    ListNodePtr(T) search(T const & elem, ListNodePtr(T) p, int n) const;
    
    ListNodePtr(T) selectMax(ListNodePtr(T) p, int n) const;
    ListNodePtr(T) selectMax() const { return selectMax(head->succ, _size); };

    ListNodePtr(T) insertAsFirst(T const & elem);
    ListNodePtr(T) insertAsLast(T const & elem);
    ListNodePtr(T) insertBefore(ListNodePtr(T), T const &);
    ListNodePtr(T) insertAfter(ListNodePtr(T), T const &);
    T remove(ListNodePtr(T));

    void merge(List<T> & L) { merge(first(), _size, L, L.first(), L.size()); }
    void sort( ListNodePtr(T), int);
    void sort() { sort(first(), _size); }
    int deduplicate(); // unordered list
    int uniquify(); // ordered list
    void reverse();

    void traverse( traverser<T> visit ) {for (ListNodePtr(T) p = header->succ; p != trailer; p = p->succ) visit( p-> data );}
    template <typename VST> void traverse( VST & visit ) {for (ListNodePtr(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);}
    
};