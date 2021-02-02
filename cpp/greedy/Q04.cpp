#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> danwi;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        danwi.push_back(a);
    }
    sort(danwi.begin(),danwi.end());
    int result = 1;
    for(int i=0;i<n;i++){
        if(result < danwi[i]) break;
        result += danwi[i];
    }
    cout << result;
    return 0;
}