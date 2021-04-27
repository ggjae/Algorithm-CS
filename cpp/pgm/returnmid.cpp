#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int i =0;
    if(s.size() % 2 == 1){
        i = s.size()/2;
        answer = s[i];
    } else {
        i = s.size()/2 - 1;
        answer = s.substr(i,2);
    }
    return answer;
}
int main(){
    cout << solution("abcde") << endl;
    return 0;
}