#ifndef LISTNODE
#define LISTNODE
#define ListNodePosi(T) ListNode<T> *
template <typename T>
struct ListNode
{
    //data member
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;
    //constructor
    ListNode() {}
    ListNode(T e, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr)
        : data(e), pred(p), succ(s) {}
    //manipulate interface
    ListNodePosi(T) insertAsPred(T const &e);
    ListNodePosi(T) insertAsSucc(T const &e);
};
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
{
    ListNodePosi(T) x = new ListNode(e, pred, *this);
    pred = x;
    pred->succ = x;
    return x;
}
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const &e)
{
    ListNodePosi(T) x = new ListNode(e, *this, succ);
    succ = x;
    succ->pred = x;
    return x;
}
#endif