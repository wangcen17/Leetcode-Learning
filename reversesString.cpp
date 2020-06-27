#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i = 0; i < len/2; i++)
        {
            
        }
    }
	void printVector(vector<char> s){
		for(auto i : s)
		{
			cout << i << " "; 
		}
		cout << "" << endl;
	}
};


int main() {
	Solution s;
	vector<char> s1 = {"h", "e", "l", "l", "0"};
	s.printVector(s1);
    cout << "Hello W3Cschool!";
    return 0;
}