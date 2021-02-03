#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int answer = s.size();
    int len = s.size()/2 + 1;
    char tmp = s[0];
    for(int i=1;i<len;i++){
        string compressed = "";
        string prev = s.substr(0,i);
        int cnt = 1;
        for(int j=i;j<s.size();j+=i){
            if(prev == s.substr(j, i)) cnt += 1;
            else { //끝난경우
                compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
                prev = s.substr(j,i);
                cnt = 1;
            }
        }
        compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
        answer = min(answer, (int)compressed.size());
    }
    cout << answer << endl;
    return 0;
}