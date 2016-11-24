#include "Circular_list.h"
#include <iostream>
using namespace std;

template<typename T>
void josephus(Circular_List<T> & cls,int n,int k){
	auto p = cls.first();
	int cnt=0;
	while(cls.size()>1){
		for(int i=0;i<k;i++){
			p=p->succ;
			++cnt;
		}
		cout<<p->data<<' ';
		p=cls.remove(p);
	}
    cout<<endl;
	cout<<cls.size()<<endl;
	cout<<p->data<<endl;
	cout<<cnt<<endl;
}

int main(){
	Circular_List<int> cls(1,2);
	for(int i=3;i<100;i++)
		cls.insertA(cls.first(),i);
	cout<<"inital size is "<<cls.size()<<endl;
	josephus(cls,cls.size(),10);	
	return 0;
}
