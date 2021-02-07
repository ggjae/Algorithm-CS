#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main(){
    string s,tmp;
    string tr;
    s.clear();
    tmp.clear();
    tr.clear();
    vector<int> v;
    cin >> s;
    int flag = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] != '-' && s[i] != '+'){
            tmp += s[i];
            if(i == s.size() - 1){
                v.push_back(stoi(tmp));
            }

        } else{
        //     printf("stoi : %d\n",stoi(tmp));
            v.push_back(stoi(tmp));
            tr += s[i];
            tmp.clear();
        }
    }
    int sum = v[0];
    int idx = 0;
    // for(int i=0;i<v.size();i++){
    //     printf("%d번째 값 : %d, 내 부호 %c\n",i,v[i],tr[i]);
    // }
    // printf("%d sum이 이거 맞아?",sum);
    for(int i=1;i<v.size();i++,idx++){
        // printf("%d\n",sum);
        if(flag == 1){
            sum -= v[i];
        } else if(tr[idx]== '-'){
            if(flag == 0) flag = 1;
            sum -= v[i];
        } else if(flag == 0){
            sum += v[i];
        }
    }
    cout << sum << endl;
    return 0;
}