#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> ret;
			for(auto i=nums.cbegin();i!=nums.cend();i++)
				for(auto j=i+1;j!=nums.cend();j++)
					if((*i+*j)==target){
						ret.push_back(i-nums.begin());
						ret.push_back(j-nums.begin());
					}
			return ret;
		}
};
