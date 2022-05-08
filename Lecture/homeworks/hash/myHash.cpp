#include <fstream>
#include "myHash.hpp"

template <typename keyType, typename valType>
int HashTable<keyType, valType>::exist(keyType k) {
    for (int i = 0; i < _using_size; i++)
        if (k == _keys[i]) 
            return i;
    return -1;
}

template <typename keyType, typename valType>
keyType HashTable<keyType, valType>::val2int(valType v) {
    keyType result = 0;
    keyType a[3];
    for (int i = 0; i < 3; i++)
        a[i] = static_cast<valType>(v[i]);
    result = a[0]*65536 + a[1]*256 + a[3];
    return result;
}


template <typename keyType, typename valType>
void HashTable<keyType, valType>::probe(keyType & k, valType & v) {
    using std::cout;
    // cout << "probe with k = " << k;
    // k = (k*v.size()) % _table_max_size;
    k = (k + v.size()) % _table_max_size;
    // v = (v + v * v) % _table_max_size;
    // cout << ". new k = " << k <<"\n";
}

template <typename keyType, typename valType>
keyType HashTable<keyType, valType>::hash1(keyType* ks, int n) {
    keyType sum = 0;
    for (int i = 0; i < n; ++i)
        sum += ks[i];
    return sum % _table_max_size;
}

template <typename keyType, typename valType>
void HashTable<keyType, valType>::insert(keyType & k, valType & v) {
    int pos = -1;
    while ((pos = exist(k)) != -1) {
        if (v == _vals[pos]) {
            return ;
        }
        probe(k, v);
    }
    _vals.push_back(v);
    _keys.push_back(k);
    _using_size++;
}

template <typename keyType, typename valType>
keyType HashTable<keyType, valType>::hash_half(keyType* ks, int n) {
    return hash1(ks, n);
}

template <typename keyType, typename valType>
keyType HashTable<keyType, valType>::hash(valType* vs, int n) {
    keyType* ks = new keyType[n];
    for (int i = 0; i < n; i++)
        ks[i] = val2int(vs[i]);
    std::cout << n << " vals, encode to: ";
    for (int i = 0; i < n; i++)
        std::cout << ks[i] << " ";
    std::cout << "\n";

    keyType key = hash1(ks);

    return key;
}

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
    for (int i = 0; i < _size; i++) std::cout << _vals[i] << "\n";
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

int test_heap() {
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
    return 0;
}   

int main () {
    using MHFL = MinHeapFixedLength<long int, std::string, IntCompare>;
    HashTable<long int, std::string> ht;
    std::string buf;
	long int aLine[100];

    std::ifstream file("DataHeapHashHW");
	int line = 0;
	while (getline(file, buf)){
		long int nCHN = buf.length()/3, a[3], k, i;
		for (k=0; k<nCHN; k++){ 
			for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(buf[3*k+i]); 
			aLine[k] = a[0]*65536 + a[1]*256 + a[2];
		}
		// std::cout << "* " << buf << "\n";
		// std::cout << nCHN << " Chinese characters : ";
		// for (int k=0; k<nCHN; k++) std::cout << aLine[k] << " ";
		// std::cout << "\n";
        long int key = ht.hash_half(aLine, nCHN);
        // std::cout << key << "\n";
        // char * val = buf.c_str();
        ht.insert(key, buf);
        // mhfl.insert(key, buf);
        // if ((++line) % 300 == 0)
	}

    std::cout << "size = " << ht.size() << "\n";

    // test_heap();
    int size = ht.size();
    long int *keys = new long int[size];
    std::string *vals = new std::string[size];
    for (int i = 0; i < size; i++) {
        keys[i] = ht._keys[i];
        vals[i] = ht._vals[i];
    }
    MHFL mhfl(keys, vals, size);
    mhfl.acsSort();
    int iters = 31, begin = mhfl.size() - iters;
    std::cout << "Print corresponding {key}: {value} pair\n";
    while (iters--) {
        std::cout << mhfl.getKeyAt(begin) << " " << mhfl.getValAt(begin) << "\n";
        begin++;
    }

    std::cout << "Initialize writing...\n";
    std::ofstream out("HeapAll.dat");
    if (out.is_open()) {
        std::cout << "Begin writing...\n";
        for (int i = mhfl.size() - 1; i >= 0; i--) {
            out << mhfl.getKeyAt(i) << " " << mhfl.getValAt(i) << "\n";
        }
    }
    std::cout << "End writing.\n";
	return 0;
}