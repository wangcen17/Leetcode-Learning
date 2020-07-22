//涉及动态规划的最长公共子序列（LCS）-- leetCode-1143
//注意子序列和子串的区别：子串是连续的
//参考link：
//https://blog.csdn.net/hrn1216/article/details/51534607?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class LCS{
public:	
	int longestCommonSubsequence(string &a, string &b) {
	  vector<vector<short>> m(a.size() + 1, vector<short>(b.size() + 1));
	  for (auto i = 1; i <= a.size(); ++i){
		  for (auto j = 1; j <= b.size(); ++j){
			if (a[i - 1] == b[j - 1]) {//the most important is here
				m[i][j] = m[i - 1][j - 1] + 1;
			}
			else {
				m[i][j] = max(m[i - 1][j], m[i][j - 1]);
			}
		  }
	  }
	  return m[a.size()][b.size()];
	}
	
	int LCSubstring(string &a, string &b){
	  vector<vector<short>> m(a.size() + 1, vector<short>(b.size() + 1));
	  int result = 0;
	  for (auto i = 1; i <= a.size(); ++i){
		  for (auto j = 1; j <= b.size(); ++j){
			if (a[i - 1] == b[j - 1]) {//the most important is here
				m[i][j] = m[i - 1][j - 1] + 1;
				result = result > m[i][j] ? result : m[i][j];
			}
			else {
				m[i][j] = 0;
			}
		  }
	  }
	  return result;		
	}
};

int main()
{
	LCS S;
	string a = "acecde", b = "ace";
	int ans = 0;
	ans = S.LCSubstring(a,b);
	cout << "ans = " << ans;
	return 0;
}