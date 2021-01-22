#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int number;
int queen[16];
int count = 0;
void check(int x){
    for(int i=0;i<x;i++){
        if(queen[i] == queen[x] || (abs(queen[i] - queen[x]) == abs(i-x))){
            return ;
        }
    } // 두 조건 중 하나만 성공 못해도, 이거 안되니까 check 끝. 
    if(x == number-1){
        count++;
        return ;
    } // 다 끝났을 때.
    for(int i=0;i<number;i++){
        queen[x+1] = i;
        check(x+1);
    } // queen[1] 에 0 넣어보고, queen[2] 에 0 넣어보고. 값을 전부 생각하는건데, 앞에서
    // pruning을 통해서 가지치기를 하고 나서 확인하는거잖아? 그래서 오래걸리지 않음.
}
int main() {
    scanf("%d",&number);
    for(int i=0;i<number;i++){ // 0번째부터 자리를 잡아주고 시작하겠다는 생각
        queen[0] = i; // 0,0 0,1 0,2 0,3 0,4 0,5 돌려야지. 케이스 몇개나오는지
        check(0); // 0부터 체크해줘.
    }
    printf("%d",count);
    return 0;
}