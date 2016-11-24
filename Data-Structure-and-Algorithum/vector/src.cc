#include "vector.h"
#include <cstdlib>
#include <algorithm>
using namespace std;
template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
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

template<typename T>void Vector<T>::unsort(Rank lo,Rank hi){
	T* V =_elem+lo;
	for(Rank i=hi-lo;i>0;i--)
		swap(V[i-1],V[rand()%i]);
}	

template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
    expand();
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++ ;
	return r;
}
template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
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
		;
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
    int j = 0;
    while (++j < _size)
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
   	_size = ++i;
    shrink();
    return j - i;
}


template <typename T>
Rank binSearch(T *A, T const &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
		Rank mi=(lo+hi)>>1;
		(e<A[mi])?hi=mi:lo=mi+1;
	}
	return --lo;
}

template <typename T>
Rank Vector<T>::search(T const& e,Rank lo,Rank hi)const {
		return binSearch(_elem,e,lo,hi);
}

template <typename T> void Vector<T>::traverse(void (*visit) (T&)){
	for(int i=0;i<_size; i++)
		visit(_elem[i]);
}
template <typename T>
template <typename VST>
void Vector<T>::traverse(VST& visit){
	for(int i=0;i<_size;i++)
		visit(_elem[i]);
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo,Rank hi){
	while (!bubble(lo,hi--));
}

template <typename T>bool Vector<T>::bubble (Rank lo, Rank hi){
	bool sorted = true;
	while(++lo<hi)
		if(_elem[lo-1]>_elem[lo]){
			sorted = false;
			swap(_elem[lo-1],_elem[lo]);
		}
	return sorted;
}

template <typename T>
void Vector<T>::mergeSort(Rank lo,Rank hi){
	if(hi-lo<2) return;
	int mi=(hi+lo)/2;
	mergeSort(lo,mi);
	mergeSort(mi,hi);
	merge(lo,mi,hi);
}

template<typename T>
void Vector<T>::merge(Rank lo,Rank mi,Rank hi){
	T*A = _elem + lo;
	int lb = mi-lo;
	T*B = new T[lb];
	for(Rank i=0;i<lb;++i)
		B[i]=A[i];
	int lc=hi-mi;
	T*C = _elem +mi;
	for(Rank i=0,j=0,k=0;(j<lb)||(k<lc);){
	}
	delete [] B;
}	

template<typename T>struct Decrease{
	virtual void operator()(T&e){e--;}
};
template<typename T>void decrease(Vector<T> &V){
	V.traverse(Decrease<T>());
}
			
template<typename T>
void Vector<T>::sort(Rank lo,Rank hi){
	//mergeSort(lo,hi);
	//insertionSort(lo,hi);
	selectionSort(lo,hi);
}	

//3-8 exercise
template<typename T>
void Vector<T>::insertionSort(Rank lo,Rank hi){
	T*A = _elem+lo;
	T*B = _elem+hi;	
	Rank p=0;
	while(p!=(hi-lo)){
		Rank posi=search(A[p],0,p);
		Rank p1=p;
		Rank p2=p-1;
		while(p2!=posi)
			swap(A[p1--],A[p2--]);
		p++;	
	}
}
//3-9
template<typename T>
Rank Vector<T>::max(Rank lo,Rank hi){
	Rank mx=hi;
	while(lo<hi--)
		if(_elem[hi]>_elem[mx])
			mx=hi;
	return mx;
}
template <typename T>
void Vector<T>::selectionSort(Rank lo,Rank hi){
	while(lo<--hi)
		swap(_elem[max(lo,hi)],_elem[hi]);
}



