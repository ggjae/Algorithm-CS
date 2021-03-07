#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> cnt;
    int flag = 0;
    int len = s.length();
    for(int i=1;i<=s.length()/2;i++){
        int nowcnt = 1;
        string temp = s.substr(0,i);
        string convert;
        for(int j=i;j<s.length();j+=i){
            if(temp == s.substr(j,i)) nowcnt++;
            else{
                if(nowcnt>1) convert += to_string(nowcnt);
                convert += temp;
                temp = s.substr(j,i);
                nowcnt = 1;
            }
        }
        if(nowcnt>1) convert += to_string(nowcnt);
        convert += temp;
        int tmplen = convert.length();
        len = min(len, tmplen);
    }
    printf("%d",len);
    return 0;
}