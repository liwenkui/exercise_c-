#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> l1{1, 3, 4, 6}, l2{2, 4, 7, 9};
    l1.sort();
    l2.sort();
    l1.merge(l2);
    l1.reverse();
    for (auto i : l1)
        cout << i << " ";
    cout << endl;
    return 0;
}