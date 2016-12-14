#include <set>
#include <iostream>
using namespace std;
int main(){
	set<int> s{1,2,3,4,5,6,7};
	auto p=s.insert(8);
	auto p1=s.insert(8);
	cout<<*(p.first)<<' '<<p.second<<endl;
	cout<<*(p1.first)<<' '<<p1.second<<endl;
	return 0;
}
