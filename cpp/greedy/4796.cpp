#include <iostream>
#include <vector>
using namespace std;
int main(){
    int L,P,V = 1;
    int cnt = 1;
    while(true){
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0){
            break;
        } else {
            int day = L*(V/P);
            if(V - P*(V/P) >= L){
                day += L;
            } else {
                day += V-P*(V/P);
            }
            printf("Case %d: %d\n", cnt++, day);
        }
    }
    return 0;
}