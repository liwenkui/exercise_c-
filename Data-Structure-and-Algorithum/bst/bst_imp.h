#include "bst.h"
#include "../release.h"

//template<typename T>
//static BinNodePosi(T)& searchIn(BinNodePosi(T) &v,const T& e,BinNodePosi(T)& hot){
//	if(!v||(e==v->data))return v;
//	hot=v;	
//	return searchIn(((e<v->data)?v->lc:v->rc),e,hot);
//}
template<typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T) &v,const T& e,BinNodePosi(T)& hot){
	if(!v||(e==v->data)) return v;
	hot=v;
	while(1){
		BinNodePosi(T) &c=(e<hot->data)?hot->lc:hot->rc;
		if(!c||(e==c->data)) return c;
		hot=c;
	}
}

template<typename T>
BinNodePosi(T)& BST<T>::search(const T& e)
{return searchIn(_root,e,_hot = nullptr);}

template<typename T>
BinNodePosi(T) BST<T>::insert(const T& e){
	BinNodePosi(T) &x = search(e);
	if(x) return x;
	x = new BinNode<T>(e,_hot);
	_size++;
	updateHeightAbove(x);
	return x;
}
template<typename T>
bool BST<T>::remove(const T& e){
	BinNodePosi(T) &x = search(e);
	if(!x) return false;
	removeAt(x,_hot);
	_size--;
	updateHeightAbove(_hot);
	return true;
}

template<typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) &x,BinNodePosi(T)& hot){
	BinNodePosi(T) w=x;
	BinNodePosi(T) succ=nullptr;
	srand(100);
	if(!HasLChild(*x))
		succ=x=x->rc;
	else if(!HasRChild(*x))
		succ=x=x->lc;
	else{
		//if(1){
		if(rand()%2){
			w=w->succ();
			swap(x->data,w->data);
			BinNodePosi(T) u=w->parent;
			((u==x)?u->rc:u->lc)=succ=w->rc;
		}else{
			w=w->pred();
			swap(x->data,w->data);
			BinNodePosi(T) u=w->parent;
			((u==x)?u->lc:u->rc)=succ=w->lc;
		}
	}
	hot=w->parent;
	if(succ) succ->parent=hot;
	release(w->data);
	release(w);
	return succ;
}
