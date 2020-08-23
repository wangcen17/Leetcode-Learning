//A Class ArrayFunction having following function
// 
//1.rotate the array - leetcode189
//  rotate the arry to right by k step
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define NoExtraSpace 0
typedef int FLAG;

class ArrayFunction{
public:
	ArrayFunction() = default;
	ArrayFunction(vector<int> &inputVector):
		m_input(inputVector){ }
		
	//rotate the arry to right by k step		
	void rotateArray(vector<int> &nums,int steps);
	void rotateArray(vector<int> &nums,int steps, int kind);
	
	//delete target value in the given array
	int deleteTargetVar(vector<int> &nums, int target);
	
	int deleteTargetVar(vector<int> &nums, int target, FLAG ways);
	
	
	void printArray(int kind);
	
	void printArray(vector<int> nums)
	{
		for(auto i : nums)
		{
			cout << i << endl;
		}
	}
protected:
	vector<int> m_result;
private:	
	vector<int> m_input;
};

void ArrayFunction::printArray(int kind){
	switch(kind){
		case 0:
			for(auto i:m_input){
				cout << i << endl;
			}
			break;
		case 1:
			for(auto i:m_result){
				cout << i << endl;
			}	
			break;
		default:
			break;
	}
}

void ArrayFunction::rotateArray(vector<int> &nums, int steps)
{
	int size = nums.size();
	steps %= size;
	vector<int> result(size, 0);
	for(int i = 0; i < size; i++)
	{
		result[(i+steps)%size] = nums[i];
	}
	nums.assign(result.begin(), result.end());
}

void ArrayFunction::rotateArray(vector<int> &nums, int steps, int kind)
{
	steps %= nums.size();
	if(NoExtraSpace != kind)
	{
		return;
	}
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + steps);
	reverse(nums.begin() + steps, nums.end());
}

//-----------
#define AfterChange 0
int ArrayFunction::deleteTargetVar(vector<int> &nums, int val)
{
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

int ArrayFunction::deleteTargetVar(vector<int> &nums, int val, FLAG ways)
{
	if(ways !=AfterChange)
	{
		return 0;
	}
	
	int position = 0;
	
	for(int i = 0; i <= nums.size(); i++)
	{
		if(val != nums[i])
		{
			nums[position++] = nums[i];
		}
	}
	
	for(int i = position-1; i < nums.size(); i++)
	{
		nums[i] = 0;
	}
	return position;
}
	
int main()
{
	vector<int> nums = {1,0,0,3,4,5,6,7};
	ArrayFunction pArray(nums);
	//pArray.printArray(0);
	//pArray.rotateArray(nums, 3, NoExtraSpace);
	int len = pArray.deleteTargetVar(nums, 0, AfterChange);
	pArray.printArray(nums);
	cout << "len = " << len << endl;
	
	return 0;
}