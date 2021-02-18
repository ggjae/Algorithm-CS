#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a;
    vector<int> dp;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        dp.push_back(1);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] > a[i]){
                int maxc = max(dp[j]+1, dp[i]);
                dp[i] = maxc;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[i] << ' ';
    }
    cout << *max_element(dp.begin(),dp.end());
    return 0;
}