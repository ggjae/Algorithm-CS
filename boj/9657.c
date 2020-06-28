#include <stdio.h>
int main(){
    int n;
    int dp[1001] = {0};
    scanf("%d",&n);
    dp[1] = dp[3] = dp[4] = 1;
    for(int i=5;i<=n;i++){
        if(!(dp[i-1] && dp[i-3] && dp[i-4])){
            dp[i] = 1;
        }
    }
    if(dp[n] == 1){
        printf("SK");
    } else {
        printf("CY");
    }
    return 0;
}