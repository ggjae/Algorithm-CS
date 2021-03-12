#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second > b.second;
    } return a.first < b.first;
}
int main(){
    vector<pair<int,int> > a;
    a.push_back({1,2});
    a.push_back({1,4});
    a.push_back({1,5});
    a.push_back({3,5});
    a.push_back({2,4});
    sort(a.begin(),a.end());
    for(int i=0;i<5;i++){
        printf("f : %d s : %d\n",a[i].first, a[i].second);
    }
    printf("--------------------------------------");
    sort(a.begin(),a.end(),compare);
    for(int i=0;i<5;i++){
        printf("f : %d s : %d\n",a[i].first, a[i].second);
    }
    return 0;
}