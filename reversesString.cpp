#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
		printVector(s);
		cout<< "len is" << len << endl;
		int left = 0, right = len - 1;
		while(left < right)
		{
			swap(s[left++], s[right--]);
		}
		cout << "after" << endl;
		printVector(s);
    }
	void printVector(vector<char> s){
		for(auto i : s)
		{
			cout << i << " ";
		}
		cout << "" << endl;
	}
	void printVector(vector<string> s){
		for(auto i : s)
		{
			cout << i << " "; 
		}
		cout << "" << endl;
	}
};


int main() {
	Solution s;
	vector<char> s1 = {'h', 'e', 'l', 'l', 'o',};
	s.reverseString(s1);
	//s.printVector(s1);
    cout << "Hello W3Cschool!";
    return 0;
}