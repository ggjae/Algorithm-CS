#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> hbg;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        hbg.push_back(a);
    }
    sort(hbg.begin(),hbg.end());
    return 0;
}