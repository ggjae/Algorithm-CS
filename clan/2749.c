#include <stdio.h>
int a[1500000]; // 15 * 10 ^ 6-1
int main(){
    
    long long int n;
    scanf("%lld",&n);
    a[0] = 0;
    a[1] = 1;
    long long int acc = 1;
    long long int prev = 0;
    long long int k = n;
    for(int i=2;i<1500000;i++){
        a[i] = a[i-1] + a[i-2];
        a[i] = a[i] % 1000000;
    }
    if(n>1500000){
        printf("%d",a[n%1500000]);
    } else {
        printf("%d",a[n]);
    }
    return 0;
}