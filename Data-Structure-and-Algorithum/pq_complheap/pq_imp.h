#include "pq_complheap.h"

template<typename T>
T PQ_ComplHeap<T>::getMax(){return _elem[0];}

template<typename T>
void PQ_ComplHeap<T>::insert(T e){
	Vector<T>::insert(e);
	percolateUp(_size-1);
}

template<typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i){
//	while(ParentValid(i)){
//		Rank j = Parent(i);
//		if(lt(_elem[i],_elem[j])) break;
//		swap(_elem[i],_elem[j]);i=j;
//	}
	T e = _elem[i];
	while(ParentValid(i)){
		Rank j = Parent(i);
		if(lt(e,_elem[j])){
			_elem[i]=e;
			break;
		}
		_elem[i]=_elem[j];
		i=j;
	}
	return i;
}

template<typename T>
T PQ_ComplHeap<T>::delMax(){
	T maxElem = _elem[0];
	_elem[0] = _elem[--_size];
	percolateDown(_size,0);
	return maxElem;
}
template<typename T>
Rank PQ_ComplHeap<T>::percolateDown(Rank n,Rank i){
	Rank j;
	while(i!=(j=ProperParent(_elem,n,i)))
	{swap(_elem[i],_elem[j]);i=j;}
	return i;
}
template<typename T>
void PQ_ComplHeap<T>::heapify(Rank n){
	//brute force
	//for(int i=1;i<n;i++)
	//	percolateUp(i);
	for(int i= LastInternal(n);InHeap(n,i);i--){
		percolateDown(n,i);
	}
}
