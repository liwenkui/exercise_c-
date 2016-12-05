#include "avl.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
	AVL<int> avl;
	vector<BinNode<int>*> bvec;
	int h=0;
	cin>>h;
	h=pow(2,h+1);
	for(int i=0;i<h-1;++i)
		bvec.push_back(avl.insert(i));
	for(auto i:bvec)
		cout<<i->data<<' '<<i->height<<endl;
	cout<<avl.root()->height<<endl;
	return 0;
}
