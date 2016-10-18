#include <algorithm>
#include <string>
#include <iostream>
#include <list>
using namespace std;
bool larger(string const &str)
{
    return str.size() - 5;
}
int main()
{
    list<string> str{"hello", "hello1", "hello22"};
    auto end_true = partition(str.begin(), str.end(), larger);
    str.erase(end_true, str.end());
    for (auto const elem : str)
        cout << elem << " ";
    cout << endl;
    return 0;
}