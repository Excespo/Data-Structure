#ifndef __LIST_H
#define __LIST_H

typedef int Rank;
const int DEFAULT_CAPACITY = 3;

template <typename T> class Vector
{
    protected:
        Rank _size; Rank _capacity;
        T* _elem;
        // copyFrom - Copy array section A[lo, hi)
        void copyFrom(T const* A, Rank lo, Rank hi);
        // expand if space isn't enough
        void expand();
        // shrink if fillin factor is too small
        void shrink();
        // scan and swap
        bool bubble(Rank lo, Rank hi);
        // bubble sort
        void bubbleSort(Rank lo, Rank hi);
        // get the max element
        Rank max(Rank lo, Rank hi);
        // algorithm
        void selectionSort(Rank lo, Rank hi);
        //
        void merge(Rank lo, Rank hi);
        // algorithm
        void mergeSort(Rank lo, Rank hi);
        // algorithm
        Rank partition(Rank lo, Rank hi);
        // algorithm
        void quickSort(Rank lo, Rank hi);
        // algorithm
        void heapSort(Rank lo, Rank hi);
    public:
        /* Constructor */
        // capacity = c, size = s, all ele initialized as v
        Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
            _elem = new T[_capacity = c]; for (_size=0; _size<s; _elem[_size++] = v);
        }
        // Copy a section from array
        Vector(T const* A, Rank lo, Rank hi) {
            copyFrom(A, lo, hi);
        }
        // Copy a whole from array
        Vector(T const* A, Rank n) {
            copyFrom(A, 0, n);
        }
        // Copy a section from vector
        Vector(Vector<T> const& V, Rank lo, Rank hi) {
            copyFrom(V._elem, lo ,hi);
        }
        // Copy a whole from vector
        Vector(Vector<T> const& V) {
            copyFrom(V._elem, 0, V._size);
        }

        /* Destructor */
        ~Vector() {delete [] _elem;}

        /* Read-only data interface */
        Rank size() const {return _size;}
        bool empty() const {return !_size;}
        int disordered() const;
        // find element in the whole inordered vector
        Rank find(T const& e) const {return find(e, 0, _size);}
        // find element in a section of inordered vector
        Rank find(T const& e, Rank lo, Rank hi) const; 
        // find element in the whole ordered vector
        Rank search(T const& e) const { return (0 >= _size) ? -1 : search(e, 0, _size);}
        // find element in the section of an ordered vector
        Rank search(T const& e, Rank lo, Rank hi) const;
        // comparator
        template <typename T> static bool it(T* a, T* b) {return lt(*a, *b);}
        template <typename T> static bool it(T& a, T& b) {return a<b;}
        template <typename T> static bool eq(T* a, T* b) {return eq(*a, *b);}
        template <typename T> static bool eq(T& a, T& b) {return a==b;}

        /* Writable interface */
        // overload subsript operator to same with an array
        T& operator[](Rank r) const;
        // overload the assignment operator, to clone vector directly
        Vector<T> & operator=(Vector<T> const &); 
        // delete rank r element
        T remove(Rank r);
        // delete elements with section in [lo, hi)
        int remove(Rank lo, Rank hi);
        // insert element
        Rank insert(Rank r, T const& e);
        // insert with default position in the tail
        Rank insert(T const& e) {return insert(_size, e);}
        // sort in the secton [lo, hi)
        void sort(Rank lo, Rank hi);
        // sort the whole
        void sort(){sort(0, _size);}
        // unsort in the secton [lo, hi)
        void unsort(Rank lo, Rank hi);
        // unsort the whole
        void unsort() {unsort(0, _size);}
        // delete repetition for inordered vector
        int deduplicate();
        // delete repetition for ordered vector
        int uniquify();
        // traverse
        void traverse(void (*)(T&)); // with function ptr, read-only or change locally
        template <typename VST> void traverse(VST&); // with function object, change globally

}; // Vector

#endif
