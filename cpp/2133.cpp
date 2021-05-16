#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[31];
    dp[0] = 1;
    dp[2] = 3;
    if(n%2 == 1) {
        printf("0");
        return 0;
    }
    else {
        for(int i=4;i<=n;i+=2){
            dp[i] = 3 * dp[i-2];
            for(int j=i-4;j>=0;j-=2){
                dp[i] += 2 * dp[j];
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}