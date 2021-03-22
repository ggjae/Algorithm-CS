#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    vector<pair<int, int> > item;
    int dp[100001];
    fill_n(dp,100001,0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        item.push_back({tmp1,tmp2});
    }

    for(int i=0;i<n;i++){
        for(int j=k;j>=1;j--){
            if(item[i].first <= j){
                dp[j] = max(dp[j], dp[j-item[i].first] + item[i].second);
            }
        }
    }
    cout << dp[k];
    return 0;
}