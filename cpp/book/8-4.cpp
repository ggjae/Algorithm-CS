#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    vector<int> value;
    int num[10001];
    fill_n(num, 10001, 10001);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int money;
        cin >> money;
        value.push_back(money);
    }
    num[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=value[i];j<=m;j++){
            if(num[j - value[i]] != 10001) num[j] = min(num[j], num[j-value[i]]+1);
        }
    }
    if(num[m] != 10001) cout << num[m];
    else cout << -1;
    return 0;
}