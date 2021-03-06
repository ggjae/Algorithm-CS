#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int cnt = 0;
    vector<int> person;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        person.push_back(tmp1);
    }
    sort(person.begin(),person.end());
    int incnt = 0;
    for(int i=0;i<n;i++){
        incnt++;
        if(incnt >= person[i]){
            cnt++;
            incnt = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}