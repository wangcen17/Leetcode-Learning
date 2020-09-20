//leetcode 977
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
		
		for(int i=0; i < A.size(); i++)
		{
			if(A[i] < 0){
				A[i] = abs(A[i]);
			}
		}
		printArray(A);
		sort(A.begin(), A.end());
		
		for(int j=0; j < A.size(); ++j)
		{
			A[j] = A[j]*A[j];
		}
		printArray(A);
    }
	
	//change the stupid process;
	vector<int> sortedSquaresV1(vector<int>& A) {
			
		for(int j=0; j < A.size(); ++j)
		{
			A[j] = A[j]*A[j];
		}
		sort(A.begin(), A.end());
		printArray(A);
		return A;
    }
	
	//双指针法
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result(A.size(), 0);
		int left = 0, right = A.size() - 1;
		int p = right;
		
		//注意这里的<=，只取一边，否则有溢出的风险；
		while(A[left] <= 0 && A[right] > 0){
			if(abs(A[left]) <= A[right]){
				result[p--] = A[right]*A[right--];
			}
			else{
				result[p--] = A[left]*A[left++];
			}
		}
		
		while(left <= right && A[left] <= 0){
			result[p--] = A[left]*A[left++];
		}
		while(left <= right && A[right] > 0){
			result[p--] = A[right]*A[right--];
		}
		return result;
    }
	
	//more clearly
	void<int> sor1edSquaresV3(vector<int>& A){
		vector<int> res(A.size());
		int l = 0, r = A.size() - 1;
		
		for(int k = A.size() - 1; k >=0; k--){
			if(abs(A[l]) < abs(A[r])){
				res[k] = A[r]*A[r--];
			}
			else{
				res[k] = A[l]*A[l++];
			}
		}
		return res;
	}	
	
	void printArray(vector<int> nums)
	{
		for(auto i : nums)
		{
			cout << i << endl;
		}
	}
};

int main()
{
	vector<int> input = {-4,-1,0,3,10};
	Solution S;
	S.sortedSquares(input);
	return 0;
}