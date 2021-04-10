#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> dp;
    int x = 0;
    int mnum = 30001;
    cin >> x;
    dp.push_back(0); // 1일때 - dp[0]
    dp.push_back(1); // 2일때 dp[1]
    dp.push_back(1); // 3 dp[2]
    dp.push_back(2); // 4 dp[3]
    dp.push_back(2); // 5 dp[4]
    for(int i=5;i<x+1;i++){
        
        dp[i] = dp[i-1]+1;
        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
        if(i % 5 == 0){
            dp[i] = min(dp[i], dp[i/5]+1);
        } 
        printf("dp[%d] : %d , \n", i, dp[i]);
    }
    //5일때 4번째. 26일때 25번째..해야되니까
    printf("%d",dp[x-1]);
    return 0;
}