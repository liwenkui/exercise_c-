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