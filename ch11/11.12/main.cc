#include <utility>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<pair<string,string>> pa;
	string first,second;
	while(cin>>first)
		if(cin>>second){
			pa.emplace_back(first,second);
			//pa.push_back({first,second});		
			//pa.push_back(pair<string,string>(first,second));
			//pa.push_back(make_pair(first,second));	
		}
	cout<<pa.size()<<endl;
	return 0;
}
