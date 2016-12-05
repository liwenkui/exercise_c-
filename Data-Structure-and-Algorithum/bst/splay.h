#ifndef SPLAY_H
#define SPLAY_H
#include "bst.h"
template<typename T>
class Splay : public BST<T>{
	protected:
		using BST<T>::_root;
		using BST<T>::_size;
		using BST<T>::_hot;
		BinNodePosi(T) splay(BinNodePosi(T));
	public:
		BinNodePosi(T)& search(const T&);
		BinNodePosi(T) insert (const T&);
		bool remove(const T&e);
};

#include "splay_imp.h"
#endif
