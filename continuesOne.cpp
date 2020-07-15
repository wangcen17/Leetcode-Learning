#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> zeroIndex;
        vector<int> oneLen;
		if(nums.size() == 1)
		{
			return nums[0] == 1?1:0;
		}
        for(int i = 0; i < nums.size(); ++i)
        {
            if(1 != nums[i])
            {
                zeroIndex.push_back(i);
            }
        }
        
		printVector(zeroIndex);
        for(int j = zeroIndex.size()-1; j > 0; --j)
        {
            oneLen.push_back(zeroIndex[j] - zeroIndex[j-1] - 1);
        }
        oneLen.push_back(zeroIndex[0] - 0);
		printVector(oneLen);
        auto max = max_element(oneLen.begin(), oneLen.end());
        return *max;       
    }
	
	void printVector(vector<int> s){
		for(auto i : s)
		{
			cout << i << " ";
		}
		cout << "" << endl;
	}
};

int main() {
	Solution s;
	vector<int> s1 = {0,1};
	int len = s.findMaxConsecutiveOnes(s1);
	cout << "ans = " << len;
    return 0;
}