#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<typename ITE,typename T>
ITE my_find(ITE begin,ITE end,T const &e){
	for(;begin!=end;begin++)
		if(*begin==e)return begin;	
}

int main(int argc,char *argv[]){
	vector<int> ivec{1,2,3,4,5,6,7};
	auto posi = ivec.cend() != my_find(ivec.cbegin(),ivec.cend(),4);
	cout<<(posi?"found\n":"not found\n");	
	return 0;
}


