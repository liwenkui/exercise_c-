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

public:
  //constructor
  List() { init(); }
  //distructor
  ~List();
  //read interface
  T &operator[](Rank r) const;
  ListNodePosi(T) first() const { return header->succ; }
  ListNodePosi(T) last() const { return trailer->pred; }
  //
  ListNodePosi(T) find(T const &e) const { return find(e, _size, trailer); }
  ListNodePosi(T) find(T const &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) insertA(ListNodePosi(T), T const &);
  ListNodePosi(T) insertB(ListNodePosi(T), T const &);
  ListNodePosi(T) insertAsFirst(T const &);
  ListNodePosi(T) insertAsLast(T const &);
  T remove(ListNodePosi(T) p);
  //
  int deduplicate();
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
  ListNodePosi(T) p;
  Rank r = 1;
  while (trailer != (p = p->succ))
  {
    ListNodePosi(T) q = find(p->data, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}
#endif