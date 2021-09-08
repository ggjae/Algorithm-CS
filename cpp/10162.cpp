#include <iostream>
using namespace std;
int main(){
    int t;
    int a = 300, b = 60, c = 10;
    int ta = 0, tb = 0, tc = 0;
    cin >> t;
    if(t >= a){
        ta = t/a;
        t %= a;
    } if (t >= b){
        tb = t/b;
        t %= b;
    } if (t >= c){
        tc = t/c;
        t %= c;
    }
    if(t != 0){
        cout << -1;
        return 0;
    } else {
        cout << ta << " " << tb << " " << tc;
        return 0;
    }
}