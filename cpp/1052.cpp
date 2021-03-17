#include <iostream>
#include <vector>
using namespace std;
int n,k;
int buycnt = 0;
int BitCnt3(int v){
   int cnt = 0;
   while (v){
       v = v&(v - 1);
       cnt++;
   }
   return cnt;
}
int main(){
    cin >> n >> k;

    while(1){
        int a = BitCnt3(n);
        if(a <= k) break;
        else {
            n++;
            buycnt++;
        }
    }

    printf("%d",buycnt);
    // N개로 K개를 넘지 않는 비어있지 않은 물병을 만드는 것
    // 2병때 한뱡, 4병때 한병, 8병때 한병, 16병때 한병...
    // 2병때 10, 3병때 11, 4병때 100, 5병때 101, 6병때 110, 
    // 1001 1000 1001 0110 1000 0000 = 10^7
    // 총 24자리를 사용하네

    
    return 0;
}