#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    int m,x;
    cin >> m >> x;
    for(int i=0;i<m;i++){
        int n;
        cin >> n;
        a.push_back(n);
    }
    
    int max = (upper_bound(a.begin(), a.end(), x) - a.begin()) - (lower_bound(a.begin(), a.end(), x) - a.begin());
    if(max == 0) cout << "-1";
    else cout << max;

    return 0;
}