#ifndef BIN_TREE
#define BIN_TREE
#include "binnode.h"
#include "../stack/stack.h"
template<typename T>
class BinTree{
	protected:
		int _size;
		BinNodePosi(T) _root;
		virtual int updateHeight(BinNodePosi(T) x);
		void updateHeightAbove(BinNodePosi(T) x);
	public:
		BinTree():_size(0),_root(nullptr){}
		~BinTree(){if(0<_size)remove (_root);}
		int size() const {return _size;}
		bool empty()const {return !_root;}
		void swap(BinNodePosi(T));
		BinNodePosi(T) root() const {return _root;}
		BinNodePosi(T) insertAsRoot(T const&e);
		BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const&e);
		BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const&e);
		BinNodePosi(T) attachAsLC(BinNodePosi(T) x,BinTree<T>* &t);
		BinNodePosi(T) attachAsRC(BinNodePosi(T) x,BinTree<T>* &t);
		bool compare(Stack<BinNodePosi(T)>&,BinNodePosi(T),T& );
		void exchange(BinNodePosi(T));
			int remove(BinNodePosi(T) x);
			BinTree<T>* secede(BinNodePosi(T) x);
			template<typename VST>
				void travLevel(VST& visit){if(_root)_root->travLevel(visit);}
		template<typename VST>
			void traviPre(VST& visit){if(_root)_root->traviPre(visit);}
		template<typename VST>
			void traviIn(VST& visit){if(_root)_root->traviIn(visit);}
		template<typename VST>
			void traviPost(VST& visit){if(_root)_root->traviPost(visit);}
		bool operator< (BinTree<T> const& t)
		{return _root&&t._root&&lt(_root,t._root);}
		bool operator==(BinTree<T> const& t)
		{return _root&&t._root&&(_root==t._root);}
};
#include "bintree_imp.h"
#endif
