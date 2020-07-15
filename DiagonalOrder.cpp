#include <iostream>
#include <vector>
using namespace std;

//这个方法超时了，用JAVA的一次for循环改一下试试；
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if(matrix.empty()){
			return {}; 
		}
		
		const int N = matrix.size();
		const int M = matrix[0].size();
		
		vector<int> res;
		//M*N总共要遍历M+N-1次；
		for(int s = 0; s < M + N - 1; ++s)
		{
			//第n趟遍历有n个数要读取
			for(int x = 0; x <= s; ++x)
			{
				int i = x;
				int j = s - i;
				if(s % 2 == 0){
					swap(i, j);
				}
				
				if(i >= N || j >= M){
					continue;
				}
				res.push_back(matrix[i][j]);
			}
		}
		return res;
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
	vector<vector<int>> s1 = {{1,2,3},
							  {4,5,6}, 
							  {7,8,9},};
	vector<int>res = s.findDiagonalOrder(s1);
	s.printVector(res);
    return 0;
}
