#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using Rank = int;
int const MAX_N = 1e2;

/* Use heap to dynamically sort and get max */

#define MaxHeapDefaultCapacity 3

#define InHeap(n, i) (((-1)<(i)) && ((i)<(n)))
#define LastInternal(n) Parent(n-1)
#define Parent(r) ((r-1)>>1)
#define LChild(r) (1 + ((r) << 1))
#define RChild(r) ((1 + (r)) << 1)
#define ParentValid(r) (0 < r)
#define LChildValid(n, i) (InHeap(n, LChild(i)))
#define RChildValid(n, i) (InHeap(n, RChild(i)))
#define Bigger(arr, i, j) ((arr[i]<arr[j]) ? j : i)
#define ProperParent(arr, n ,i) ( RChildValid(n, i) ? Bigger(arr, Bigger(arr, i, LChild(i)), RChild(i)) : ( LChildValid(n,i)) ? Bigger(arr, i, LChild(i)) : i )

template <typename T> class MaxHeap
{
private:
    T* _elem;
    Rank _size;
    Rank _capacity;
protected:
    Rank siftUp(Rank i);
    Rank siftDown(Rank n, Rank i);
    void heapify(Rank n);
    void copyFrom(T* arr, Rank i, Rank j);
    void insert(Rank r, T const & elem);
    Rank remove(Rank lo, Rank hi); // remove [lo, hi)
    void expand();
    void shrink();
    void sort(Rank i, Rank j);
public:
    MaxHeap() {};
    MaxHeap(T* A, Rank n) {copyFrom(A,0,n); heapify(n);}
    ~MaxHeap() {};
    T getMax() {return _elem[0];}
    T delMax();
    void push_back (T const & elem) {insert(_size, elem);}
    void descSort() {sort(0, _size);}
    void show();
    bool empty() {return _size == 0;}
    Rank size() {return _size;}
    Rank remove(Rank r) {int e = _elem[r]; remove(r, r+1); return e;}
    Rank removeZero(Rank r);
    void deleteZeros(int zeros);
    T& operator[](Rank r) const {return _elem[r];}
};

template <typename T> void MaxHeap<T>::copyFrom(T* arr, Rank i, Rank j)
{
    _elem = new T[_capacity = 2*(j-i)]; _size = 0;
    while (i < j)
        _elem[_size++] = arr[i++];
}

template <typename T> void MaxHeap<T>::expand()
{
    if (_size < _capacity) return;
    if (_capacity < MaxHeapDefaultCapacity) _capacity = MaxHeapDefaultCapacity;
    T* oldElem = _elem; _elem = new T[_capacity<<=1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete [] oldElem;
}

template <typename T> void MaxHeap<T>::shrink()
{
    if (_capacity < MaxHeapDefaultCapacity<<1) return;
    if (_size << 2 > _capacity) return;
    T* oldElem = _elem; _elem = new T[_capacity>>=1];
    for (int i = 0; i < _size; i++) 
        _elem[i] = oldElem[i];
    delete [] oldElem;
}

template <typename T> void MaxHeap<T>::show()
{
    for (int i = 0; i < _size; ++i)
        (i<_size-1) ? (cout << _elem[i] << " ") : (cout << _elem[i] << endl);
}

template <typename T> void MaxHeap<T>::insert (Rank r, T const& elem)
{
    expand();
    _elem[_size] = elem; _size++;
    siftUp(_size-1);
}

template <typename T> Rank MaxHeap<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi) return 0;
    while (hi < _size) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}

template <typename T> Rank MaxHeap<T>::siftUp(Rank r) 
{
    while (ParentValid(r)) {
        Rank j = Parent(r);
        if (_elem[j]>=_elem[r]) break;
        swap(_elem[r], _elem[j]); r = j;
    }
    return r;
}

template <typename T> T MaxHeap<T>::delMax()
{
    T maxElem = _elem[0]; _elem[0] = _elem[--_size];
    siftDown(_size, 0);
    return maxElem;
}

template <typename T> Rank MaxHeap<T>::siftDown( Rank n, Rank i)
{
    Rank j;
    while (i != (j = ProperParent(_elem, n, i)))
        {swap(_elem[i], _elem[j]); i = j;}
    return i;
}

template <typename T> void MaxHeap<T>::heapify(Rank n)
{
    for (int i = LastInternal(n); InHeap(n, i); i--)
        siftDown(n, i);
}

template <typename T> void MaxHeap<T>::sort(Rank i, Rank j)
{
    MaxHeap<T> H (_elem+i, j-i);
    while (!H.empty())
        _elem[i++] = H.delMax();
}

template <typename T> Rank MaxHeap<T>::removeZero(Rank r)
{
    remove(r, r+1);
    return 0;
}

template <typename T> void MaxHeap<T>::deleteZeros(int zeros)
{
    int i = 0;
    while (zeros!=0) {
        if (_elem[i] == 0) {remove(i, i+1); zeros--;}
        else ++i;
    }
}

int main() {
    int n, m, c;
    int a[MAX_N];
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // Use MaxHeap
    MaxHeap<int> H(a, n);
    H.descSort();
    int time = 0, zeros = 0;
    while (!H.empty()) {
        m = (m > H.size()) ? H.size() : m; zeros = 0;
        for (int i = 0; i < m; ++i) {
            if (H[i] > c) H[i] = H[i] - c;
            else {H[i] = 0; zeros++;}
        }
        H.deleteZeros(zeros);
        time++;
    }
    cout << time << endl;


    return 0;
}