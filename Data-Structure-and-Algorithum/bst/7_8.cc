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
	double height=0.0;
	int t=100;
	while(--t){
		for(int i=num-1;i!=0;--i)
			swap(ivec[i],ivec[rand()%i]);
		BST<int> bst;	
		for(auto i:ivec){
			//cout<<j<<' ';
			bst.insert(i);
			//cout<<bst.root()->height<<' ';
		}
		//cout<<endl;
		height+=bst.root_height();
		//cout<<height<<' ';
	}
	cout<<"when num= "<<num<<endl;
	cout<<"average height= "<<height/100<<endl;
	cout<<"[log2n]= "<<int(log(num)/log(2))<<endl;
	cout<<"sqrt(n)= "<<sqrt(num)<<endl;
	return 0;
}
