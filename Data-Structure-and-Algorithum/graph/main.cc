#include "GraphMatrix.h"
#include <iostream>
using namespace std;

int main(){
	GraphMatrix<int,int> g;
	g.insert(0);
	g.insert(1);
	g.insert(2);
	g.insert(3);
	g.insert(4);
	g.insert(5,0,2,2);
	cout<<g.exists(2,2)<<endl;
	cout<<g.nextNbr(2,3)<<endl;
	return 0;
}
