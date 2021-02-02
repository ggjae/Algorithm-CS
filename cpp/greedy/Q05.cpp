#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> w;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        w.push_back(tmp);
    }
    sort(w.begin(),w.end());
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(w[i] != w[j]) count++;
        }
    }
    cout << count;
    return 0;
}