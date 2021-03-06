#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int result = s[0] - '0';
    for(int i=1;i<s.size();i++){
        if(s[i] == '0' || result == 0 || s[i] == '1' || result == 1){
            result += s[i] - '0';
        } else {
            result *= s[i] - '0';
        }
    }
    cout << result << endl;
    return 0;
}