#include "minHeap.h"

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
    while (i != (j = ProperChild(_vals, _size, i))) {
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
    _keys.assign(ks);
    _vals.assign(vs);
    heapify(_size);
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::print() {
    using std::cout;
    cout << "Print current heap's keys:\n";
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
    std::swap(_keys[0], _keys[size]);
    std::swap(_vals[0], _vals[size]);
    siftDown(_size, 0);
}

template <typename keyT, typename valT>
void minHeap<keyT, valT>::sort() {
    minHeap<keyT, valT> h_tmp = {_keys, _vals};
}