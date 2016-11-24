#ifndef LIST
#define LIST
#include "ListNode.h"
typedef int Rank;
template <typename T>
class List
{
private:
  int _size;
  ListNodePosi(T) header;
  ListNodePosi(T) trailer;

protected:
  void init();
  void copyNodes(ListNodePosi(T), int);
  int clear();
  void merge(ListNodePosi(T)&,int ,List<T>&,ListNodePosi(T),int);
  void mergeSort(ListNodePosi(T)&,int);
  void selectionSort(ListNodePosi(T), int);
  void insertionSort(ListNodePosi(T), int);

public:
  //constructor
  List() { init(); }
  List(List<T> const&L){
	   copyNodes(L.first(),L._size);}
  List(List<T> const&L,Rank r,int n){
	  copyNodes(L[r],n);}
  List(ListNodePosi(T) p,int n){
	  copyNodes(p,n);}
  //distructor
  ~List();
  //read interface
  Rank size() const {return _size;}
  bool empty() const { return _size<=0;}
  T &operator[](Rank r) const;
  ListNodePosi(T) first() const { return header->succ; }
  ListNodePosi(T) last() const { return trailer->pred; }
  bool valid(ListNodePosi(T) p)
  {return p&&(trailer!=p)&&(header!=p);}
  int disordered() const;
  ListNodePosi(T) find(T const &e) const { return find(e, _size, trailer); }
  ListNodePosi(T) find(T const &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) search(T const &e)const {return search(e,_size,trailer);}
  ListNodePosi(T) search(T const &e,int n,ListNodePosi(T) p) const;
  ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
  ListNodePosi(T) selectMax() { return slectMax(header->succ, _size); }
  //write
  ListNodePosi(T) insertA(ListNodePosi(T), T const &);
  ListNodePosi(T) insertB(ListNodePosi(T), T const &);
  ListNodePosi(T) insertAsFirst(T const &);
  ListNodePosi(T) insertAsLast(T const &);
  T remove(ListNodePosi(T) p);
  void merge(List<T>& L){merge(first(),_size,L,L.first(),L._size);}
  void sort(){sort(first(),_size);}
  void sort(ListNodePosi(T) p,int n);
  int deduplicate();
  int uniquify();
  void reverse();
  //traverse
  template<typename VST>
	  void traverse(VST &);
};

template <typename T>
void List<T>::init()
{
  header = new ListNode<T>;
  trailer = new ListNode<T>;
  header->succ = trailer;
  header->pred = nullptr;
  trailer->succ = nullptr;
  trailer->pred = header;
  _size = 0;
}

template <typename T>
T &List<T>::operator[](Rank r) const
{
  ListNodePosi(T) p = first();
  while (0 < r--)
  {
    p = p->succ;
  }
  return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::find(T const &e, int n, ListNodePosi(T) p) const
{
  while (0 < n--)
  {
    if ((p = p->pred)->data == e)
      return p;
  }
  return nullptr;
}
template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const &e)
{
  _size++;
  return p->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const &e)
{
  _size++;
  return p->insertAsSucc(e);
}
template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
  init();
  while (n--)
  {
    insertAsLast(p->data);
    p = p->succ;
  }
}
template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const &e)
{
  _size++;
  return header->insertAsSucc(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const &e)
{
  _size++;
  return trailer->insertAsPred(e);
}
template <typename T>
T List<T>::remove(ListNodePosi(T) p)
{
  T e = p->data;
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  _size--;
  delete p;
  return e;
}
template <typename T>
int List<T>::clear()
{
  int oldSize = _size;
  while (0 < _size)
    remove(header->succ);
  return oldSize;
}
template <typename T>
List<T>::~List<T>()
{
  clear();
  delete header;
  delete trailer;
}
template <typename T>
int List<T>::deduplicate()
{
  if (_size < 2)
    return 0;
  int oldSize = _size;
  ListNodePosi(T) p=header;
  Rank r = 0;
  while (trailer != (p = p->succ))
  {
    ListNodePosi(T) q = find(p->data, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n)
{
  ListNodePosi(T) max = p;
  for (ListNodePosi(T) cur = p; 1 < n; n--)
  {
    if (((cur = cur->succ)->data) >= (max->data))
      max = cur;
  }
  return max;
}
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n){
	for(int r=0;r<n;r++){
		insertA(search(p->data,r,p),p->data);
		p=p->succ;
		remove(p->pred);
	}
}
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n)
{
  ListNodePosi(T) head = p->pred, tail = p;
  for (int i = 0; i < n; i++)
    tail = tail->succ;
  while (1 < n)
  {
    ListNodePosi(T) max = selectMax(head->succ, n);
    //insertB(tail, remove(max));
	//swap(tail->pred->data,max->data);
	if(tail->pred!=max)
		swap(tail->pred->data,max->data);
    tail = tail->pred;
    n--;
  }
}
template<typename T>
int List<T>::uniquify(){
	if(_size<2) return 0;
	int oldSize=_size;
	ListNodePosi(T) p=first();
	ListNodePosi(T) q;
	while(trailer!=(q=p->succ))
		if(p->data!=q->data)
			p=q;
		else remove(q);
	return oldSize-_size;
}
template<typename T>
ListNodePosi(T) List<T>::search(T const& e,int n,ListNodePosi(T) p)const{
	while(0<=n--)
		if(((p=p->pred)->data)<=e)break;
	return p;
}

template<typename T> template<typename VST>
void List<T>::traverse(VST& visit){
	for(ListNodePosi(T) p=header->succ;p!=trailer;p=p->succ)
		visit(p->data);
}
template<typename T>
void List<T>::mergeSort(ListNodePosi(T)& p,int n){
	if(n<2) return;
	int m=n>>1;
	ListNodePosi(T) q=p;
	for(int i=0;i<m;i++)
		q=q->succ;
	mergeSort(p,m);
	mergeSort(q,n-m);
	merge(p,m,*this,q,n-m);
}

template<typename T>
void List<T>::merge(ListNodePosi(T) &p,int n,List<T> &L,ListNodePosi(T) q,int m){
	ListNodePosi(T) pp = p->pred;
	while(0<m)
		if((0<n)&&(p->data<=q->data)){
			if(q==(p=p->succ))
				break;
			n--;
		}else{
			insertB(p,L.remove((q=q->succ)->pred));
			m--;
		}
	p = pp->succ;
}
template<typename T>
void List<T>::reverse()
{
	ListNodePosi(T) p=header;
	ListNodePosi(T) q=trailer;
	for(int i=1;i<_size();i+=2)
		swap((p=p->succ)->data,(q=q->pred)->data);
}
#endif
