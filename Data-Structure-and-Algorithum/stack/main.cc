#include "stack.h"
#include <iostream>

using namespace std;
void convert(Stack<char>& S,long long n,int base){
	static char digit[]=
	{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	if(0<n){
		S.push(digit[n%base]);
		convert(S,n/base,base);
	}
}
int main(){
	Stack<char> output;
	convert(output,829184930382942357,16);
	while(output.size()!=0)
		cout<<output.pop()<<' ';
	cout<<endl;
	return 0;
}
