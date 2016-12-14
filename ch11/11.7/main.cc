#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using Families = map<string,vector<string>>;
int main(){
	Families fm;
	cout<<"input last name "<<endl;
	for(string in;cin>>in;cout<<"input children's name "<<endl)
		for(string cn;cin>>cn;)
			fm[in].push_back(cn);
	cout<<fm.size()<<endl;
	cout<<fm.begin()->second.size()<<endl;
	return 0;
}
