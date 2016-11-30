#ifndef TREE_H
#define TREE_H
#include "bintree.h"
template<typename T>
class Tree:public BinTree<T>{
	private:
	protected:
		int updateHeight(BinNodePosi(T) x){
			if(FirstChild(x)){
			BinNodePosi(T) s=x->lc;
			int max=s->height;
			while((s=s->rc))
				if(s->height>max) max = s->height;
			return x->height=1+max;
			}
			return 0;
		}	
		int updateHeightAbove(BinNodePosi(T) x){
		}
	public:
		using BinTree<T>::insertAsLC;
		using BinTree<T>::insertAsRC;
		using BinTree<T>::size;
		BinNodePosi(T) insertAsChild(BinNodePosi(T) x,T const &e);
		BinNodePosi(T) FirstChild(BinNodePosi(T) x){return x->lc;}
		BinNodePosi(T) NextChild(BinNodePosi(T) x){return x->rc;}
		BinNodePosi(T) LastChild(BinNodePosi(T) x){ 
			while(HasRChild(*x))
				x=x->rc;
			return x;}
		
};
template<typename T>
BinNodePosi(T) Tree<T>::insertAsChild(BinNodePosi(T) x,T const &e){
	BinNodePosi(T) s=x;
	if(!s->lc)	
		return insertAsLC(s,e);
	else{
		s=s->lc;
		while(HasRChild(*s))
			s=s->rc;
		return insertAsRC(s,e);
	}
}

#endif

