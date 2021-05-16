#include <iostream>
#include <vector>
using namespace std;
int main(){
    int dp[1001];
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] % 10007 + dp[i-2] % 10007;
    }
    printf("%d",dp[n] % 10007);
    return 0;
}