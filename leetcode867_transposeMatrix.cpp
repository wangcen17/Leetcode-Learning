//leetcode 867:transposed matrix
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	//V0:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> result;
		//tips:init vector -> vector<vector<int>> result(cloum, vector(row, 0));
		
		int row = A.size(), cloum = A[0].size();
		//cout << "row = " << row << "cloum = " << cloum<< endl;
		
		for(int cI = 0; cI < cloum; cI++)
		{
			vector<int> R;
			for(int rI = 0; rI < row; rI++)
			{
				//cout << "push " << A[rI][cI]<< endl;
				R.push_back(A[rI][cI]);	
			}
			result.push_back(R);
		}
		//printVector(result);
		return result;
    }
	
	//V1 : try to be more concise
	vector<vector<int>> transposeV1(vector<vector<int>>& A) {
		
		int row = A.size(), col = A[0].size();
		vector<vector<int>> result(col);
		
		for(int cI = 0; cI < col; cI++)
		{
			for(int rI = 0; rI < row; rI++)
			{
				//emplace_back can help to improve efficient；
				result[cI].emplace_back(A[rI][cI]);
			}
		}
		
		return result;
	}
	
	void printVector(vector<vector<int>>& intervals)
	{
		for(auto it = intervals.begin(); it != intervals.end(); ++it)
		{
			for(unsigned int i = 0; i < (*it).size(); ++i)
			{
				cout << (*it)[i] << " "; 
			}
			cout <<""<< endl;
		}
	}
};

int main()
{
	vector<vector<int>> A = {{1,2,3},
							 {4,5,6},
						     {7,8,9}};
	vector<vector<int>> B;
	Solution S;
	S.printVector(A);
	B = S.transposeV1(A);
	S.printVector(B);
	return 0;
}