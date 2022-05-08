#include <iostream>
#include <string>
#include <algorithm>

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
    keyType getValAt(int r) { return _vals[r]; }
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

/* method template 

template <typename keyType, typename valType, typename CompType>
int MinHeap<keyType, valType, CompType>::expand() {

}

*/

template <typename keyType, typename valType, typename CompType>
MinHeap<keyType, valType, CompType>::MinHeap() {
    _size = 0; _capacity = MinHeapDefaultCapacity;
    _keys = new keyType[_capacity];
    _vals = new valType[_capacity];
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::expand() {
    if (_size < _capacity) return;
    if (_capacity < MinHeapDefaultCapacity) _capacity = MinHeapDefaultCapacity;
    keyType* oldKeys = _keys; valType* oldVals;
    _capacity <<= 1;
    _keys = new keyType[_capacity];
    _vals = new valType[_capacity];
    for (int i = 0; i < _size; i++) {
        _keys[i] = oldKeys[i];
        _vals[i] = oldVals[i];
    }
    delete [] oldKeys, oldVals;
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::shrink() {
    if (_capacity < MinHeapDefaultCapacity << 1) return;
    if (_size << 2 > _capacity) return;
    keyType* oldKeys = _keys; valType* oldVals = _vals;
    _capacity <<= 1;
    _keys = new keyType[_capacity];
    _vals = new valType[_capacity];
    for (int i = 0; i < _size; i++) {
        _keys[i] = oldKeys[i];
        _vals[i] = oldVals[i];
    }
    delete [] oldKeys, oldVals;
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::copyFrom(keyType* keys, valType* vals, int lo, int hi) {
    _capacity = 2*(hi-lo); _size = 0;
    _keys = new keyType[_capacity];
    _vals = new valType[_capacity];
    while (lo < hi) {
        _keys[_size] = keys[lo];
        _vals[_size] = vals[lo];
        _size++; lo++;
    }
}

template <typename keyType, typename valType, typename CompType>
int MinHeap<keyType, valType, CompType>::siftUp(int r) {
    while (ParentValid(r)) {
        int rp = Parent(r);
        if (CompType::gt(_keys[r], _keys[rp])) break;
        std::swap(_vals[r], _vals[rp]);
        std::swap(_keys[r], _keys[rp]);
        r = rp;
    }
    return r;
}

template <typename keyType, typename valType, typename CompType>
int MinHeap<keyType, valType, CompType>::siftDown(int size, int r) {
    int j;
    while (r != (j = ProperParent(_keys, size, r, CompType::lt))) {
        std::swap(_keys[r], _keys[j]);
        std::swap(_vals[r], _vals[j]);
        r = j;
    }
    return r;
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::heapify(int size) {
    for (int i = LastInternal(size); InHeap(size, i); i--) 
        siftDown(size, i);
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::sort(int lo, int hi) {
    MinHeap<keyType, valType, CompType> H(_keys+lo, _vals+lo, hi-lo);
    while (!(H.empty())) {
        keyType minKey = H.getMinKey();
        valType minVal = H.getMinVal();
        H.delMin();
        _keys[lo] = minKey;
        _vals[lo] = minVal;
        lo++;
    }
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::delMin() {
    --_size;
    _keys[0] = _keys[_size];
    _vals[0] = _vals[_size];
    siftDown(_size, 0);
}

template <typename keyType, typename valType, typename CompType>
void MinHeap<keyType, valType, CompType>::printAll() {
    std::cout << "Print keys:\n";
    for (int i = 0; i < _size; i++) std::cout << _keys[i] << " ";
    std::cout << "\nPrint vals in corresponding order:\n";
    for (int i = 0; i < _size; i++) std::cout << _vals[i] << " ";
    std::cout << "\n";
}

/* Inheritence classes */

template <typename keyType, typename valType, typename CompType>
void MinHeapFixedLength<keyType, valType, CompType>::insert(keyType key, valType val) {
    if (this->_size == _max_size) {
        if (CompType::lt(this->_keys[0], key)){
            this->_keys[0] = key; this->_vals[0] = val;
        }
        this->siftDown(this->_size, 0);
    } else {
        this->_vals[this->_size] = val; this->_keys[this->_size] = key;
        this->siftUp(this->_size);
        this->_size++;
    }
}


int main() {
    int ks[] = {65, 14, 1, 2, 10, 8,};
    std::string vs[] = {"sixty-five", "ten-four", "one", "two", "ten", "eight"};
    MinHeapFixedLength<int, std::string, IntCompare> mh(ks, vs, 6);
    mh.printAll();
    mh.delMin();
    mh.printAll();
    mh.acsSort();
    mh.printAll();
    int k = 9; std::string v = "nine";
    mh.insert(k, v);
    mh.printAll();
}