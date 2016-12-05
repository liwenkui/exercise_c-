#ifndef BST_H
#define BST_H
#include "../bintree/bintree.h"
template<typename T>class BST:public BinTree<T>{
	protected:
		using BinTree<T>::_root;
		using BinTree<T>::_size;
		using BinTree<T>::updateHeightAbove;
		using BinTree<T>::updateHeight;
		BinNodePosi(T) _hot;
		BinNodePosi(T) connect34(
				BinNodePosi(T),BinNodePosi(T),BinNodePosi(T),
				BinNodePosi(T),BinNodePosi(T),BinNodePosi(T),BinNodePosi(T));
		BinNodePosi(T) rotateAt(BinNodePosi(T) x);
	public:
		int root_height(){return _root->height;}
		virtual BinNodePosi(T) & search(const T& e);	
		virtual BinNodePosi(T) insert(const T& e);
		virtual bool remove(const T& e);
};
#include "bst_imp.h"
#endif
