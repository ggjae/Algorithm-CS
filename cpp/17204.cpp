#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    int part[151];
    int ans = 0;
    int c = 0;
    int check = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> part[i]; // 1,3,2,1,4
    }
    for(int i=0;i<n;i++){
        ans = part[ans];
        c++;
        if(ans == k){
            cout << c;
            check++;
            break;
        }
    }

    if(check == 0){
        cout << -1;
    }
    return 0;
}