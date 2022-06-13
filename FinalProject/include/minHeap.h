#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/* MACROS FOR MINHEAP */
#define IsInHeap(size, i) (((i) > (-1)) && ((i) < (size)))
#define LastInternal(size) Parent(size - 1)
#define Parent(i) ((i - 1) >> 1)
#define LChild(i) (((i) << 1) + 1)
#define RChild(i) (((i + 1)) << 1)
#define IsParentValid(i) (i > 0)
#define IsLChildValid(size, i) (IsInHeap(size, LChild(i)))
#define IsRChildValid(size, i) (IsInHeap(size, RChild(i)))
#define SmallerBetween(arr, i, j) ((arr[i] < arr[j]) ? (i) : (j))
/* Smaller One between the elem and its children */
#define ProperChoice(arr, size, i)                                                                                     \
    ((IsRChildValid(size, i) ? (SmallerBetween(arr, RChild(i), (SmallerBetween(arr, LChild(i), i))))                   \
                             : ((IsLChildValid(size, i)) ? (SmallerBetween(arr, LChild(i), i)) : (i))))

template <typename keyT, typename valT>
class minHeap {
  private:
    std::vector<keyT> _keys;
    std::vector<valT> _vals;
    int _size;

  protected:
    int siftUp(int r);
    int siftDown(int size, int r);
    void heapify(int size);

  public:
    minHeap() { _size = 0; }
    minHeap(std::vector<keyT> ks, std::vector<valT> vs);
    ~minHeap() {}
    int size() { return _size; }
    bool empty() { return _size == 0; }
    keyT get_min_key() { return _keys[0]; }
    valT get_min_val() { return _vals[0]; }
    keyT get_key_at(int r) { return _keys[r]; }
    valT get_val_at(int r) { return _vals[r]; }
    valT get_val_at(keyT k);
    bool set_val_with(keyT k, valT v);
    void push_back(keyT k, valT v);
    void print_keys();
    void print_vals();
    void print_all();
    void delMin();
    void sort();
};

template <typename keyT, typename valT>
int minHeap<keyT, valT>::siftUp(int i) {
    while (IsParentValid(i)) {
        int p = Parent(i);
        if (_vals[p] < _vals[i])
            break;
        std::swap(_vals[i], _vals[p]);
        std::swap(_keys[i], _keys[p]);
        i = p;
    }
    return i;
}

template <typename keyT, typename valT>
int minHeap<keyT, valT>::siftDown(int size, int i) {
    int j;
    while (i != (j = ProperChoice(_vals, _size, i))) {
        std::swap(_keys[i], _keys[j]);
        std::swap(_vals[i], _vals[j]);
        i = j;
    }
    return i;
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::heapify(int size) {
    for (int i = LastInternal(size); IsInHeap(size, i); i--)
        siftDown(size, i);
}

template <typename keyT, typename valT>
minHeap<keyT, valT>::minHeap(std::vector<keyT> ks, std::vector<valT> vs) {
    _size = ks.size();  // ASSERTION ks.size() == vs.size()
    _keys.assign(ks.begin(), ks.end());
    _vals.assign(vs.begin(), vs.end());
    heapify(_size);
}

template <typename keyT, typename valT>
valT minHeap<keyT, valT>::get_val_at(keyT k) {
    int i = 0;
    while (_keys[i] != k && i < _size)
        i++;
    if (i == _size)
        throw "Invalid key";
    return _vals[i];
}

template <typename keyT, typename valT>
bool minHeap<keyT, valT>::set_val_with(keyT k, valT v) {
    // int i; std::cout << "searching " << k << " within " << _size << "
    // keys.\n";
    int i = 0;
    while (_keys[i] != k && i < _size)
        i++;
    if (i == _size)
        return false;  // bad set
    _vals[i] = v;
    siftDown(_size, i);
    siftUp(i);
    return true;
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::push_back(keyT k, valT v) {
    _keys.push_back(k);
    _vals.push_back(v);
    siftUp(_size++);
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::print_keys() {
    using std::cout;
    cout << "Current heap of size: " << _size;
    cout << "\nPrint current heap's keys:\n";
    for (auto elem : _keys)
        cout << elem << " ";
    cout << "\n";
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::print_vals() {
    using std::cout;
    cout << "Current heap of size: " << _size;
    cout << "Print current heap's values:\n";
    for (auto elem : _vals)
        cout << elem << " ";
    cout << "\n";
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::print_all() {
    using std::cout;
    cout << "Current heap of size: " << _size;
    cout << "\nPrint current heap's keys:\n";
    for (auto elem : _keys)
        cout << elem << " ";
    cout << "\n";
    cout << "Print current heap's values:\n";
    for (auto elem : _vals)
        cout << elem << " ";
    cout << "\n";
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::delMin() {
    --_size;
    std::swap(_keys[0], _keys[_size]);
    std::swap(_vals[0], _vals[_size]);
    _keys.pop_back();
    _vals.pop_back();
    siftDown(_size, 0);
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::sort() {
    minHeap<keyT, valT> h_tmp = {_keys, _vals};
    int i = 0;
    while (!h_tmp.empty()) {
        keyT min_k = h_tmp.get_min_key();
        valT min_v = h_tmp.get_min_val();
        h_tmp.delMin();
        _keys[i] = min_k;
        _vals[i] = min_v;
        i++;
    }
}

/*
 * Implementation and declaration of template class
 * must be placed together to avoid
 * `undefined reference` problem
 */