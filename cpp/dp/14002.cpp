#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define IINF -1000000001

vector<int> a;
vector<int> dp;
void backtrace(int idx, int last){
    if(idx < 0) return;
    if(dp[idx] == last){
        backtrace(idx-1, last-1);
        printf("%d ", a[idx]);
    } else{
        backtrace(idx-1, last);
    }
}
int main(){
    int n;
    // vector<int> res;
    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        dp.push_back(1);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                
            }
        }
        // if(res.back() < a[i]){
        //     res.push_back(a[i]);
        //     ans++;
        // } else {
        //     int tmp = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
        //     res[tmp] = a[i];
        // }
    }
    int cnt = 1;

    cout << *max_element(dp.begin(),dp.end()) << endl;
    backtrace(n-1, *max_element(dp.begin(), dp.end()));
    return 0;
}