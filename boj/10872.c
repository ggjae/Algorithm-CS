#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fac(int k){
    int b = k;
    while(k>1){
        k = k-1;
        b = b * k;
    }
    return b;
    
}
int main() {
    int a;
    scanf("%d",&a);
    if(a == 0){
        printf("1");
        return 0;
    }
    printf("%d",fac(a));
    return 0;
}