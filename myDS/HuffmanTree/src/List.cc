#include "../include/List.hh"

/**
 * @brief init a list
 * @param NULL
 *
 * @return void
 */
template <typename T>
void List<T>::init()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->succ = nullptr;
    trailer->pred = header;
    _size = 0;
}

template <typename T> 
T& List<T>::operator[] (Rank r) const 
{
    // if ( (r < 0) || (r >= _size) ) 
    //     {std::cout<<"Invalid rank.\n"; exit(0);}
    assert((r>=0) && (r < _size));
    ListNodePtr(T) p = first();
    while ( 0 < r-- )
        p = p->succ;
    return p->data;
}

template <typename T>
ListNodePtr(T) List<T>::find(T const & elem, ListNodePtr(T) p, int n) const
{
    while ( 0 < n-- )
        if ( elem ==  (p = p->pred)->data ) return p;
    return nullptr;
}

template <typename T>
ListNodePtr(T) List<T>::insertAsFirst(T const & elem)
{
    _size++;
    return header->insertAsSucc(elem);
}

template <typename T>
ListNodePtr(T) List<T>::insertAsLast(T const & elem)
{
    _size++;
    return trailer->insertAsPred(elem);
}

template <typename T>
ListNodePtr(T) List<T>::insertBefore(ListNodePtr(T) p, T const & elem)
{
    _size++;
    return p->insertAsPred(elem);
}

template <typename T>
ListNodePtr(T) List<T>::insertAfter(ListNodePtr(T) p, T const & elem)
{
    _size++;
    return p->insertAsSucc(elem);
}

template <typename T>
ListNodePtr(T) ListNode<T>::insertAsPred(T const & d)
{
    ListNodePtr(T) x = new ListNode (d, pred, this);
    pred->succ = x; pred = x;
    return x;
}

template <typename T>
ListNodePtr(T) ListNode<T>::insertAsSucc(T const & s)
{
    ListNodePtr(T) x = new ListNode (s, this, succ);
    succ->pred = x; succ = x;
    return x;
}

template <typename T>
void List<T>::copyNodes(ListNodePtr(T) p, int n)
{
    init();
    while (n--) 
        { insertAsLast(p->date); p = p->succ;}
}

template <typename T>
void List<T>::List(ListNodePtr(T) p, int n)
{
    copyNodes(p, n);
}

template <typename T>
void List<T>::List(List<T> const & L)
{
    copyNodes(L.first(), L._size);
}

template <typename T>
void List<T>::List(List<T> const & L, Rank r, int n)
{
    copyNodes(L[r], n);
}

template <typename T>
T List<T>::remove(ListNodePtr(T) p)
{
    T elem = p->data;
    p->pred->succ = p->succ; p->succ->pred = p->pred;
    delete p; _size--; return elem;
}

template <typename T>
List<T>::~List() 
{
    clear(); delete header; delete trailer;
}

template <typename T>
int List<T>::clear() 
{
    int old_size = _size;
    while (0 < _size) remove(header->succ);
    return old_size;
}

template <typename T>
int List<T>::deduplicate()
{
    if (_size < 2) return 0;
    int oldSize = _size;
    ListNodePtr(T) p = header; Rank r = 0;
    while (trailer != (p = p->succ)) {
        ListNodePtr(T) q = find(p->data, p, r);
        q ? remove(q) : r++;
    }
    return oldSize - _size;
}

template <typename T>
int List<T>::uniquify()
{
    if (_size < 2) return 0;
    int oldSize = _size;
    ListNodePtr(T) p = first(); ListNodePtr(T) q;
    while (trailer != (q = p->succ)) {
        if (p->data != q->data) p = q;
        else remove(q);
    }
    return oldSize - _size;
}

/**
 * @brief search an element in an ordered list, the element is the latest one that is no greater than the element to be compared.
 * @param `T const &` elem
 * @param p
 * @param n
 * 
 * @return a node pointer to the goal element, else header
 */
template <typename T>
ListNodePtr(T) List<T>::search(T const & elem, ListNodePtr(T) p, int n) 
{
    while ( 0 < n-- )
        if ( (p = p->pred)->data <= elem ) break;
    return p;
}

template <typename T>
void List<T>::sort (ListNodePtr(T) p, int n)
{
    switch (rand() % 3)
    {
    case 1:
        insertionSort(p, n); break;
    case 2:
        selectionSort(p, n); break;
    default:
        mergeSort(p, n); break;
    }
}

template <typename T>
void List<T>::insertionSort(ListNodePtr(T) & p, int n)
{
    for (Rank r = 0; r < n; r++) {
        /* construct a ascending prefix */
        insertAfter(search(p->data, r, p), p->data);
        p = p->succ; remove(p->pred);
    }
}

template <typename T>
void List<T>::selectionSort(ListNodePtr(T) & p, int n)
{
    ListNodePtr(T) head = p->pred; ListNodePtr(T) tail = p;
    for (int i = 0; i < n; i++) tail = tail->succ;
    while (1 < n) {
        ListNodePtr(T) max = selectMax(head->succ, n);
        insertBefore(tail, remove(max));
        tail = tail->pred; n--;
    }
}

template <typename T>
ListNodePtr(T) List<T>::selectMax(ListNodePtr(T) p, int n)
{
    ListNodePtr(T) max = p;
    for (ListNodePtr(T) cur = p; 1 < n; --n) {
        if (!lt(cur = cur->succ)->data, max->data)
            max = cur;
    }
    return max;
}

template <typename T>
bool lt(ListNodePtr(T) x, ListNodePtr(T) y) {return x->data < y->data;}

template <typename T>
void List<T>::merge(ListNodePtr(T) & p ,int n, List<T> & L, ListNodePtr(T) & q, int m)
{
    // assert: this.valip(p) && rank(p) + n <= size && this.sorted(p, n)
    //         L.valid(q) && rank(q) + m <= L.size && L.sorted(q, m)
    // possible to have this == L && rank(p) + n == rank(q)
    ListNodePtr(T) pp = p->pred;
    while ( 0 < m ){
        if ( (0 < n) && (p->data <= q->data)) {
            if (q == (p = p->succ)) break; 
            n--;
        } else {
            insertB(p, L.remove( (q = q->succ)->pred) );
            m--;
        }
    }
    p = pp->pred;
}

template <typenama T>
void List<T>::mergeSort(ListNodePtr(T) & p, int n)
{
    if (n < 2) return 0;
    int m = n >> 1;
    ListNodePtr(T) q = p; for (int i = 0; i < m; ++i) q = q->succ;
    mergeSort(p, m); mergeSort(q, n-m);
    merge(p, m, *this, q, n-m);
}