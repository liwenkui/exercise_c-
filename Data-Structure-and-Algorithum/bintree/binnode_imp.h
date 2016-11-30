#include "binnode.h"
#include <cstdlib>
#include "../release.h"
#include "../stack/stack.h"
#include "../queue/queue.h"
template<typename T> 
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
	return lc = new BinNode(e,this);
}

template<typename T> 
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
	return rc = new BinNode(e,this);
}

template <typename T> template <typename VST> 
void BinNode<T>::travIn ( VST& visit ) {  
	switch ( rand() % 5 ) { 
		case 1: travIn_I1 ( this, visit ); break; 
		case 2: travIn_I2 ( this, visit ); break; 
		case 3: travIn_I3 ( this, visit ); break; 
		case 4: travIn_I4 ( this, visit ); break; 
		default: travIn_R ( this, visit ); break; 
	}
}
template <typename T> template <typename VST> 
void BinNode<T>::travPre ( VST& visit ) { 
	switch ( rand() % 5 ) { 
		case 1: travPre_I1 ( this, visit ); break; 
		case 2: travPre_I2 ( this, visit ); break; 
		case 3: travPre_I3 ( this, visit ); break; 
		case 4: travPre_I4 ( this, visit ); break; 
		default: travPre_R ( this, visit ); break; 
	}
}
template <typename T> template <typename VST> 
void BinNode<T>::travPost ( VST& visit ) { 
	switch ( rand() % 5 ) { 
		case 1: travPost_I1 ( this, visit ); break; 
		case 2: travPost_I2 ( this, visit ); break; 
		case 3: travPost_I3 ( this, visit ); break; 
		case 4: travPost_I4 ( this, visit ); break; 
		default: travPost_R ( this, visit ); break; 
	}
}

template<typename T>
int BinNode<T>::size(){
	int s=1;
	if(lc)
		s+= lc->size();
	if(rc)
		s+= rc->size();
	return s;
}

template<typename T,typename VST>
void travPre_R(BinNodePosi(T) x,VST& visit){
	if(!x) return;
	visit(x->data);
	travPre_R(x->lc,visit);
	travPre_R(x->rc,visit);
}
template<typename T,typename VST>
void travPost_R(BinNodePosi(T) x,VST& visit){
	if(!x) return;
	travPost_R(x->lc,visit);
	travPost_R(x->rc,visit);
	visit(x->data);
}
template<typename T,typename VST>
void travIn_R(BinNodePosi(T) x,VST& visit){
	if(!x) return;
	travIn_R(x->lc,visit);
	visit(x->data);
	travIn_R(x->rc,visit);
}

template<typename T,typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,Stack<BinNodePosi(T)>& S){
	while(x){
		visit(x->data);
		S.push(x->rc);
		x=x->lc;
	}
}
template<typename T,typename VST>
void travPre_I2(BinNodePosi(T) x,VST& visit){
	Stack<BinNodePosi(T)> S;
	while(true){
		visitAlongLeftBranch(x,visit,S);
		if(S.empty()) break;
		x=S.pop();
	}
}
template<typename T,typename VST>
void travPre_I1(BinNodePosi(T) x,VST& visit){
	Stack<BinNodePosi(T)> S;
	if(x) S.push(x);
	while(!S.empty()){
		x = S.pop();
		visit(x->data);
		if(HasRChild(*x)) S.push(x->rc);
		if(HasLChild(*x)) S.push(x->lc);
	}
}

template<typename T>
static void goAlongLeftBranch(BinNodePosi(T) x,Stack<BinNodePosi(T)>& S){
	while(x){S.push(x);x=x->lc;}
}
template<typename T,typename VST>
void travIn_I1(BinNodePosi(T) x,VST&visit){
	Stack<BinNodePosi(T)> S;
	while(true){
		goAlongLeftBranch(x,S);
		if(S.empty()) break;
		x=S.pop();
		visit(x->data);
		x=x->rc;
	}
}
template<typename T>
BinNodePosi(T) BinNode<T>::succ(){
	BinNodePosi(T) s=this;
	if(rc){
		s=rc;
		while(HasLChild(*s)) s=s->lc;
	}else{
		while(IsRChild(*s)) s=s->parent;
		s=s->parent;
	}
	return s;
}
template<typename T>
BinNodePosi(T) BinNode<T>::pred(){  //5-14 exercise
	BinNodePosi(T) s=this;
	if(lc){
		s=lc;
		while(HasRChild(*s)) s=s->rc;
	}else{
		while(IsLChild(*s)) s=s->parent;
		s=s->parent;
	}
	return s;
}

template<typename T> template <typename VST>
void BinNode<T>::travLeval (VST& visit){
	Queue<BinNodePosi(T)> Q;
	Q.enqueue(this);
	while(!Q.empty()){ BinNodePosi(T) x=Q.dequeue();
		visit(x->data);
		if(HasLChild(*x)) Q.enqueue(x->lc);
		if(HasRChild(*x)) Q.enqueue(x->rc);
	}
}
template<typename T,typename VST>
void travIn_I4(BinNodePosi(T) x,VST& visit){
	while(true)
		if(HasLChild(*x))
			x=x->lc;
		else{
			visit(x->data);
			while(!HasRChild(*x))
				if(!(x=x->succ())) return;
				else visit(x->data);
			x=x->rc;
		}
}

