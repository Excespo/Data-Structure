#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

template <typename keyType, typename valType> class HashTable {
private:
    int _table_max_size = 1631;
    int _using_size;
    // bool sanity_check() { return _keys.size() == _vals.size(); }
    int exist(keyType k);
    void probe(keyType & k, valType & v);
    keyType val2int(valType v);
    keyType hash1(keyType* ks, int n);
    
public:
    std::vector<keyType> _keys; // stores the hash value(being the key of value)
    std::vector<valType> _vals;
    HashTable() { _using_size = 0; }
    int size() { return _using_size; }
    void insert(keyType & k, valType & v);
    keyType hash_half(keyType* ks, int n);
    keyType hash(valType* vs, int n);

};


class IntCompare{
public:
        static bool lt(int x, int y){ return x < y; }
        static bool eq(int x, int y){ return x == y; }
        static bool gt(int x, int y){ return x > y; }
};

/* macros for minheap */

#define MinHeapDefaultCapacity 31

#define InHeap(size, i) ( ((-1)<(i)) && ((i)<(size)) )
#define LastInternal(size) Parent(size-1)
#define Parent(i) ((i-1)>>1)
#define LChild(i) ( ((i) << 1) + 1)
#define RChild(i) ( ((i) + 1) << 1)
#define ParentValid(i) ( 0 < i )
#define LChildValid(size, i) (InHeap(size, LChild(i)))
#define RChildValid(size, i) (InHeap(size, RChild(i)))
#define SmallerOne(arr, i, j, lt) ( (lt(arr[i], arr[j])) ? i : j )
#define ProperParent(arr, size, r, lt)                                           \
    ( RChildValid(size, r) ?                                                 \
        SmallerOne(arr, SmallerOne(arr, r, LChild(r), lt), RChild(r), lt) :  \
        ( LChildValid(size, r) ? SmallerOne(arr, r, LChild(r), lt) : r)      \
    )
/* macros end */

template <typename keyType, typename valType, typename CompType> class MinHeap {
protected:
    keyType* _keys;
    valType* _vals;
    int _size;
    int _capacity;

    void expand();
    void shrink();
    void copyFrom(keyType* keys, valType* vals, int lo, int hi);
    int siftUp(int r);
    int siftDown(int size, int r);
    void heapify(int size);
    void sort(int lo, int hi);
public:
    MinHeap();
    MinHeap(keyType* keys, valType* vals, int size) { copyFrom(keys, vals, 0, size); heapify(size); }
    ~MinHeap() {};
    int size() { return _size; }
    bool empty() { return _size == 0; }
    keyType getMinKey() { return _keys[0]; }
    valType getMinVal() { return _vals[0]; }
    keyType getKeyAt(int r) { return _keys[r]; }
    valType getValAt(int r) { return _vals[r]; }
    void delMin();
    void acsSort() { sort(0, _size); }
    void printAll();
};


template <typename keyType, typename valType, typename CompType> 
class MinHeapFixedLength: public MinHeap<keyType, valType, CompType> {
protected:
    int _max_size;
public:
    MinHeapFixedLength(keyType* keys, valType* vals, int size) { this->copyFrom(keys, vals, 0, size); this->heapify(size); }
    MinHeapFixedLength() { _max_size = 31; }
    MinHeapFixedLength(int len): _max_size(len) {}
    ~MinHeapFixedLength() {};
    void insert(keyType key, valType val);
};

template <typename keyType, typename valType, typename CompType> 
class MinHeapVariableLength: public MinHeap<keyType, valType, CompType> {
private:
    ;
public:
    void insert(keyType key, valType val);
};