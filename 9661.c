#include <stdio.h>
int main(){ // 나중에 해봐!
    long long n;
    scanf("%lld",&n);
    if(n%5==0 || n%5==2){
        printf("CY");
    } else{
        printf("SK");
    }
    return 0;
}