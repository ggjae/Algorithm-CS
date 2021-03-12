#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,l;
    vector<int> leak;
    bool check[1001];
    cin >> n >> l;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        leak.push_back(tmp1);
    }
    int cnt = 0;
    sort(leak.begin(),leak.end());
    fill_n(check,1001,false);
    for(int i=0;i<n;i++){
        if(check[leak[i]] == false){
            for(int j=leak[i];j<leak[i]+l;j++){
                if(j > 1000) break;
                check[j] = true;
            }
            cnt++;
        }    
    }
    cout << cnt;
    return 0;
}