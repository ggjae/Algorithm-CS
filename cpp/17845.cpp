#include <iostream>
using namespace std;
int main(){
    int n,k;
    int lec[1001][2] = {0};
    int dp[10001] = {0, };
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> lec[i][0] >> lec[i][1];
    }
    for(int i=0;i<1;i++){
        for(int j=n;j>1;j--){
            if(j >= lec[i][1]){
                dp[j] = max(dp[j], dp[j-lec[i][1]]+lec[i][0]);
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     printf("dp[%d] = %d\n",i,dp[i]);
    // }
    return 0;
}