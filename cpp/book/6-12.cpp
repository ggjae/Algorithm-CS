#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;
int main(){
    int n=0,k=0;
    int tmp,result=0;
    vector<int> a;
    vector<int> b;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cin >> tmp;
        b.push_back(tmp);
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<>());
    for(int i=0;i<k;i++){
        a[i] = b[i];
    }

    for(int i=0;i<n;i++){
        cout << a[i] << ' ';
        result += a[i];
    }
    int sum = accumulate(a.begin(),a.end(),0);
    cout << result << endl;
    cout << sum << endl;
    
    return 0;
}