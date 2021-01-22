#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    long long int a,b;
    long long int c = 0;
    cin >> n;
    a = 0;
    b = 1;
    if(n == 0){
        cout << a;
    } else if(n == 1){
        cout << b;
    } else {
        for(int i=1;i<n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        cout << c;
    }
    

    return 0;
}