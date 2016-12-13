#include "../vector/vector.h"
#include <cstdlib>
template<typename T>
void Vector<T>::quickSort(Rank lo,Rank hi){
	if(hi-lo<2)return;
	Rank mi=partition(lo,hi-1);
	quickSort(lo,mi);
	quickSort(mi+1,hi);
}
template<typename T>
Rank Vector<T>::partition(Rank lo,Rank hi){
	swap(_elem[lo],_elem[lo+rand()%(hi-lo+1)]);
	T pivot = _elem[lo];int mi=lo;
	for(int k=lo+1;k<=hi;k++)
		if(_elem[k]<pivot)
			swap(_elem[++mi],_elem[k]);
	swap(_elem[lo],_elem[mi]);
	return lo;
}
