#ifndef STACK_H
#define STACK_H
#include "../vector/vector.h"

template<typename T>
class Stack:public Vector<T>{
	public:
		using Vector<T>::size;
		using Vector<T>::remove;
		using Vector<T>::insert;
		void push(T const&e){ insert(size(),e);}
		T pop() {return remove(size()-1);}
		T& top() {return (*this)[size()-1];}
};
#endif
