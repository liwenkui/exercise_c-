#ifndef CIRCULAR_LIST
#define CIRCULAR_LIST
#include "ListNode.h"
typedef int Rank;
template <typename T>
class Circular_List{
	private:
		ListNodePosi(T)  head;
		int _size;
	public:
		Circular_List():head(nullptr),_size(0){}
		Circular_List(T const&e1,T const & e2):head(new ListNode<T>(e1)),_size(2){
            auto p=new ListNode<T>(e2);
            head->succ=p;
			head->pred=p;
			p->pred=head;
			p->succ=head;
		}
		~Circular_List(){
			auto p=head;
			while(head!=(p=p->succ))
					delete p;
			delete head;
		}
		ListNodePosi(T) insertA(ListNodePosi(T) p,T const & e){
			ListNodePosi(T) q=new ListNode<T>(e,p,p->succ);
            p->succ=q;
			q->succ->pred=q;
			++_size;
			return q;
		}
		ListNodePosi(T) first() const {return head;}
		T& operator[](Rank r)const{
			auto p=head;
			while(0<r--){
				p=(p->succ);
			}
			return p->data;
		}
		Rank size() const {return _size;}
		bool empty() const {return _size<=0;}
		ListNodePosi(T) remove(ListNodePosi(T) p){
			auto q=p->succ;
			p->pred->succ=p->succ;
			p->succ->pred=p->pred;
			delete p;
			--_size;
			return q;
		}
};
#endif
