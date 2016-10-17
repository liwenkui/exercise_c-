#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 5, 6, 6, 5, 7, 8, 9};
    list<double> ils{0, 1, 2, 3, 4, 5, 5, 6, 6, 5, 7, 8, 9.1};
    cout << count(ivec.begin(), ivec.end(), 5) << endl;
    cout << count(ils.begin(), ils.end(), 5) << endl;
    cout << accumulate(ivec.begin(), ivec.end(), 0) << endl;
    cout << equal(ivec.begin(), ivec.end(), ils.begin()) << endl;
    cout << accumulate(ils.begin(), ils.end(), 0) << endl;
    
    return 0;
}
