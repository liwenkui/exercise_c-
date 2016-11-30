#include "bintree.h"
#include "tree.h"
#include <iostream>
using namespace std;
int main(){
	BinTree<int> bt;
	auto s = bt.insertAsRoot(1);
	auto s1= bt.insertAsRC(s,2);
	auto s2= bt.insertAsLC(s,3);
	auto s3= bt.insertAsRC(s1,4);
	auto s5= bt.insertAsLC(s1,6);
	auto s4= bt.insertAsLC(s2,5);
	auto s6= bt.insertAsRC(s2,7);
	//Stack<BinNode<int>*> S;//5-24
	//int a=0;
	//cout<<bt.compare(S,s,a)<<endl;
	bt.exchange(s);
	cout<<s->data<<" ";
	cout<<s1->data<<" ";
	cout<<s2->data<<" ";
	cout<<s3->data<<" ";
	cout<<s4->data<<" ";
	cout<<s5->data<<" ";
	cout<<s6->data<<" ";
	cout<<endl;
	return 0;
}
