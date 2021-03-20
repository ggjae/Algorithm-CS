#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int answer = 0;
    for(int i=1;i<=n;i++){
        int t = i;
        int v = i;
        while(t > 0){
            v += t%10;
            t = t/10;            
        }
        if(v == n){
            answer = i;
            break;
        }
    }
    cout << answer;
    
    return 0;
}