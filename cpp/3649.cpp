#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum = 0;
    bool finish=false;
    int num = 0;
    int val = 0;
    int l = 0;
    vector<int> v;
    int len = 0;
    cin >> len >> num;
    len*=10000000;
    v.clear();
    for(int i=0;i<num;i++){
        cin>> val;
        v.push_back(val);   
    }
    sort(v.begin(),v.end());
    int r = v.size()-1;
    while(l<r){
        sum = v[l]+v[r];
        if(sum==len){
            finish = true;
            cout << "yes "<< v[l] << " " << v[r] << '\n';
            break;
        }
        else if(sum < len)  l++;
        else r--;
    }
    if(!finish){
        cout << "danger\n";
    }
    return 0;
}