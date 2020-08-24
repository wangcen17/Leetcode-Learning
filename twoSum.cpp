//Given a target, find the index of the two nums
//in the array
//Leetcode 1:

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <time.h>
using namespace std;

class twoSum{
public:
	vector<int> BruteWay(vector<int> &nums, int target);
	//use map and space to save time;
	vector<int> mapWay(vector<int> &nums, int target);
	void printArray(const vector<int> nums)
	{
		for(auto i : nums)
		{
			cout << i << endl;
		}
	}	
};

vector<int> twoSum::BruteWay(vector<int> &nums, int target)
{
	int size = nums.size();
	
	for(int i = 0; i < size; ++i)
	{
		for(int j = i+1; j < size; ++j)
		{
			if(nums[i] + nums[j] == target)
			{
				return {i, j};
			}
		}
	}
	return {0, 0};
	
}

vector<int> twoSum::mapWay(vector<int> &nums, int target)
{
	vector<int> reserve;
	
	unordered_map<int, int> hash;
	for(int i = 0; i < nums.size(); ++i)
	{
		int tmp = target - nums[i];
		if(hash.find(tmp) != hash.end())
		{
			res.push_back(hash[temp]);
			res.push_back(i);
		}
		else
		{
			hash[nums[i]] = i;
		}
	}
	return res;
}


int main()
{
	clock_t start,end;
	vector<int> result;
	vector<int> nums = {2,1,5,7,3,4};
	
	twoSum test;
	start = clock();
	result = test.BruteWay(nums, 12);
	end = clock();
	cout << "time is " << start - end << endl;
	test.printArray(result);

	return 0;
}