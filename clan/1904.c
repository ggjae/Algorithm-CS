#include <stdio.h>
long long dp[1000001];
int main(){
    int a,b;
    scanf("%d",&a);
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2;i<a;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }
    printf("%lld",dp[a-1]);
    return 0;
}