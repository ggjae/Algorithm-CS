#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(){
    int n;
    int ans = 0;
    string str;
    cin >> n;
    map<string, int> m;
    while(n--){
        cin >> str;
        m[str]++;
    }
    for(auto i = m.begin();i!=m.end();i++){
        ans = max(ans, i->second);
    }
    for(auto i = m.begin();i!=m.end();i++){
        if(ans == i->second){
            cout << i->first;
            break;
        }
    }
    return 0;
}