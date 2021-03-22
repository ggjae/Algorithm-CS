#include <iostream>
#include <vector>
using namespace std;
int main(){
    int dp[1000][1000];
    int n,k;
    cin >> n >> k;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[2][0] = 1;
    dp[2][2] = 1;
    for(int i=3;i<=n;i++){
        for(int j=2;j<=i;j++){
            if(j == i) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j-1] % 10007) + (dp[i-1][j] % 10007);
            }
        }
    }
    cout << dp[n][k] % 10007;
    return 0;
}