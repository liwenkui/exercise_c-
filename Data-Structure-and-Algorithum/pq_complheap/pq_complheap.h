#ifndef PQ_COMPLHEAP
#define PQ_COMPLHEAP
#include "../pq/pq.h"
#include "../vector/vector.h"
#include "pq_complheap_macro.h"
template<typename T>
class PQ_ComplHeap : public PQ<T>,public Vector<T>{
	protected:
		using Vector<T>::_elem;
		using Vector<T>::copyFrom;
		using Vector<T>::_size;
		Rank percolateDown(Rank n,Rank i);
		Rank percolateUp (Rank i);
		void heapify( Rank n);
	public:
		PQ_ComplHeap(){}
		PQ_ComplHeap(T* A,Rank n){copyFrom(A,0,n);heapify(n);}
		void insert(T);
		T getMax();
		T delMax();
};
#include "pq_imp.h"
#endif
