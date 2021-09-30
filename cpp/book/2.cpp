#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,m,k;
    vector<int> v;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(),greater<>()); // 6 5 4 4 2
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    int m1 = v[0];
    int m2 = v[1];
    int sum = 0;
    for(int i=0,j=0;i<m;i++){
        if(j++ >= k){
            sum += m2;
            j = 0;
            continue;
        }
        sum += m1;
    }
    cout << sum;
    return 0;
}