#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(8);
    int max = *max_element(a.begin(),a.end());
    cout << max << endl;
    vector<int> arr = { 1,2,3,4,5,6 };
	cout << "upper_bound(3) : " << upper_bound(arr.begin(), arr.end(), 3) - arr.begin();
    
    // cout << max(a) << endl;
    return 0;
}