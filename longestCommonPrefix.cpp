#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//solution-1
/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        cout << strs.size() << endl;
        if(!strs.size())
        {
            return "";
        }
        
        int sizeOfstrs = strs.size();
        int shortLen = findShortestLen(strs);
		
        for(int i = 0; i < shortLen; ++i)
        {
			for(int j = 1; j < sizeOfstrs; ++j)
			{
				if(strs[0][i] != strs[j][i])
				{
					return strs[0].substr(0, i);
				}
			}
        }
        return strs[0].substr(0, shortLen);
        
    }
    
    int findShortestLen(vector<string>& strs)
    {
        int numOfstring = strs.size();
        int shortLen = 0, len = 0;
        shortLen = strs[0].size();
        for(int i = 1; i < numOfstring; ++i)
        {
            len = strs[i].size();
            shortLen = shortLen < len? shortLen:len;
        }
		cout << "shortLen is" << shortLen << endl;
        return shortLen;
    }
};*/

//solution-2
//先排序，后比较头尾即可
class Solution{
public:
	string longestCommonPrefix(vector<string>& strs) {
		printVector(strs);
		if(strs.empty())
		{
			return "";
		}
		sort(strs.begin(), strs.end());
		printVector(strs);
		string s1 = strs.front(), s2 = strs.back();
		int len = min(s1.size(), s2.size());
		int i;
		for(i = 0; i  < len && s1[i] == s2[i]; ++i){};
		return s1.substr(0, i);
		
	}
	void printVector(vector<string> & arr)
	{
	    for(auto i : arr){
	        cout << i << " " << endl;
	    }
	}	
};

int main() {
    vector<string> arr = {"abcd", "ab", "abdgf"};
	Solution s;
	string ans = s.longestCommonPrefix(arr);
	cout << "ans " << ans << endl;
    return 0;
}