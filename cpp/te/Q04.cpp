#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> kind;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        kind.push_back(tmp1);
    }
    sort(kind.begin(),kind.end());
    int result = 1;
    for(int i=0;i<n;i++){
        if(result < kind[i]) break;
        result += kind[i];
    }
    cout << result;
    return 0;
}