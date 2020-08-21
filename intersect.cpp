//俩个vector的交集
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

enum waysToFind{
	normal,
	dPointor,
};

class Intersect{
public:

	void findIntersect(vector<int>& nums1, vector<int>& nums2, int wagFlag){
		switch(wagFlag){
			case::normal:
				cout << "enter normal" << endl;
				normalWay(nums1, nums2);
				break;
			case::dPointor:
				cout << "enter here" << endl;
				dPointorWay(nums1, nums2);
				break;
			default:
				break;
		}
	}

	void normalWay(vector<int>& nums1, vector<int>& nums2){
		unordered_map<int, int> t;
		for(auto i : nums1)
		{
			++t[i];
		}
		for(auto j : nums2)
		{
#if 0
			if(t.find(j) != t.end() && --t[j] >= 0)
#endif
			if(--t[j] >= 0)
			{
				result.push_back(j);
			}
		}
	}
	
	void dPointorWay(vector<int>& nums1, vector<int>& nums2){
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		
		int len = nums1.size() > nums2.size() ? nums1.size() : nums2.size();
		
		//cout << "len = " << len << endl;
		
		int i1 = 0, i2 = 0;
		while(i1 < len && i2 < len){
			if(nums1[i1] == nums2[i2]){
				result.push_back(nums1[i1]);
				++i1;
				++i2;
			}
			else if(nums1[i1] < nums2[i2]){
				++i1;
			}
			else{
				++i2;
			}
		}
	}
	
	vector<int> getResult(){
		return result;
	}
	
	void printResult(const vector<int> &num){
		for(auto i : num){
			cout << i << endl;
		}
	}
	
	vector<int> result;
};

int main()
{
	vector<int> nums1 = {1,2,2,1};
	vector<int> nums2 = {2,2,3,1};
	Intersect Sec;
	Sec.findIntersect(nums1, nums2, normal);
	
    vector<int> result = Sec.getResult();
	Sec.printResult(result);
	
	
	return 0;
}