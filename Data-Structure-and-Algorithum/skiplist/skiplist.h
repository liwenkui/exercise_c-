#ifndef SKIPLIST_H
#define SKIPLIST_H
#include "../list/List.h"
#include "../bst/entry.h"
#include "quadlist.h"
#include "../dictionary/dictionary.h"

template<typename K,typename V>
class Skiplist : public Dictionary<K,V>,public List<Quadlist<Entry<K,V>>*>{
	protected:
		bool skipSearch(
				ListNode<Quadlist<Entry<K,V>>*>* &qlist,
				QuadlistNode<Entry<K,V>>* &p,
				K& k);
	public:

};
#endif
