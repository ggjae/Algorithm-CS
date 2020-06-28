#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fib(int k){
    if(k == 0){
        return 0;
    }
    if(k == 1){
        return 1;
    }
    return fib(k-1) + fib(k-2);
    
}
int main() {
    int a;
    scanf("%d",&a);
    if(a == 0){
        printf("0");
    } else if (a == 1){
        printf("1");
    } 
    else {
        printf("%d",fib(a));
    }
    return 0;
}