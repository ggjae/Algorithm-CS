#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    vector<int> kind;
    int dp[10001];
    fill_n(dp,10001,10001);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        if(tmp1 > k) continue;
        kind.push_back(tmp1);
        dp[tmp1] = 1;
    }
    dp[0] = 0;
    sort(kind.begin(),kind.end());
    for(int i=0;i<n;i++){
        for(int j=kind[i];j<=k;j++){
            dp[j] = min(dp[j], dp[j-kind[i]] + 1);
        }
    }
    if(dp[k] == 10001) cout << -1;
    else cout << dp[k];
    return 0;
}