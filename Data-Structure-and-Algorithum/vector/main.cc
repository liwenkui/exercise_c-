#include "vector.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1("abcd"),s2("abdd");
	Vector<char> ch1(s1.c_str(),4),ch2(s2.c_str(),4);
	cout<<(ch1<ch2)<<endl;
	return 0;
}

