#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<int> r;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        r.push_back(a);
    }
    sort(r.begin(),r.end());
    int sum = 0;
    int max = 0;
    for(int i=0;i<n;i++){
        sum = r[i] * (n-i);
        if(sum > max){
            max = sum;
        }
    }
    cout << max;
    return 0;
}