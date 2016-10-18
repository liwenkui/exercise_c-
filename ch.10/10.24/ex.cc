#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool cheak_size(string const &str, size_t sz)
{
    return str.size() < sz;
}
int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string str{"123456"};
    auto result = find_if(ivec.begin(), ivec.end(), bind(cheak_size, str, _1));
    if (result != ivec.end())
        cout << *result << endl;
    else
        cout << "Not found" << endl;
    return 0;
}