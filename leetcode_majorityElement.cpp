#include<iostream>
#include<algorithm>
#include<stdio.h>
#include <vector>
#include<string>
#include<map>
#include <unordered_map>
using namespace std;

//不能放在类中，编译不过；
bool cmp(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
}

class Solution {
public:
	
    int majorityElement(vector<int>& nums) {
		int targetNum = nums.size() >> 1;
		map<int, int> record;
		
		for(auto i : nums){
			record[i]++;
		}
		printMap(record);
		
		vector<pair<int, int>> vec(record.begin(), record.end());
		sort(vec.begin(), vec.end(), cmp);
		printMapInVector(vec);
		
		return vec[0].second >= targetNum ? vec[0].first : -1;
    }
	
	void printMap(map<int, int> input)
	{
		for(auto &iter : input)
		{
			cout << "key: " << iter.first << "value: " << iter.second << endl;
		}
	}
	
	void printMapInVector(vector<pair<int, int>> input)
	{
		for(auto m : input)
		{
			cout << "index: "<< m.first << "value: " << m.second << endl; 
		}
	}
	
	int majorityElement(vector<int>& nums) {	
		int targetNum = nums.size() >> 1;	
		unordered_map<int, int> map_store;//hash
		for(auto i : nums)
		{
			map_store[i]++;
			if(map_store[i] > targetNum){
				return i;
			}
		}
		return -1;
	}
};


int main()
{
	vector<int> input = {1,2,5,9,5,9,5,5,5};
	
	Solution S;
	int result = S.majorityElement(input);
	
	cout <<"result = " << result << endl;
	
	return 0;
}