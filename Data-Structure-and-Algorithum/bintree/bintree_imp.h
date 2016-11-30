#include "bintree.h"
#include <iostream>
#include <algorithm>

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
	return x->height=1+std::max(stature(x->lc),stature(x->rc));
}
template<typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x){
	while(x){
		int P_height = x->height;
		updateHeight(x);
		if(x->height==P_height) break;
		x=x->parent;
	}
}

template<typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const &e){
	_size=1;
	return _root=new BinNode<T>(e);
}
template<typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x,T const&e)
{
	++_size;
	x->insertAsLC(e);
	updateHeightAbove(x);
	return x->lc;
}
template<typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x,T const&e){
	++_size;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rc;
}

template<typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S){
	if((x->lc = S->_root))
		x->lc->parent = x;
	_size+=S->_size;
	updateHeightAbove(x);
	S->_root=nullptr;// 把s的资源交给x节点，将根结点清空
	S->_size=0;
	release(S);
	S=nullptr;
	return x;
}
template<typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S){
	if((x->rc = S->_root))
		x->rc->parent = x;
	_size+=S->_size;
	updateHeightAbove(x);
	S->_root=nullptr;// 把s的资源交给x节点，将根结点清空
	S->_size=0;
	release(S);
	S=nullptr;
	return x;
}
template<typename T>
static int removeAt(BinNodePosi(T) x){
	if(!x) return 0;
	int n = 1+removeAt(x->lc)+removeAt(x->rc);
	release(x->data);
	release(x);
	return n;
}
template<typename T>
int BinTree<T>::remove(BinNodePosi(T) x){
	FromParentTo(*x)=nullptr;
	updateHeightAbove(x->parent);
	int n=removeAt(x);
	_size-=n;
	return n;
}

template<typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x){
	FromParentTo(*x) = nullptr;
	updateHeightAbove(x->parent);
	BinTree<T>* S =new BinTree<T>;
	S->root=x;
	x->parent=nullptr;
	S->_size=x->size();
	_size-=S->_size;
	return S;
}
template<typename T>
void BinTree<T>::swap(BinNodePosi(T) x){
	if(!x) return;
	if(x->lc&&x->rc)
	std::swap(x->lc->data,x->rc->data);
	swap(x->lc);
	swap(x->rc);
}
template<typename T>
bool BinTree<T>::compare(Stack<BinNodePosi(T)>& path,BinNodePosi(T) p,T& sum){
	if(!p)return true;
	if(p->data>sum){
		path.push(p);
		cout<<"push elements "<<p->data<<endl;
		sum+=p->data;
	}else return false;
	if(HasLChild(*p)){
		compare(path,p->lc,sum);
		sum-=path.pop()->data;
	}
	if(HasRChild(*p)){
		compare(path,p->rc,sum);
		sum-=path.pop()->data;
	}
	if(path.size()==1) return true;
}

template<typename T>
void BinTree<T>::exchange(BinNodePosi(T) x){
	if(!x)return;
	exchange(x->lc);
	exchange(x->rc);
	if(HasLChild(*x)&&HasRChild(*x))
		x->data=std::max(x->data,std::max(x->lc->data,x->rc->data));
	else if(HasLChild(*x))
		x->data=std::max(x->data,x->lc->data);
	else if(HasRChild(*x))
		x->data=std::max(x->data,x->rc->data);
}


