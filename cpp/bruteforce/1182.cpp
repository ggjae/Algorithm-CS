#include <iostream>
#include <vector>
using namespace std;
int n,s;
int cnt = 0;
vector<int> v;
void dfs(int i, int sum){
    if(i == n) return;
    if(sum + v[i] == s) cnt++;

    dfs(i+1,sum);
    dfs(i+1, sum+v[i]);
}
int main(){
    
    int su = 0;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        v.push_back(tmp1);
    }
    dfs(0,0);
    
    cout << cnt;
    return 0;
}