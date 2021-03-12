#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<pair<int, int> > a;
    a.push_back({1,2});
    a.push_back({1,3});
    a.push_back({3,4});
    a.push_back({2,2});
    sort(a.begin(),a.end());
    for(int i=0;i<4;i++){
        printf("f : %d s : %d\n",a[i].first,a[i].second);
    }
    return 0;
}