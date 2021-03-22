#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    int n;
    vector<string> a;
    for(int i=0;i<n;i++){
        string tmp1;
        cin >> tmp1;
        a.push_back(tmp1);
    }
    for(int i=0;i<s.size();i++){
        int flag = 0;
        int idx = i;
        for(int j=0;j<a.size();j++){
    
            for(int k=0;k<a[j].size();k++){
                if(s[i++] == a[j][k]){
                    if(i == s.size()){
                        printf("1");
                        return 0;
                    }
                    flag = 1;
                }
                else flag = 0;
            }
            if(flag == 0){
                i = idx;
                continue;
            }
        }
    }
    printf("0");
    return 0;
}