#ifndef QUEUE_H
#define QUEUE_H
#include "../list/List.h"
template<typename T> 
class Queue:public List<T>{
	public:
		using List<T>::insertAsLast;
		using List<T>::first;
		using List<T>::remove;
		void enqueue(T const&e){insertAsLast(e);}
		T dequeue(){return remove(first());}
		T& front(){return first()->data;}
};
#endif
