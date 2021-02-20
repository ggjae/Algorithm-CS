#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<char> dq;
    for(int i=0;i<s.length();i++){
        while(k && !dq.empty() && dq.back() < s[i]){
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    for(int i=0;i<dq.size()-k;i++){
        cout << dq[i];
    }
    return 0;
}