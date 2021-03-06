#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    int flag = 0;
    for(int i = 1; i<s.size();i++){
        if(s[i] != s[i-1]){
            if(flag == 1){
                flag = 0;
            } else {
                flag = 1;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}