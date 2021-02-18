#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define IINF -1000000001
int main(){
    int n;
    vector<int> a;
    // vector<int> dp;
    vector<int> res;
    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        // dp.push_back(1);
    }
    
    res.push_back(IINF);
    for(int i=0;i<n;i++){
        // for(int j=0;j<i;j++){
        //     if(a[j] < a[i]){
        //         dp[i] = max(dp[i], dp[j] + 1);
        //     }
        // }
        if(res.back() < a[i]){
            res.push_back(a[i]);
            ans++;
        } else {
            int tmp = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
            res[tmp] = a[i];
        }
    }
    cout << ans;
    return 0;
}