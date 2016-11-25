#ifndef BIN_TREE
#define BIN_TREE
#include "binnode.h"
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
		BinNodePosi(T) root() const {return _root;}
		BinNodePosi(T) insertAsRoot(T const&e);
		BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const&e);
		BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const&e);
		BinNodePosi(T) attachAsLC(BinNodePosi(T) x,BinTree<T>* &t);
		BinNodePosi(T) attachAsRC(BinNodePosi(T) x,BinTree<T>* &t);
		int remove(BinNodePosi(T) x);
		BinTree<T>* secede(BinNodePosi(T) x);
		template<typename VST>
			void travLevel(VST& visit){if(_root)_root->travLevel(visit);}
		
};
#endif
