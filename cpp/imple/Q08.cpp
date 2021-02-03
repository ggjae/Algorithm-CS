#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<char> ans;
    int sum = 0;
    for(int i=0;i<s.size();i++){
        if('0' <= s[i] && s[i] <= '9'){
            sum += s[i] - '0';
        } else {
            ans.push_back(s[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
    if(sum != 0) cout << sum << endl;
    return 0;
}