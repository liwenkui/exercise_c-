#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <list>
using namespace std;
template <typename Sequence>
ostream &println(Sequence const &seq)
{
    for (auto const &elem : seq)
        cout << elem << " ";
    cout << endl;
    return cout;
}
void my_elimDups(vector<string> &ints)
{
    sort(ints.begin(), ints.end());
    auto end_unique = unique(ints.begin(), ints.end());
    ints.erase(end_unique, ints.end());
}
bool is_shorter(string const &lst, string const &rhs)
{
    return lst.size() < rhs.size();
}
int main()
{
    vector<string> v{"1234", "1234", "hi", "alan", "wen"};
    my_elimDups(v);
    stable_sort(v.begin(), v.end(), is_shorter);
    println(v);
    return 0;
}
