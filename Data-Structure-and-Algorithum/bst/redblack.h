#ifndef REDBLACK_H
#define REDBLACK_H
#include "bst.h"
template<typename T>
class RedBlack : public BST<T>{
	protected:
		using BST<T>::_hot;
		using BST<T>::_size;
		using BST<T>::_root;
		void solveDoubleRed(BinNodePosi(T));
		void solveDoubleBlack(BinNodePosi(T));
		int updateHeight(BinNodePosi(T));
	public:
		BinNodePosi(T) insert (const T&e);
		bool remove (const T&e);
		using BST<T>::search;
};

#include "redblack_imp.h"
#endif
