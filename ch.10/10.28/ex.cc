#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
template <typename Seq>
void print(Seq const &seq)
{
    for (const auto i : seq)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1, lst2, lst3, lst4;
    copy(vec.cbegin(), vec.cend(), back_inserter(lst1));
    copy(vec.cbegin(), vec.cend(), front_inserter(lst2));
    copy(vec.cbegin(), vec.cend(), inserter(lst3, lst3.begin()));
    copy(vec.cbegin(), vec.cend(), inserter(lst4, lst4.end()));
    print(lst1);
    print(lst2);
    print(lst3);
    print(lst4);
    return 0;
}