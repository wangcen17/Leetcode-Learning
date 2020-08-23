//a class about the plus including following leetcodes:
// leetcode66：plus one
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class PlusOne{
public:	
	//clever way without plus
	void way1(vector<int> &nums);
	//try to address
	void way2(vector<int> &nums);
	
	void printArray(const vector<int> nums)
	{
		for(auto i : nums)
		{
			cout << i << endl;
		}
	}
};

void PlusOne::way1(vector<int> &nums)
{
	int n = nums.size();
	for(int i = n - 1; i >= 0; i--)
	{
		if(nums[i] == 9)
		{
			nums[i] = 0;
		}
		else
		{
			nums[i]++;
			return;
		}
	}
	
	nums[0] = 1;
	nums.push_back(0);
}

void PlusOne::way2(vector<int> &nums)
{
	bool carry = true;
	
	for(int i = nums.size() - 1; i >= 0 && carry; i--)
	{
		nums[i] = (++nums[i])%10;
		if(nums[i] == 0)
		{
			carry = true;
		}
		else{
			carry = false;
		}
	}
	
	if(carry)
	{
		nums.insert(nums.begin(), 1);
	}
}

int main()
{
	vector<int> nums = {1,2,3};
	PlusOne test;
	test.way2(nums);
	test.printArray(nums);
	return 0;
}