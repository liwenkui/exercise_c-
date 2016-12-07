#include "redblack.h"
#define IsBlack(p) (!(p)||(RB_BLACK == (p)->color))
#define IsRed(p) (!IsBlack(p))
#define BlackHeightUpdated(x) (\
		(stature((x).lc))==stature((x).rc)&&\
		((x).height==(IsRed(&x)?stature((x).lc):stature((x).lc)+1))\
		)
template<typename T>
int RedBlack<T>::updateHeight(BinNodePosi(T) x){
	x->height=max(stature(x->lc),stature(x->rc));
	return IsBlack(x)?x->height++:x->height;
}

template<typename T>
BinNodePosi(T) RedBlack<T>::insert(const T&e){
	BinNodePosi(T)& x=search(e);
	if(x) return x;
	x = new BinNode<T>(e,_hot,nullptr,nullptr,-1);
	_size++;
	solveDoubelRed(x);
	return x?x:_hot->parent;
}

template<typename T>
void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x){
	if(IsRoot(*x))
	{_root->color=RB_BLACK;_root->height++;return;}
	BinNodePosi(T) p=x->parent; if(IsBlack(p)) return;
	BinNodePosi(T) g=p->parent;
	BinNodePosi(T) u=uncle(x);
	if(IsBlack(u)){
		if(IsLChild(*x)==IsLChild(*p))
			p->color=RB_BLACK;
		else
			x->color=RB_BLACK;
		g->color=RB_RED;
		BinNodePosi(T) gg=g->parent;
		BinNodePosi(T) r=FromParentTo(*g)=rotateAt(x);
		r->parent=gg;
	}else{
		p->color=RB_BLACK;p->height++;
		u->color=RB_BLACK;u->height++;
		if(!IsRoot(*g))g->color=RB_RED;
		solveDoubelRed(g);
	}
}
template<typename T>
bool RedBlack<T>::remove(const T&e){
	BinNodePosi(T) &x=search(e);
	if(!x) return false;
	BinNodePosi(T) r=removeAt(x,_hot);
	if(!(--_size))return true;
	if(!_hot)
	{_root->color=RB_BLACK;updateHeight(_root);return true;}
	if(BlackHeightUpdated(*_hot)) return true;
	if(IsRed(r))
	{r->color=RB_BLACK;r->height++;return true;}
	solveDoubleBlack(r);
	return true;
}
#include "redblack_solvedoubleblack.h"

