#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 5, 6, 6, 5, 7, 8, 9};
    list<int> ils{0, 1, 2, 3, 4, 5, 5, 6, 6, 5, 7, 8, 9};
    cout << count(ivec.begin(), ivec.end(), 5) << endl;
    cout << count(ils.begin(), ils.end(), 5) << endl;
    return 0;
}
