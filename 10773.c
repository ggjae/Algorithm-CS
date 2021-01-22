#include <stdio.h>

int main(void){

    int n=0, size=0, value=0,top=-1;
    int ord;
    long long sum = 0;
    int stack[100001]; // stack 선언

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&ord);
        if(ord == 0){
            top--;
        } else {
            stack[++top] = ord;
        }
    }
    for(int i=0;i<=top;i++){
        sum += stack[i];
    }
    printf("%lld",sum);
    return 0;
}