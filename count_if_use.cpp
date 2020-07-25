#include <vector>
#include <algorithm>
#include <iostream>
bool greater10(int value)
{
    return value >10;
}
int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(10);
    cout << "v1 = ( ";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
       cout << *Iter << " ";
    cout << ")" << endl;
    vector<int>::iterator::difference_type result1;
	auto f = [](int i){
		return i > 10;
	};
    result1 = count_if(v1.begin(), v1.end(), f);
    cout << "The number of elements in v1 greater than 10 is: "
         << result1 << "." << endl;
}