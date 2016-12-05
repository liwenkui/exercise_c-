#include "splay.h"

template<typename NodePosi> inline
void attachAsLChild(NodePosi p,NodePosi lc){p->lc=lc;if(lc) lc->parent=p;}

template<typename NodePosi> inline
void attachAsRChild(NodePosi p,NodePosi rc){p->rc=rc;if(rc) rc->parent=p;}

template<typename T>
BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v){
	if(!v) return nullptr;
	BinNodePosi(T) p;
	BinNodePosi(T) g;
	while((p=v->parent)&&(g=p->parent)){
		BinNodePosi(T) gg=g->parent;
		if(IsLChild(*v))
			if(IsLChild(*p)){
				attachAsLChild(g,p->rc);attachAsLChild(p,v->rc);
				attachAsRChild(p,g);attachAsRChild(v,p);
			}else{
				attachAsRChild(g,v->lc);attachAsLChild(p,v->rc);
				attachAsLChild(v,g);attachAsRChild(v,p);
			}
		else if(IsRChild(*p)){
			attachAsRChild(g,p->lc);attachAsRChild(p,v->lc);
			attachAsLChild(p,g);attachAsLChild(v,p);
		}else{
			attachAsRChild(p,v->lc);attachAsLChild(g,v->rc);
			attachAsLChild(v,p);attachAsRChild(v,g);
		}
		if(!gg) v->parent=nullptr;
		else
			(g==g->lc)?attachAsLChild(gg,v):attachAsRChild(gg,v);
		updateHeight(g);
		updateHeight(p);
		updateHeight(v);
	}
	if((p=v->parent)){
		if(IsLChild(*v)){
			attachAsLChild(p,v->rc);attachAsRChild(v,p);}
		else{
			attachAsRChild(p,v->lc);attachAsLChild(v,p);}
		updateHeight(p);
		updateHeight(v);
	}
	v->parent=nullptr;
	return v;
}

template<typename T>BinNodePosi(T)& Splay<T>::search(const T&e){
	BinNodePosi(T) p=searchIn(_root,e,_hot=nullptr);
	_root=splay(p?p:_hot);
	return _root;
}
template<typename T>BinNodePosi(T) Splay<T>::insert(const T&e){
	if(!_root){
		_size++;return _root = new BinNode<T>(e);}
	if(e==search(e)->data) return _root;
	_size++;BinNodePosi(T) t=_root;
	if(_root->data<e){
		t->parent = _root =new BinNode<T>(e,nullptr,t,t->rc);
		if(HasRChild(*t)){t->rc->parent = _root;t->rc=nullptr;}
	}else{
		t->parent = _root = new BinNode<T>(e,nullptr,t->lc,t);
		if(HasLChild(*t)){t->lc->parent = _root;t->lc=nullptr;}
	}
	updateheightAbove(t);
	return _root;
}
template<typename T>
bool Splay<T>::remove(const T&e){
	if(!_root||(e!=searchIn(e)->data)) return false;
	BinNodePosi(T) w=_root;
	if(!HasLChild(*_root)){
		_root=_root->rc;if(_root)_root->parent=nullptr;
	}else if(!HasRChild(*_root)){
		_root=_root->lc;if(_root)_root->parent=nullptr;
	}else{
		BinNodePosi(T) lTree = _root->lc;
		lTree->parent=nullptr;_root->lc=nullptr;
		_root=_root->rc;_root->parent=nullptr;
		search(w->data);
		_root->lc=lTree;lTree->parent=_root;
	}
	release(w->data);release(w);_size--;
	if(_root) updateHeight(_root);
	return true;
}
