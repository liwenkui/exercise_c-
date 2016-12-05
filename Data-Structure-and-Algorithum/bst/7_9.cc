#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include "bst.h"
#include "entry.h"
using namespace std;
int main(){
	int num=0;
	cin>>num;
	srand((unsigned)time(0));	
	vector<int> ivec(num);
	for(int i=0;i<num;++i)
		ivec[i]=i;
	double b_height=0.0;
	double a_height=0.0;
	double c=0.0;
	int t=1000;
	while(t--){
		for(int i=num-1;i!=0;--i)
			swap(ivec[i],ivec[rand()%i]);
		BST<int> bst;	
		for(auto i:ivec){
			bst.insert(i);
		}
		b_height=bst.root()->height;
		for(int i=0;i<num/2;++i)
			bst.remove(i);
		a_height=bst.root()->height;
		c+=b_height-a_height;
	}
	cout<<c/1000<<endl;
	return 0;
}
