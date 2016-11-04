#include "StrVec.h"
#include <memory>
#include <string>
#include <iostream>
using namespace std;

allocator<string> StrVec::alloc;
int main()
{
	StrVec s;
	s.push_back("a");
	s.push_back("b");
	s.push_back("c");
	s.push_back("d");
	s.push_back("f");
	cout << s.size() << " " << s.capacity() << endl;
	return 0;
}
