#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;

    int seq[100001];
    int dp[100001]; 

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> seq[i];
    }

    dp[0] = seq[0];

    for(int i=1;i<n;i++){
        dp[i] = max(seq[i]+dp[i-1], seq[i]);
    }
    int result = -1002;
    for(int i=0;i<n;i++){
        result = max(result,dp[i]);
    }
    cout << result << endl;
    return 0;
}