#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> ivec;
    fill_n(back_inserter(ivec), 10, 0);
    for (auto c : ivec)
        cout << c << " ";
    cout << endl;
    return 0;
}