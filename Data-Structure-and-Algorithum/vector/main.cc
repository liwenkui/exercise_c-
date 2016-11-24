#include "vector.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	Vector<int> ivec;
	for(int i=0;i<100;i++)
	ivec.insert(0,i);
	ivec.unsort();
	ivec.sort();
	for(int i=0;i<100;i++)
		cout<<ivec[i]<<' ';
	cout<<endl;
			
	return 0;
}

