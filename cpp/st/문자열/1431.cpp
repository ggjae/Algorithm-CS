#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
    int asum = 0;
    int bsum = 0;
    if(a.length() < b.length()){
        return true;
    } else if (a.length() == b.length()){
        for(const auto &ca : a){
            if(ca >= '0' && ca <= '9'){
                asum += ca - '0';
            }
        }
        for(const auto &cb : b){
            if(cb >= '0' && cb <= '9'){
                bsum += cb - '0';
            }
        }

        if(asum != bsum){
            return asum < bsum;
        } else {
            return a < b;
        }
    }
    return false;
}
int main(){
    int n = 0;
    vector<string> v;
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compare);
    for(const auto &a : v){
        cout << a << endl;
    }
    return 0;
}