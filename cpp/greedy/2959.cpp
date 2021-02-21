#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    for(int i=0;i<4;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    cout << a[0] * a[2];
    return 0;
}