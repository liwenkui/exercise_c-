#include <string>
#include <map>
#include <iostream>
#include <set>
using namespace std;
int main(){
	map<string,size_t> word_count;
	set<string> exclude = {"the","but"};
	string word;
	while(cin>>word){
		auto res=word_count.insert({word,1});
		if(!res.second)
			++res.first->second;
	}
	for(const auto &w:word_count)
		cout<<w.first<<" occurs "<<w.second
			<<((w.second>1)?" times":" time")<<endl;
	word_count.at("a");//Check access to th element with key k
	return 0;
}
