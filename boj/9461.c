#include <stdio.h>
long long dp[101];
int main(){
    int a,b;
    scanf("%d",&a);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 3;
    dp[6] = 4;
    dp[7] = 5;
    dp[8] = 7;
    dp[9] = 9;
    for(int i=10;i<100;i++)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }
    for(int j=0;j<a;j++){
        scanf("%d",&b);
        printf("%lld\n",dp[b-1]);
    }
    return 0;
}