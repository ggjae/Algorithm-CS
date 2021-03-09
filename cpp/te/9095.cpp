#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n,t;
    cin >> t;
    
    for(int j=0;j<t;j++){
        cin >> n;
        
        int dp[11]={0};
        dp[1]=1, dp[2]=2, dp[3]=4;
        
        for(int i=4;i<=n;i++)
            dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
        
        cout << dp[n] << endl;
    }
    return 0;
}
