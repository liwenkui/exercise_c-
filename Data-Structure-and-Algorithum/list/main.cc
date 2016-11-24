#include "List.h"
#include <iostream>
using namespace std;

template<typename T>struct Increase
{virtual void operator() (T&e){e++;}};

int main()
{
    List<int> ls;
	for(int i=1;i<=100;i++)
		ls.insertAsLast(i);
//	Increase<int> inc;
//	ls.traverse(inc);
//	for(int i=0;i<100;i++)
//	cout<<ls[i]<<' ';	
//	cout<<endl;
	
    return 0;
}
