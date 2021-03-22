#include <iostream>
#include <vector>
using namespace std;
int main(){
    int dp[1001][1001];
    int n,k;
    cin >> n >> k;
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 2;
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = (dp[i-1][j-1] % 10007) + (dp[i-1][j] % 10007);
        }
    }
    cout << dp[n][k] % 10007;
    return 0;
}