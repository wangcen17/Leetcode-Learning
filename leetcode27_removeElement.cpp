//leetcode 27：
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	//leetcdoe27: remove element without extra space;
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int times = count(nums.begin(), nums.end(), val);
        int startIndex;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size; i++)
        {
            if(nums[i] == val)
            {
                startIndex = i;
                break;
            }
        }
        
        for(int i = startIndex + times; i < size; i++)
        {
            nums[i-times] = nums[i];
        }
        auto iter = nums.end() - times;
        nums.erase(iter, nums.end());
        return size - times;
    }
	
	void printResult(const vector<int> &num){
		for(auto i : num){
			cout << i << endl;
		}
	}
	
};

int main()
{
	int size;
	vector<int> nums;
	int value, deleteV;
	
	Solution s;
	cout << "enter size of the vector nums " << endl;
	
	cin >> size;
	
	cout << "enter the values of nums" << endl;
	
	for(int i = 0; i < size; i++)
	{
		cin >> value;
		nums.push_back(value);
	}
	
	cout << "the vector you enter" << endl;
	s.printResult(nums);
	
	cout << "enter the value you need to delete" << endl;
	cin >> deleteV;
	
	int deleteSize = s.removeElement(nums, deleteV);
	
	cout <<"after delete " << deleteSize << endl;
	
	s.printResult(nums);
	
	
	
	return 0;
}
