#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int a;
        int cnt[4] = {0, };
        cin >> a;
        if(a >= 25){
            cnt[0] = a/25;
            a = a%25;
        } if(a >= 10){
            cnt[1] = a/10;
            a = a%10;
        } if(a >= 5){
            cnt[2] = a/5;
            a = a%5;
        } if(a >= 1){
            cnt[3] = a/1;
            a = a%1;
        }
        for(int i=0;i<4;i++){
            cout << cnt[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}