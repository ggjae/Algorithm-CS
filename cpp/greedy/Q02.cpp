#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // char s[21];
    // char adds[41];
    // cin >> s;
    // int j=0;
    // for(int i=0;i<s.size();i++){
    //     adds[j++] = s[i];
    //     if(s[i] == '0' || s[i] == '1'){
    //         adds[j] = '+';
    //     } else {
    //         adds[j] = '*';
    //     }
    // }
    // int result = 0;
    // for(int i=0;i<adds.size();i++){
    //     if(adds[i] == '*'){

    //     }
    // }
    string str;
    cin >> str;
    long long result = str[0] - '0';
    for (int i = 1 ; i < str.size() ; i++){
        int num = str[i] - '0'; // 다음 값을 보는 과정
        if (num <= 1 || result <= 1){
            result += num; // 만약에 처음에 00 이였다면 아직도 0일테니. 리절트도 신경써주기
        } else {
            result *= num;
        }
    }
    return 0;
}