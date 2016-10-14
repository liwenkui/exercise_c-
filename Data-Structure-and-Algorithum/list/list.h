#ifndef LIST
#define LIST
#include "ListNode.h"
template <typename T>
class List
{
  private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;

  protected:
    void init();

  public:
    List() { init(); }
};
#endif