#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    int n,d;
    int dp[100000];
    bool check[100000];
    vector<int> ans;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        ans.push_back(tmp);
        check[i] = false;
    }
    for(int i=0;i<n;i++){
        dp[i] = ans[i];
        for(int j=1;j<=d;j++){
            if(i-j>=0 && check[i] == false){
                dp[i] = max(dp[i], ans[i]+dp[i-j]);
                if(dp[i] == ans[i]+dp[i-j]){
                    check[i] = true;
                }
            }
        }
        
    }
    sort(dp,dp+n-1,greater<>());
    cout << dp[0];
    return 0;
}