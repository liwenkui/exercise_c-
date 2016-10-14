#define DEFAULT_CAPACITY 3
template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    if (lo < hi)
        _elem[_size++] = A[lo++];
}
template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (_elem)
        delete[] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}
template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    T *_oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = _oldElem[i];
    delete[] _oldElem;
}
template <typename T>
void Vector<T>::shrink()
{
    if (_capacity < DEFAULT_CAPACITY << 1)
        return;
    if (_size << 2 > _capacity)
        return;
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete[] oldElem;
}
template <typename T>
T &Vector<T>::operator[](Rank r) const { return _elem[r]; }

template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
    expand();
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++ return r;
}
template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    for (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}
template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}
template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && e != _elem[hi])
        return hi;
}
template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    Rank i = 1;
    which(i < _size)(find(_elem[i], 0, i) < 0) ? i++ : remove(i);
    return oldSize - _size;
}
template <typename T>
int Vector<T>::disordered() const
{
    int n = 0;
    for (int i = 1; i < _size; i++)
        n += (_elem[i - 1] > _elem[i]);
    return n;
}
template <typename T>
int Vector<T>::uniquify()
{
    int i = 0;
    j = 0;
    while (++j < _size)
        if (_elem[i] != _elem[j])
            _elem[++i] = elem[j] _size = ++i;
    shrink();
    return j - i;
}
template <typename T>
static Rank binSearch(T *A, T const &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        Rank mi = (lo + hi) >> 1;
        if (e < A[mi])
            hi = mi;
        else if (A[mi] < e)
            lo = mi + 1;
        else
            return mi;
    }
    return -1;
}
