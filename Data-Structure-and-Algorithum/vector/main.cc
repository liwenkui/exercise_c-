#include "vector.h"
#include <iostream>
using namespace std;
int main()
{
    Vector<int> iVec;
	for(int i=0;i<100;i++)
	iVec.insert(0,i);
	iVec.disordered();
	for(int i=0;i<100;i++)
	cout<<iVec[i]<<" ";
	cout<<endl;	
    return 0;
}
