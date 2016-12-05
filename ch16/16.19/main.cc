#include <iostream>
#include <vector>
#include <string>
using namespace std;
template<typename T>
void print(T& container){
//	for(typename T::size_type iter=0;iter!=container.size();iter++)
//		cout<<container[iter]<<' ';
//	cout<<endl;
	for(auto iter=container.begin();iter!=container.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;
}

int main(){
	vector<int> ivec{1,2,3,4,5,6,7,8,9,0};
	string str="hello word!";
	print(ivec);
	print(str);
	return 0;
}
