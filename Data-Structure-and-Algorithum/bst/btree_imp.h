#include "btree.h"
#include "btree_solveunderflow.h"

template<typename T>
BTNodePosi(T) BTree<T>::search(const T&e){
	BTNodePosi(T) v=_root;
	BTNodePosi(T) _hot=nullptr;
	while(v){
		Rank r = v->key.search(e);
		if((0<=r)&&(e==v->key[r])) return v;
		_hot=v;
		v=v->child[r+1];
	}
	return nullptr;
}

template<typename T>
bool BTree<T>::insert(const T&e){
	BTNodePosi(T) v = search(e);
	if(v) return false;
	Rank r = _hot->key.search(e);
	_hot->key.insert(r+1,e);
	_hot->child.insert(r+2,nullptr);
	_size++;
	solveOverflow(_hot);
	return true;
}

template<typename T>
void BTree<T>::solveOverflow(BTNodePosi(T) v){
	if(_order>=v->child.size()) return;
	Rank s = _order/2;
	BTNodePosi(T) u=new BTNode<T>();//新结点以有一个空孩子
	for(Rank j=0;j<_order-s-1;j++){
		u->child.insert(j,v->child.remove(s+1));
		u->key.insert(j,v->key.remove(s+1));
	}
	u->child[_order-s-1]=v->child.remove(s+1);
	if(u->child[0])
		for(Rank j=0;j<_order-s;j++)
			u->child[j]->parent=u;
	BTNodePosi(T) p=v->parent;
	if(!p) {_root=p=new BTNode<T>();p->child[0]=v;v->parent=p;}
	Rank r=1+p->key.search(v->key[0]);
	p->key.insert(r,v->key.remove(s));
	p->child.insert(r+1,u);u->parent=p;
	solveOverflow(p);
}
template<typename T>
bool BTree<T>::remove(const T&e){
	BTNodePosi(T) v=search(e);
	if(!v) return false;
	Rank r=v->key.search(e);
	if(v->child[0]){
		BTNodePosi(T) u=v->child[r+1];
		while(u->child[0]) u=u->child[0];
		v->key[r]=u->key[0];
		v=u;
		r=0;
	}
	v->key.remove(r);v->child.remove(r+1);
	_size--;
	solveUnderflow(v);
	return true;
}
