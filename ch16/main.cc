#include <iostream>
#include "Blob.h"

using namespace std;
int main(){
	Blob<string> articles = {"a","an","the"};
	for(int i=0;i<3;i++)
		cout<<articles[i]<<' ';
	cout<<endl;
	Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
	for(size_t i=0;i<squares.size();++i)
		squares[i]=i*i;
	for(size_t i=0;i<squares.size();++i)
		cout<<squares[i]<<' ';
	cout<<endl;
	return 0;
}
