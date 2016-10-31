#include "set.h"
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    vector<int> a1 = {0, 1, 2}, a2 = {2, 3, 4}, a3 = {3, 4, 5};
    Set<int> set1(a1), set2(a2), set3(a3);
    Set<int> set4;
    set4 = (set1 + set3 - set2) & set3;
    set4.print();
    return 0;
}