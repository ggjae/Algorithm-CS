#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<int> a;
    vector<int> dp;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        dp.push_back(1);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max = *max_element(dp.begin(),dp.end());
    cout << max;
    return 0;
}