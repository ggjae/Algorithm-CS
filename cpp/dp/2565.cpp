#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<pair<int, int> > a;
    vector<int> dp;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        a.push_back(make_pair(tmp1,tmp2));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        dp.push_back(1);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j].second < a[i].second){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",dp[i]);
    // }
    int max = *max_element(dp.begin(),dp.end());
    cout << n - max;
    return 0;
}