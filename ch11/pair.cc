#include <utility>
#include <iostream>
using namespace std;
int main(){
	pair<int,int> p(1,2),p2(2,2),p3(0,3),p4(1,1);
	cout<<(p<p2)<<endl;
	cout<<(p<p3)<<endl;
	cout<<(p<p4)<<endl;
	return 0;
}
