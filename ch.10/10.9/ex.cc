#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void my_elimDups(vector<int> &ints)
{
    sort(ints.begin(), ints.end());
    auto end_unique = unique(ints.begin(), ints.end());
    ints.erase(end_unique, ints.end());
}
int main()
{
    vector<int> ivec{5, 3, 2, 1, 4, 5, 6, 5, 2, 3, 4, 7, 8, 9, 6, 5, 7};
    my_elimDups(ivec);
    for (auto c : ivec)
        cout << c << " ";
    cout << endl;
    return 0;
}