#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row_zero;
        vector<int> col_zero;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    row_zero.push_back(i);
                    col_zero.push_back(j);
                }
            }
        }
        print_1_Vector(row_zero);
        cout << "" << endl;
        print_1_Vector(col_zero);
        
        set<int>s(row_zero.begin(), row_zero.end());
        row_zero.assign(s.begin(), s.end());
        
        set<int>t(col_zero.begin(), col_zero.end());
        col_zero.assign(t.begin(), t.end());
        
        for(auto it = row_zero.begin(); it != row_zero.end(); ++it)
        {
            for(int j = 0; j < n; ++j){
                setMatrix_row_column((*it), j, matrix);
            }
        }
        
        for(auto it = col_zero.begin(); it != col_zero.end(); ++it)
        {
            for(int i = 0; i < m; ++i){
                setMatrix_row_column(i, (*it), matrix);
            }
        }
        
    }
    
    void setMatrix_row_column(int row, int column, vector<vector<int>>& matrix)
    {
        matrix[row][column] = 0;
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
	
	void print_1_Vector(vector<int> & arr)
	{
	    for(auto i : arr){
	        cout << i << " ";
	    }
	}
};

//版本2--减少了一点空间占用
//直接用set来做，避免了转换；用assign更方便；
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row_zero;
        unordered_set<int> col_zero;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    row_zero.insert(i);
                    col_zero.insert(j);
                }
            }
        }
        
        for(auto row_index:row_zero)
        {
            matrix[row_index].assign(n, 0);
        }
        
        for(auto col_index:col_zero)
        {
            for(int i = 0; i < m; ++i){
                setMatrix_row_column(i, col_index, matrix);
            }
        }
        
    }
    
    void setMatrix_row_column(int row, int column, vector<vector<int>>& matrix)
    {
        matrix[row][column] = 0;
    }
};

int main() {
    vector<vector<int>> arr = {{0,1,2,0},{3,4,2,5}};
	Solution s;
	s.printVector(arr);
	s.setZeroes(arr);
	cout << "after" << endl;
	s.printVector(arr);
    return 0;
}